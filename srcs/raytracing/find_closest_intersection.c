/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:15:19 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 15:24:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "intersection.h"
#include "object.h"
#include "vect3d.h"

static void	set_normal(t_intersection *isect, t_ray ray)
{
	isect->normal = object_get_normal(isect->hit_object, isect->dest);
	isect->inside = 0;
	if (vect3d_dot(ray.d, isect->normal) > 0)
	{
		isect->normal = -isect->normal;
		isect->inside = 1;
	}
}

short		find_closest_intersection(const t_scene *scene, t_ray ray,
			t_intersection *isect)
{
	unsigned int	i;
	t_object		*curr_object;
	t_vect3d		isect_point;
	short			is_isect;

	is_isect = 0;
	isect->ray = ray;
	i = 0;
	while (i < scene->objects.size)
	{
		curr_object = &scene->objects.data[i];
		if (object_intersection(curr_object, ray, &isect_point) && (!is_isect
			|| vect3d_sq_len(isect_point - ray.o)
				< vect3d_sq_len(isect->dest - ray.o)))
		{
			is_isect = 1;
			isect->dest = isect_point;
			isect->hit_object = curr_object;
		}
		i++;
	}
	if (is_isect)
		set_normal(isect, ray);
	return (is_isect);
}
