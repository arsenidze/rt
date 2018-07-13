/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/12 20:36:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "vect3d.h"
#include "raytracing.h"
#include "apply_light.h"
#include "intersection.h"

float mix(const float a, const float b, const float mix)
{
    return (b * mix + a * (1 - mix));
}

t_vect3d	get_refraction_ray(t_vect3d ray_dir, t_vect3d normal, int inside)
{
	float		ior;
	float		eta;
	float		cosi;
	float		k;

	ior = 1.1f;
	if (inside)
		eta = ior;
	else
		eta = 1.0f / ior;
	cosi = -vect3d_dot(normal, ray_dir);
	k = 1 - eta * eta * (1 - cosi * cosi);
	return (vect3d_mult_on_scalar(ray_dir, eta)
			+ vect3d_mult_on_scalar(normal, eta * cosi - sqrt(k)));

//	ior = 1.1f;
//	if (inside)
//		eta = ior;
//	else
//		eta = 1.0f / ior;
//	cosi = vect3d_dot(normal, ray_dir);
//	k = 1 - eta * eta * (1 - cosi * cosi);
//	if (k < 0)
//		return (vect3d(0, 0, 0));
//	return (vect3d_mult_on_scalar(-ray_dir, eta)
//			+ vect3d_mult_on_scalar(normal, -eta * cosi - sqrt(k)));
}

#define BACKGROUND_COLOR vect3d(0, 0, 0)
//#define BACKGROUND_COLOR COLOR(0x44444400)

t_vect3d	trace_ray(t_scene *scene, t_vect3d orig, t_vect3d ray_dir,
			int depth)
{
	t_intersection	intersection;
	t_vect3d		res_color;

	if (find_closest_intersection(scene, orig, ray_dir,
		&intersection))
	{
		(void)depth;
		if (intersection.hit_object->is_glass 
				&& depth < MAX_RAY_DEPTH)
		{
			//handle_reflection(scene, depth + 1);
			t_vect3d	reflection_col;

			t_vect3d	reflect_ray = vect3d_norm(vect3d_reflect(ray_dir,
										intersection.normal));

			reflection_col = vect3d(0, 0, 0);
			reflection_col = trace_ray(scene, intersection.dest,
								reflect_ray,
								depth + 1);
			float facingratio = -vect3d_dot(ray_dir, intersection.normal);
			float fresneleffect = mix(pow(1 - facingratio, 3), 1, 0.1);
			
			t_vect3d	refraction_col;

			t_vect3d refract_ray = vect3d_norm(get_refraction_ray(ray_dir,
									intersection.normal, intersection.inside));

			refraction_col = trace_ray(scene,
			intersection.dest - vect3d_mult_on_scalar(intersection.normal, 0.001),
								refract_ray,	
								depth + 1);
//			return (refraction_col);
//			return (COLOR_ADD(COLOR_MULT(reflection_col, fresneleffect),
//					COLOR_MULT(refraction_col, (1 - fresneleffect))));
			return (vect3d_mult_on_scalar(reflection_col, fresneleffect)
				+ vect3d_mult_on_scalar(refraction_col, (1 - fresneleffect))
				* intersection.hit_object->k[K_AMBIENT]);
		}
		res_color = apply_light(scene, &intersection);
		return (res_color);
	}
	return (BACKGROUND_COLOR);
}
