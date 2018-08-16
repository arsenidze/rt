/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:18:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/12 10:58:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include "primitive.h"
#include "mmath.h"
#include <math.h>

t_torus			torus_create(double r0, double r1)
{
	t_torus	torus;

	torus.r0 = r0;
	torus.r1 = r1;
	torus.mid = (r1 - r0) / 2.0;
	return (torus);
}

#define EPS 0.001

//short			torus_intersection(t_primitive primitive, t_basis basis,
//				t_ray ray, t_vect3d *intersect_point)
//{
//	double		coeff[5];
//	double		t;
//	double		a;
//	double		b;
//	double		c;
//	double		d;
//	t_vect3d	q;
//	t_vect3d	f;
//	double		h;
//	double		j;
//	double		k;
//	double		roots[4];
//
//	a = primitive.torus.mid + primitive.torus.r0;
//	b = primitive.torus.mid;
//	c = vect3d_dot(ray.o, basis.z);
//	d = vect3d_dot(ray.d, basis.z);
//	
//	q = ray.o - vect3d_mult_on_scalar(basis.z, c);
//	f = ray.d - vect3d_mult_on_scalar(basis.z, d);
//
//	h = vect3d_dot(f, f) + d * d;
//	j = 2 * (vect3d_dot(q, f) + c * d);
//	k = vect3d_dot(q, q) + c * c + a * a - b * b;
//
//	coeff[0] = h * h;
//	coeff[1] = 2 * h * j;
//	coeff[2] = j * j + 2 * h * k - square(2 * a) * vect3d_dot(f, f);
//	coeff[3] = 2 * j * k - square(2 * a) * 2 * vect3d_dot(q, f);
//	coeff[4] = k * k - square(2 * a) * vect3d_dot(q, q);
//	solve4(coeff, roots);
//	int	i;
//	i = -1;
//	while (++i < 4)
//		if (roots[i] < 0)
//			roots[i] = INF;
//	t = roots[0];
//	i = 1;
//	while (++i < 4)
//		if (roots[i] < t)
//			t = roots[i];
//	if (t == INF || t != t)
//		return (0);
//	 *intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, t - EPS);
//	return (1);
//}

short			torus_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		coeff[5];
	double		t;
	double		a;
	double		b;
	double		c;
	double		d;
	t_vect3d	x;
	t_vect3d	q;
	t_vect3d	f;
	double		h;
	double		j;
	double		k;
	double		roots[4];

	x = ray.o;
	a = (primitive.torus.r1 - primitive.torus.r0) / 2.0 + primitive.torus.r0;
	b = (primitive.torus.r1 - primitive.torus.r0) / 2.0;
	c = vect3d_dot(x, basis.z);
	d = vect3d_dot(ray.d, basis.z);
	
	q = x - vect3d_mult_on_scalar(basis.z, c);
	f = ray.d - vect3d_mult_on_scalar(basis.z, d);

	h = vect3d_dot(f, f) + d * d;
	j = 2 * (vect3d_dot(q, f) + c * d);
	k = vect3d_dot(q, q) + c * c + a * a - b * b;

	coeff[0] = h * h;
	coeff[1] = 2 * h * j;
	coeff[2] = j * j + 2 * h * k - square(2 * a) * vect3d_dot(f, f);
	coeff[3] = 2 * j * k - square(2 * a) * 2 * vect3d_dot(q, f);
	coeff[4] = k * k - square(2 * a) * vect3d_dot(q, q);
	solve4(coeff, roots);
	int	i;
	i = -1;
	while (++i < 4)
		if (roots[i] < 0)
			roots[i] = INF;
	t = roots[0];
	i = 1;
	while (++i < 4)
		if (roots[i] < t)
			t = roots[i];
	if (t == INF || t != t)
		return (0);
	*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, t - EPS);
	return (1);
}


t_vect3d		torus_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	t_vect3d	normal;
	t_vect3d	mid_vect;
	t_vect3d	bc;
	double		a;

	a = primitive.torus.r0 + primitive.torus.mid;
	bc = point - vect3d_mult_on_scalar(basis.z, vect3d_dot(point, basis.z));
	//bc = point + vect3d_mult_on_scalar(basis.z,
	//	vect3d_dot(basis.z - point, basis.z));
	mid_vect = vect3d_mult_on_scalar(vect3d_norm(bc), a);
	normal = point - mid_vect;
	normal = vect3d_norm(normal);
	//normal = vect3d_div_on_scalar(normal, primitive.torus.mid);
	return (normal);
}

void			torus_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2])
{
	t_vect3d	bc;
	t_vect3d	shifted_point;
	double		phi;
	double		theta;

	point = basis_get_coord_in_basis(basis, point);
	bc = point - vect3d_mult_on_scalar(basis.z, vect3d_dot(point, basis.z));
	bc = vect3d_norm(bc);
	shifted_point = point - vect3d_mult_on_scalar(bc, primitive.torus.mid);
	phi = atan2(point[Y], point[X]) + M_PI;
	theta = acos(shifted_point[Z] / primitive.torus.mid);
	coord[0] = phi / (2.0 * M_PI);
	coord[1] = theta / (2.0 * M_PI);
}
