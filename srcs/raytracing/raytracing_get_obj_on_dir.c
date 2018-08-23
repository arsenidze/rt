/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_get_obj_on_dir.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:39:35 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/23 14:25:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include "raytracing_private.h"
#include "vect3d.h"
#include "scene.h"
#include "intersection.h"
#include <stddef.h>

t_object const	*raytracing_get_obj_on_dir(t_vect3d point1, t_vect3d point2,
				t_vect3d dir, const t_scene *scene)
{
	t_ray			ray;
	t_intersection	isect;

	ray.o = point1;
	ray.d = dir;
	(void)point2;
	if (find_closest_intersection(scene, ray, &isect))
	{
		if (vect3d_is_fst_closer_snd_to(isect.dest, point2, point1))
		{
			return (isect.hit_object);
		}
	}
	return (NULL);
}
