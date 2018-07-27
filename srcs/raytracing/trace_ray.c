/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/26 16:37:10 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "vect3d.h"
#include "raytracing.h"
#include "apply_light.h"
#include "intersection.h"
#include "mmath.h"

float mix(const float a, const float b, const float mix)
{
    return (b * mix + a * (1 - mix));
}

float	 max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

t_vect3d	get_refraction_ray(t_vect3d ray_dir, t_vect3d normal, int inside)
{
	float		ior;
	float		eta;
	float		cosi;
	float		k;

	ior = 1.3f;
	if (inside)
		eta = ior;
	else
		eta = 1.0f / ior;
	cosi = -vect3d_dot(normal, ray_dir);
	k = 1 - eta * eta * (1 - cosi * cosi);
	return (vect3d_mult_on_scalar(ray_dir, eta)
			+ vect3d_mult_on_scalar(normal, eta * cosi - sqrt(k)));
}

void		fresnel(t_vect3d dir, t_vect3d n, float ior, float *kr)
{
	float cosi = clampd(-1, 1, vect3d_dot(dir, n));
    float etai = 1, etat = ior;
    if (cosi > 0)
	{
		float tmp = etai;
		etai = etat;
		etat = tmp;
	}
    // Compute sini using Snell's law
    float sint = etai / etat * sqrtf(max(0.f, 1 - cosi * cosi));
    // Total internal reflection
    if (sint >= 1) {
        *kr = 1;
    }
    else {
        float cost = sqrtf(max(0.f, 1 - sint * sint));
        cosi = fabsf(cosi);
        float Rs = ((etat * cosi) - (etai * cost))
			/ ((etat * cosi) + (etai * cost));
        float Rp = ((etai * cosi) - (etat * cost))
			/ ((etai * cosi) + (etat * cost));
        *kr = (Rs * Rs + Rp * Rp) / 2;
    }
}

#define BACKGROUND_COLOR vect3d(0, 0, 0)
//#define BACKGROUND_COLOR COLOR(0x44444400)

t_vect3d	trace_ray(const t_scene *scene, t_vect3d orig, t_vect3d ray_dir,
			int depth)
{
	t_intersection	intersection;
	t_vect3d		res_color;

	if (find_closest_intersection(scene, orig, ray_dir,
		&intersection))
	{
		(void)depth;
		if (intersection.hit_object->is_glass == 1 
				&& depth < MAX_RAY_DEPTH)
		{
			//handle_reflection(scene, depth + 1);
			float kr;
			fresnel(ray_dir, intersection.normal, 1.3, &kr);
			t_vect3d	refraction_col = vect3d(0, 0, 0);

			if (kr < 1)
			{
				t_vect3d refract_ray = vect3d_norm(get_refraction_ray(ray_dir,
									intersection.normal, intersection.inside));

				refraction_col = trace_ray(scene,
					intersection.dest
					- vect3d_mult_on_scalar(intersection.normal, 0.001),
					refract_ray,	
					depth + 1);
			}

			t_vect3d	reflection_col;

			t_vect3d	reflect_ray = vect3d_norm(vect3d_reflect(ray_dir,
										intersection.normal));

			reflection_col = vect3d(0, 0, 0);
			reflection_col = trace_ray(scene, intersection.dest,
								reflect_ray,
								depth + 1);
			return (vect3d_mult_on_scalar(reflection_col, kr)
				+ vect3d_mult_on_scalar(refraction_col, (1 - kr)));

//			t_vect3d	reflection_col;
//
//			t_vect3d	reflect_ray = vect3d_norm(vect3d_reflect(ray_dir,
//										intersection.normal));
//
//			reflection_col = vect3d(0, 0, 0);
//			reflection_col = trace_ray(scene, intersection.dest,
//								reflect_ray,
//								depth + 1);
//			float facingratio = -vect3d_dot(ray_dir, intersection.normal);
//			float fresneleffect = mix(pow(1 - facingratio, 3), 1, 0.1);
//			
//			t_vect3d	refraction_col;
//
//			t_vect3d refract_ray = vect3d_norm(get_refraction_ray(ray_dir,
//									intersection.normal, intersection.inside));
//
//			refraction_col = trace_ray(scene,
//				intersection.dest
//				- vect3d_mult_on_scalar(intersection.normal, 0.001),
//				refract_ray,	
//				depth + 1);
//
//			return (vect3d_mult_on_scalar(reflection_col, fresneleffect)
//				+ vect3d_mult_on_scalar(refraction_col, (1 - fresneleffect)));
		}
		else if (intersection.hit_object->is_glass == 2
					&& depth < MAX_RAY_DEPTH)
		{
			t_vect3d	diffuse_col;
			t_vect3d	diffuse_ray;

			diffuse_ray = intersection.normal + random_in_unit_sphere();
			diffuse_col = trace_ray(scene, intersection.dest, diffuse_ray,
									depth + 1);
			return (vect3d_mult_on_scalar(diffuse_col, 0.5));
		}
		else if (intersection.hit_object->is_glass == 3
					&& depth < MAX_RAY_DEPTH)
		{
			t_vect3d	metal_col;
			t_vect3d	metal_ray;
			double		fuzz;

			fuzz = 0.5;
			metal_ray = vect3d_reflect(ray_dir, intersection.normal)
						+ vect3d_mult_on_scalar(random_in_unit_sphere(), fuzz);
			metal_col = trace_ray(scene, intersection.dest, metal_ray,
									depth + 1);
			return (vect3d_mult_on_scalar(metal_col, 1));
		}
		res_color = apply_light(scene, &intersection);
		return (res_color);
	}
	return (BACKGROUND_COLOR);
}
