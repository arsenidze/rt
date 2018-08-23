/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight_light_apply.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:40:29 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/23 14:42:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spotlight_light.h"
#include "light_private.h"
#include "raytracing.h"
#include "intersection.h"
#include "vect3d.h"

t_vect3d	spotlight_light_apply(const t_spotlight_light *light,
			const t_scene *scene, const t_intersection *isect)
{
	t_vect3d		dir_to_light;
	const t_object	*shadow_reason;
	double			cos_theta;

	dir_to_light = light->pos - isect->dest;
	dir_to_light = vect3d_norm(dir_to_light);
	cos_theta = vect3d_dot(-dir_to_light, light->dir);
	if (cos_theta < light->cos_of_cut_off)
		return (light->ambient * isect->hit_object->material.ambient);
	if ((shadow_reason = raytracing_get_obj_on_dir(isect->dest, light->pos,
		dir_to_light, scene)))
	{
		if (shadow_reason->material.transparency > 0)
		{
			return (vect3d_from_scalar(shadow_reason->material.transparency)
				* calc_col(LIGHT_GET_COMPONENTS((*light)), dir_to_light,
					isect));
		}
		return (light->ambient * isect->hit_object->material.ambient);
	}
	return (calc_col(LIGHT_GET_COMPONENTS((*light)), dir_to_light, isect));
}
