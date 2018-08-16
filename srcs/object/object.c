/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:49:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 14:50:05 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

short		object_intersection(const t_object *object, t_ray ray,
			t_vect3d *intersect_point)
{
	t_ray	shifted_ray;
	short	is_isect;
//	double	angels[3];
//
//	angels[0] = vect3d_dot(object->basis.x, vect3d(1, 0, 0));
//	angels[1] = vect3d_dot(object->basis.y, vect3d(0, 1, 0));
//	angels[2] = vect3d_dot(object->basis.z, vect3d(0, 0, 1));
	shifted_ray.o = ray.o - object->pos;
	shifted_ray.d = ray.d;
	is_isect = object->shape.intersection(object->shape.primitive,
		object->basis, shifted_ray, intersect_point);
	if (is_isect)
		*intersect_point += object->pos;
	return (is_isect);
}

t_vect3d	object_get_normal(const t_object *object, t_vect3d point)
{
	return (object->shape.get_normal(object->shape.primitive, object->basis,
		point - object->pos));
}

void		object_get_tex_coord(const t_object *object, t_vect3d point,
			float coord[2])
{
	object->shape.get_tex_coord(object->shape.primitive, object->basis,
		point - object->pos, coord);
}
