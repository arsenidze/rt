/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:18:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 14:05:36 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include "primitive.h"
#include "mmath.h"
#include <math.h>
#include "primitive_private.h"

t_torus			torus_create(double r0, double r1)
{
	t_torus	torus;

	torus.r0 = r0;
	torus.r1 = r1;
	torus.cross_cut_r = (r1 - r0) / 2.0;
	torus.mid_r = r0 + torus.cross_cut_r;
	return (torus);
}

static void		torus_fill_coeff(t_primitive primitive, t_basis basis,
				t_ray ray, double coeff[5])
{
	double		tmp[6];
	t_vect3d	tmp_vect[2];
	double		h;
	double		j;
	double		k;

	tmp[0] = vect3d_dot(ray.o, basis.z);
	tmp[1] = vect3d_dot(ray.d, basis.z);
	tmp[2] = primitive.torus.mid_r * primitive.torus.mid_r;
	tmp_vect[1] = ray.o - vect3d_mult_on_scalar(basis.z, tmp[0]);
	tmp_vect[0] = ray.d - vect3d_mult_on_scalar(basis.z, tmp[1]);
	tmp[3] = vect3d_dot(tmp_vect[0], tmp_vect[0]);
	tmp[4] = vect3d_dot(tmp_vect[0], tmp_vect[1]);
	tmp[5] = vect3d_dot(tmp_vect[1], tmp_vect[1]);
	h = tmp[3] + tmp[1] * tmp[1];
	j = 2 * (tmp[4] + tmp[0] * tmp[1]);
	k = tmp[5] + tmp[0] * tmp[0] + tmp[2]
		- primitive.torus.cross_cut_r * primitive.torus.cross_cut_r;
	coeff[0] = h * h;
	coeff[1] = 2 * h * j;
	coeff[2] = j * j + 2 * h * k - 4 * tmp[2] * tmp[3];
	coeff[3] = 2 * j * k - 4 * tmp[2] * 2 * tmp[4];
	coeff[4] = k * k - 4 * tmp[2] * tmp[5];
}

#define EPS 0.001

short			torus_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		coeff[5];
	double		roots[4];
	int			num_real_roots;
	int			num_pos_roots;

	torus_fill_coeff(primitive, basis, ray, coeff);
	num_real_roots = solve4(coeff, roots);
	if (num_real_roots == 0)
		return (0);
	num_pos_roots = sort_and_left_positive_roots(roots, num_real_roots);
	if (num_pos_roots == 0)
		return (0);
	*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, roots[0] - EPS);
	return (1);
}

t_vect3d		torus_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	t_vect3d	normal;
	t_vect3d	mid_vect;
	t_vect3d	bc;
	double		a;

	a = primitive.torus.mid_r;
	bc = point - vect3d_mult_on_scalar(basis.z, vect3d_dot(point, basis.z));
	mid_vect = vect3d_mult_on_scalar(vect3d_norm(bc), a);
	normal = point - mid_vect;
	normal = vect3d_div_on_scalar(normal, primitive.torus.cross_cut_r);
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
	shifted_point = point
					- vect3d_mult_on_scalar(bc, primitive.torus.cross_cut_r);
	phi = atan2(point[Y], point[X]) + M_PI;
	theta = acos(shifted_point[Z] / primitive.torus.cross_cut_r);
	coord[0] = phi / (2.0 * M_PI);
	coord[1] = theta / (2.0 * M_PI);
}
