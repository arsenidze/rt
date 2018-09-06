/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/06 21:09:04 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "scene.h"
#include "vect3d.h"
#include "raytracing.h"
#include "intersection.h"
#include "ray.h"

t_vect3d	trace_ray(const t_scene *scene, t_ray ray, int depth)

{
	t_intersection	isect;
	t_vect3d		point_col;

	if (find_closest_intersection(scene, ray, &isect))
	{
		point_col = apply_light(scene, &isect);
		if ((isect.hit_object->material.reflection > 0.0
			|| isect.hit_object->material.transparency > 0.0))
		{
			if (depth < MAX_RAY_DEPTH)
				point_col += handle_reflection_and_refraction(scene, &isect,
					depth);
		}
		return (vect3d_clamp(point_col, 0, 1));
	}
	return (BACKGROUND_COLOR);
}
