/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/13 20:42:08 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paraboloid.h"
#include "primitive.h"
#include "mmath.h"
#include <math.h>

int	sort_and_left_positive_roots(double *roots, int n);

t_paraboloid	paraboloid_create(double k, double h)
{
	t_paraboloid	paraboloid;

	paraboloid.k = k;
	paraboloid.h = h;
	return (paraboloid);
}

#define EPS 0.001

static short	paraboloid_limitation_check(t_paraboloid paraboloid,
				t_basis basis, t_ray ray, t_vect3d *intersect_point)
{
	double		proj_on_axis;
	
	(void)ray;
	proj_on_axis = vect3d_dot(*intersect_point, basis.z);
	if (proj_on_axis >= paraboloid.h)
		return (0);
	else
		return (1);
}

short			paraboloid_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		coeff[3];
	double		roots[2];
	int			num_real_roots;
	int			num_pos_roots;
	int			i;

	coeff[0] = 1.0 - square(vect3d_dot(ray.d, basis.z));
	coeff[1] = 2.0 * (vect3d_dot(ray.d, ray.o) - vect3d_dot(ray.d, basis.z)
					* (vect3d_dot(ray.o, basis.z) + 2 * primitive.paraboloid.k));
	coeff[2] = vect3d_dot(ray.o, ray.o) - vect3d_dot(ray.o, basis.z)
					* (vect3d_dot(ray.o, basis.z) + 4 * primitive.paraboloid.k);
	num_real_roots = solve2(coeff, roots);
	if (num_real_roots == 0)
		return (0);
	num_pos_roots = sort_and_left_positive_roots(roots, num_real_roots);
	if (num_pos_roots == 0)
		return (0);
	if (primitive.paraboloid.h < 0.0)
	{
		*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, roots[0] - EPS);
		return (1);
	}
	i = 0;
	while (i < num_pos_roots)
	{
		*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, roots[i] - EPS);
		if (paraboloid_limitation_check(primitive.paraboloid, basis, ray,
			intersect_point))
		return (1);
		i++;
	}
	return (0);
}

t_vect3d		paraboloid_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	double			m;
	t_vect3d		normal;

	m = vect3d_dot(point, basis.z);
	normal = point
			- vect3d_mult_on_scalar(basis.z, m + primitive.paraboloid.k);
	normal = vect3d_norm(normal);
	return (normal);
}

void			paraboloid_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2])
{
	double	phi;

	point = basis_get_coord_in_basis(basis, point);
	phi = atan2(point[Y], point[X]) + M_PI;
	coord[0] = phi / (2.0 * M_PI);
	coord[1] = 1.0 - point[Z] / primitive.paraboloid.h;
}
