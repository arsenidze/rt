/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:52:33 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/04 15:56:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point_light.h"
#include "light_private.h"
#include "raytracing.h"
#include "intersection.h"
#include "vect3d.h"
#include <math.h>

static inline double	calc_attenuation(const t_point_light *light,
						double dist, double sq_dist)
{
	double	attenuation;

	attenuation = 1.0 / (light->constant + light->linear * dist
				+ light->quadratic * sq_dist);
	return (attenuation);
}

t_vect3d				point_light_apply(const t_point_light *light,
						const t_scene *scene, const t_intersection *isect)
{
	double			sq_dist;
	double			dist;
	t_vect3d		dir_to_light;
	const t_object	*shadow_reason;
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
			return (attenuation
				* vect3d_from_scalar(shadow_reason->material.transparency)
				* calc_col(LIGHT_GET_COMPONENTS((*light)), dir_to_light,
					isect));
			return (attenuation * light->ambient
				* isect->hit_object->material.ambient);
	}
	return (attenuation * calc_col(LIGHT_GET_COMPONENTS((*light)), dir_to_light,
		isect));
}
