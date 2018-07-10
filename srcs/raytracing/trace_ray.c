/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:58:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:16:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "color.h"
#include "vect3d.h"
#include "raytracing.h"
#include "apply_light.h"
#include "intersection.h"

#define BACKGROUND_COLOR COLOR(0x00000000)

t_color	trace_ray(t_scene *scene, t_vect3d ray_dir)
{
	t_intersection	intersection;
	t_color			res_color;

	if (find_closest_intersection(scene, scene->camera->pos, ray_dir,
		&intersection))
	{
		res_color = apply_light(scene, &intersection);
		return (res_color);
	}
	return (BACKGROUND_COLOR);
}
