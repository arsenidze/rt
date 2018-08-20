/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:52:33 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 22:28:33 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point_light.h"
#include "raytracing.h"
#include "intersection.h"
#include "vect3d.h"
#include <math.h>

double	calculate_specular_impact(t_vect3d dir_to_light,
						const t_intersection *isect)
{
	t_vect3d	bisector;
	double		spec;

	bisector = dir_to_light + -isect->ray.d;
	bisector = vect3d_norm(bisector);
	spec = vect3d_dot(bisector, isect->normal);
	if (spec > 0)
		return (pow(spec, isect->hit_object->material.shininess));
	return (0);
}

static inline double	calc_attenuation(const t_point_light *light,
						double dist, double sq_dist)
{
	double	attenuation;

	attenuation = 1.0 / (light->constant + light->linear * dist
				+ light->quadratic * sq_dist);
	return (attenuation);
}


static inline t_vect3d	calc_point_light(const t_point_light *light,
						t_vect3d dir_to_light, const t_intersection *isect)
{
	double		diff;
	double		spec;
	t_vect3d	output;

	output = light->ambient * isect->hit_object->material.ambient;
	diff = vect3d_dot(dir_to_light, isect->normal);
	if (diff > 0)
		output += light->diffuse
			* vect3d_mult_on_scalar(isect->hit_object->material.diffuse, diff);
	spec = calculate_specular_impact(dir_to_light, isect);
	if (spec > 0)
		output += light->specular
			* vect3d_mult_on_scalar(isect->hit_object->material.specular, spec);
	return (output);
}

t_vect3d				point_light_apply(const t_point_light *light,
						const t_scene *scene, const t_intersection *isect)
{
	double			sq_dist;
	double			dist;
	t_vect3d		dir_to_light;
	t_object		*shadow_reason;
	t_vect3d		attenuation;
	
	dir_to_light = light->pos - isect->dest;
	sq_dist = vect3d_sq_len(dir_to_light);
	dist = sqrt(sq_dist);
	dir_to_light = vect3d_div_on_scalar(dir_to_light, dist);
	attenuation = vect3d_from_scalar(calc_attenuation(light, dist, sq_dist));
	if ((shadow_reason = raytracing_get_obj_on_dir(isect->dest, light->pos,
		dir_to_light, scene)))
	{
		if (shadow_reason->material.transparency > 0)
		{
			return (attenuation * calc_point_light(light, dir_to_light, isect))
				* vect3d_from_scalar(shadow_reason->material.transparency);
		}
		return (attenuation * light->ambient
				* isect->hit_object->material.ambient);
	}
	return (attenuation * calc_point_light(light, dir_to_light, isect));
}
