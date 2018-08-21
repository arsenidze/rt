/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 23:09:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 19:36:50 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "scene.h"
#include "intersection.h"
#include "vect3d.h"

t_vect3d	apply_light(const t_scene *scene, const t_intersection *isect)
{
	t_uint		i;
	t_vect3d	output;

	if (OBJ_HAS_TEX((*isect->hit_object)))
		object_update_material_according_to_tex(isect->hit_object, isect->dest);
	output = vect3d(0, 0, 0);
	i = 0;
	while (i < scene->lights.size)
	{
		output += light_apply_light_by_type(&scene->lights.data[i], scene,
			isect);
		i++;
	}
	output = vect3d_clamp(output, 0, 1);
	return (output);
}
