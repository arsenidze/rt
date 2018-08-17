/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:09:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 23:23:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "primitive.h"
#include "disk.h"
#include "mmath.h"
#include "primitive_private.h"
#include <math.h>

static void		cone_fill_coeff(t_primitive primitive, t_basis basis,
				t_ray ray, double coeff[3])
{
	coeff[0] = 1.
			- square(vect3d_dot(ray.d, basis.z)) * (1 + primitive.cone.slope2);
	coeff[1] = 2.0 * (vect3d_dot(ray.d, ray.o)
				- vect3d_dot(ray.d, basis.z) * vect3d_dot(ray.o, basis.z)
				* (1 + primitive.cone.slope2));
	coeff[2] = vect3d_dot(ray.o, ray.o) - square(vect3d_dot(ray.o, basis.z))
				* (1 + primitive.cone.slope2);
}

#define EPS 0.001

static short	cone_limitation_check(t_cone cone, t_basis basis, t_ray ray,
				t_vect3d *intersect_point)
{
	double		proj_on_axis;
	t_vect3d	axis;
	short		is_isect;

	proj_on_axis = vect3d_dot(*intersect_point, basis.z);
	if (proj_on_axis <= 0.0)
		return (0);
	if (proj_on_axis >= cone.h)
	{
		axis = vect3d_mult_on_scalar(basis.z, cone.h);
		ray.o -= axis;
		is_isect = disk_intersection(PRIMITIVE(disk, cone.r), basis, ray,
			intersect_point);
		if (is_isect)
			*intersect_point += axis;
		return (is_isect);
	}
	else
		return (1);
}

short			cone_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *isect_pnt)
{
	double		coeff[3];
	double		roots[2];
	int			num_real_roots;
	int			num_pos_roots;
	int			i;

	cone_fill_coeff(primitive, basis, ray, coeff);
	if ((num_real_roots = solve2(coeff, roots)) == 0)
		return (0);
	num_pos_roots = sort_and_left_positive_roots(roots, num_real_roots);
	if (num_pos_roots == 0)
		return (0);
	if (primitive.cone.h < 0.0)
	{
		*isect_pnt = ray.o + vect3d_mult_on_scalar(ray.d, roots[0] - EPS);
		return (1);
	}
	i = -1;
	while (++i < num_pos_roots)
	{
		*isect_pnt = ray.o + vect3d_mult_on_scalar(ray.d, roots[i] - EPS);
		if (cone_limitation_check(primitive.cone, basis, ray, isect_pnt))
			return (1);
	}
	return (0);
}

t_vect3d		cone_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	double		proj_on_axis;
	double		m;
	t_vect3d	normal;

	if (primitive.cone.h >= 0.0)
	{
		proj_on_axis = vect3d_dot(point, basis.z);
		if (proj_on_axis >= primitive.cone.h)
		{
			return (disk_get_normal(PRIMITIVE(disk, primitive.cone.r), basis,
				point - vect3d_mult_on_scalar(basis.z, primitive.cone.h)));
		}
	}
	m = vect3d_dot(basis.z, point);
	normal = point
			- (vect3d_mult_on_scalar(basis.z, m * (1 + primitive.cone.slope2)));
	normal = vect3d_norm(normal);
	return (normal);
}

void			cone_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2])
{
	double	phi;

	point = basis_get_coord_in_basis(basis, point);
	phi = atan2(point[Y], point[X]) + M_PI;
	coord[0] = phi / (2.0 * M_PI);
	coord[1] = 1.0 - point[Z] / primitive.cone.h;
}
