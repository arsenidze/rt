/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:15:19 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:13:41 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "vect3d.h"
#include "object.h"
#include "intersection.h"

#define IS_INTERSECT_OBJ(s, r, o, i) o->intersection(o->primitive,s,r,i)

/*
**	function 'find_closest_intersection' don't fill 'normal' field in
**	out 'intersection' parameter for optimization purpose.
*/

short	find_closest_intersection(t_scene *scene, t_vect3d start,
		t_vect3d ray_dir, t_intersection *intersection)
{
	int			i;
	t_object	*curr_object;
	t_vect3d	intersect_point;
	short		was_intersect;

	was_intersect = 0;
	intersection->orig = start;
	intersection->dest = vect3d(0, 0, 0);
	intersection->ray_dir = ray_dir;
	i = 0;
	while (scene->objects[i])
	{
		curr_object = scene->objects[i];
		if (IS_INTERSECT_OBJ(start, ray_dir, curr_object, &intersect_point)
			&& (!was_intersect
				|| vect3d_sq_len(intersect_point - start)
					< vect3d_sq_len(intersection->dest - start)))
		{
			was_intersect = 1;
			intersection->dest = intersect_point;
			intersection->hit_object = curr_object;
		}
		i++;
	}
	return (was_intersect);
}
