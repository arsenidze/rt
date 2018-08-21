/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 13:49:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "primitive.h"
#include "mmath.h"
#include <math.h>

t_plane			plane_create(void)
{
	t_plane	plane;

	plane.tex_scale = 500;
	return (plane);
}

#define EPS 0.001

short			plane_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		cos_between_ray_and_normal;
	double		t;

	(void)primitive;
	cos_between_ray_and_normal = vect3d_dot(ray.d, basis.z);
	if (cos_between_ray_and_normal == 0)
		return (0);
	t = -vect3d_dot(ray.o, basis.z) / cos_between_ray_and_normal;
	if (t <= 0)
		return (0);
	*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, t - EPS);
	return (1);
}

t_vect3d		plane_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	(void)primitive;
	(void)point;
	return (basis.z);
}

void			plane_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2])
{
	point = basis_get_coord_in_basis(basis, point);
	coord[0] = fabs(fmod(point[Y], primitive.plane.tex_scale))
				/ primitive.plane.tex_scale;
	coord[1] = fabs(fmod(point[X], primitive.plane.tex_scale))
				/ primitive.plane.tex_scale;
}
