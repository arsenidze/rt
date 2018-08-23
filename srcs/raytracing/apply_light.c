/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 23:09:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/23 14:44:12 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "scene.h"
#include "intersection.h"
#include "vect3d.h"
#include "object.h"
#include <stddef.h>

t_vect3d	apply_light(const t_scene *scene, const t_intersection *isect)
{
	t_uint			i;
	t_vect3d		output;
	const t_object	*obj_handler;
	t_object		tmp_object;

	obj_handler = NULL;
	if (OBJ_HAS_TEX((*isect->hit_object)))
	{
		obj_handler = isect->hit_object;
		tmp_object = *isect->hit_object;
		object_update_material_according_to_tex(&tmp_object, isect->dest);
		((t_intersection *)isect)->hit_object = &tmp_object;
	}
	output = vect3d(0, 0, 0);
	i = 0;
	while (i < scene->lights.size)
	{
		output += light_apply_light_by_type(&scene->lights.data[i], scene,
			isect);
		i++;
	}
	if (obj_handler)
		((t_intersection *)isect)->hit_object = obj_handler;
	output = vect3d_clamp(output, 0, 1);
	return (output);
}
