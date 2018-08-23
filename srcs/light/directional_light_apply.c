/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional_light_apply.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:40:29 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/23 14:39:54 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directional_light.h"
#include "light_private.h"
#include "raytracing.h"
#include "intersection.h"
#include "vect3d.h"
#include "intersection.h"

t_vect3d	directional_light_apply(const t_directional_light *light,
			const t_scene *scene, const t_intersection *isect)
{
	t_vect3d		dir_to_light;
	const t_object	*shadow_reason;

	dir_to_light = -light->dir;
	if ((shadow_reason = raytracing_get_obj_on_dir(isect->dest, vect3d_inf(),
		dir_to_light, scene)))
	{
		if (shadow_reason->material.transparency > 0)
		{
			return (vect3d_from_scalar(shadow_reason->material.transparency)
			* calc_col(LIGHT_GET_COMPONENTS((*light)), dir_to_light, isect));
		}
		return (light->ambient * isect->hit_object->material.ambient);
	}
	return (calc_col(LIGHT_GET_COMPONENTS((*light)), dir_to_light, isect));
}
