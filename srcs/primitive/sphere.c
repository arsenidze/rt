/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/12 11:29:43 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "primitive.h"
#include "basis.h"
#include "mmath.h"
#include <math.h>

t_sphere		sphere_create(double r)
{
	t_sphere	sphere;

	sphere.r = r;
	sphere.r2 = r * r;
	return (sphere);
}

static void		sphere_fill_coeff(t_primitive primitive, t_ray ray,
				double coeff[3])
{
	coeff[0] = 1;
	coeff[1] = vect3d_dot(ray.o, ray.d);
	coeff[2] = vect3d_dot(ray.o, ray.o) - primitive.sphere.r2;
}

#define EPS 0.001

short			sphere_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		coeff[3];
	double		t;

	(void)basis;
	sphere_fill_coeff(primitive, ray, coeff);
	t = get_positive_root(coeff);
	if (t < 0)
		return (0);
	*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, t - EPS);
	return (1);
}

t_vect3d	sphere_get_normal(t_primitive primitive, t_basis basis,
			t_vect3d point)
{
	t_vect3d	normal;

	(void)primitive;
	(void)basis;
	normal = vect3d_norm(point);
	return (normal);
}

void			sphere_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2])
{
	double		phi;
	double		theta;
	double		r;

	(void)primitive;
	point = basis_get_coord_in_basis(basis, point);
	r = primitive.sphere.r;
	phi = atan2(point[Y], point[X]) + M_PI;
	theta = acos(point[Z] / r);
	coord[0] = phi / (2.0 * M_PI);
	coord[1] = theta / (2.0 * M_PI);
}
