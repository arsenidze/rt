/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 19:49:42 by amelihov         ###   ########.fr       */
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
		if ((isect.hit_object->material.reflection > 0.0
			|| isect.hit_object->material.transparency > 0.0)
			&& depth < MAX_RAY_DEPTH)
			return (handle_reflection_and_refraction(scene, &isect, depth));
		else
		{
			point_col = apply_light(scene, &isect);
			return (point_col);
		}
	}
	return (BACKGROUND_COLOR);
}
