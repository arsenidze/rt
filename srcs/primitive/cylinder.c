/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:13:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 23:03:05 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "primitive.h"
#include "disk.h"
#include "basis.h"
#include "mmath.h"
#include <math.h>

t_cylinder		cylinder_create(double r, double h)
{
	t_cylinder	cylinder;

	cylinder.r = r;
	cylinder.r2 = r * r;
	cylinder.h = h;
	return (cylinder);
}

static short	cylinder_limitation_check(t_cylinder cylinder, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		proj_on_axis;
	t_vect3d	axis;
	short		is_isect;

	proj_on_axis = vect3d_dot(*intersect_point, basis.z);
	if (proj_on_axis <= 0.0)
		return (disk_intersection(PRIMITIVE(disk, cylinder.r), basis, ray,
			intersect_point));
	else if (proj_on_axis >= cylinder.h)
	{
		axis = vect3d_mult_on_scalar(basis.z, cylinder.h);
		ray.o -= axis;
		is_isect = disk_intersection(PRIMITIVE(disk, cylinder.r), basis, ray,
			intersect_point);
		if (is_isect)
			*intersect_point += axis;
		return (is_isect);
	}
	else
		return (1);
}

#define EPS 0.001

short			cylinder_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		coeff[3];
	double		t;

	coeff[0] = 1.0 - square(vect3d_dot(ray.d, basis.z));
	coeff[1] = vect3d_dot(ray.d, ray.o) - vect3d_dot(ray.d, basis.z)
				* vect3d_dot(ray.o, basis.z);
	coeff[2] = vect3d_dot(ray.o, ray.o) - square(vect3d_dot(ray.o, basis.z))
				- primitive.cylinder.r2;
	t = get_positive_root(coeff);
	if (t < 0)
		return (0);
	*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, t - EPS);
	if (primitive.cylinder.h < 0.0)
		return (1);
	else
		return (cylinder_limitation_check(primitive.cylinder, basis, ray,
			intersect_point));
}

t_vect3d		cylinder_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	double		proj_on_axis;
	double		m;
	t_vect3d	normal;

	if (primitive.cylinder.h >= 0.0)
	{
		proj_on_axis = vect3d_dot(point, basis.z);
		if (proj_on_axis <= 0.0)
			return (disk_get_normal(PRIMITIVE(disk, primitive.cylinder.r),
				basis, point));
		else if (proj_on_axis >= primitive.cylinder.h)
			return (-disk_get_normal(PRIMITIVE(disk, primitive.cylinder.r),
		basis, point - vect3d_mult_on_scalar(basis.z, primitive.cylinder.h)));
	}
	m = vect3d_dot(basis.z, point);
	normal = point - vect3d_mult_on_scalar(basis.z, m);
	normal = vect3d_norm(normal);
	return (normal);
}

void			cylinder_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2])
{
	double	phi;

	point = basis_get_coord_in_basis(basis, point);
	phi = atan2(point[Y], point[X]) + M_PI;
	coord[0] = phi / (2.0 * M_PI);
	coord[1] = 1.0 - point[Z] / primitive.cylinder.h;
}
