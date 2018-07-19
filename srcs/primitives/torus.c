/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:18:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/17 20:14:50 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "torus.h"
#include "mmath.h"
#include <stdlib.h>

#define EPS 0.001

short		torus_intersection(void *v_torus, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_torus		*torus;
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

	torus = (t_torus *)v_torus;
	x = start - torus->pos;
	a = (torus->r1 - torus->r0) / 2.0 + torus->r0;
	b = (torus->r1 - torus->r0) / 2.0;
	c = vect3d_dot(x, torus->axis);
	d = vect3d_dot(ray_dir, torus->axis);
	
	q = x - vect3d_mult_on_scalar(torus->axis, c);
	f = ray_dir - vect3d_mult_on_scalar(torus->axis, d);

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
	 if (intersect_point)
	 	*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	return (1);
}

void		torus_delete(void *torus)
{
	free(torus);
}

t_vect3d	torus_get_normal(void *v_torus, t_vect3d point)
{
	t_torus		*torus;
	t_vect3d	normal;
	t_vect3d	mid;
	t_vect3d	bc;
	double		a;

	torus = (t_torus *)v_torus;
	a = (torus->r1 - torus->r0) / 2.0 + torus->r0;
	bc = point + vect3d_mult_on_scalar(torus->axis,
					vect3d_dot(torus->axis - point, torus->axis));
	mid  = vect3d_mult_on_scalar(vect3d_norm(bc), a);
	normal = point - mid;
	normal = vect3d_norm(normal);
	return (normal);
}

t_torus		*torus_new(t_vect3d pos, t_vect3d axis, double r0, double r1)
{
	t_torus	*torus;

	if (!(torus = malloc(sizeof(t_torus))))
		return (NULL);
	torus->pos = pos;
	torus->axis = axis;
	torus->r0 = r0;
	torus->r1 = r1;
	return (torus);
}
