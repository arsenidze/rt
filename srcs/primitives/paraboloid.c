/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/04 16:30:53 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paraboloid.h"
#include "mmath.h"
#include <stdlib.h>

#define EPS 0.001

short		paraboloid_intersection(void *v_paraboloid, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_paraboloid	*paraboloid;
	t_vect3d		x;
	double			coefficients[3];
	double			t;

	paraboloid = (t_paraboloid *)v_paraboloid;
	x = start - paraboloid->pos;
	coefficients[0] = vect3d_dot(ray_dir, ray_dir)
					- square(vect3d_dot(ray_dir, paraboloid->axis));
	coefficients[1] = vect3d_dot(ray_dir, x)
					- vect3d_dot(ray_dir, paraboloid->axis)
					* (vect3d_dot(x, paraboloid->axis) + 2 * paraboloid->k);
	coefficients[2] = vect3d_dot(x, x)
					- vect3d_dot(x, paraboloid->axis)
					* (vect3d_dot(x, paraboloid->axis) + 4 * paraboloid->k);
	t = get_positive_root(coefficients);
	if (t < 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	return (1);
}

void		paraboloid_delete(void *paraboloid)
{
	free(paraboloid);
}

t_vect3d	paraboloid_get_normal(void *v_paraboloid, t_vect3d point)
{
	t_paraboloid	*paraboloid;
	t_vect3d		normal;
	double			m;

	paraboloid = (t_paraboloid *)v_paraboloid;
	m = vect3d_dot(point - paraboloid->pos, paraboloid->axis);
	normal = point - paraboloid->pos
			- vect3d_mult_on_scalar(paraboloid->axis, m + paraboloid->k);
	normal = vect3d_norm(normal);
	return (normal);
}

void			paraboloid_get_tex_coord(void *v_paraboloid, t_vect3d point,
				float coord[2])
{
	(void)v_paraboloid;
	(void)point;
	(void)coord;
}

t_paraboloid	*paraboloid_new(t_vect3d pos, t_vect3d axis, double k)
{
	t_paraboloid	*paraboloid;

	if (!(paraboloid = malloc(sizeof(t_paraboloid))))
		return (NULL);
	paraboloid->pos = pos;
	paraboloid->axis= axis;
	paraboloid->k = k;
	return (paraboloid);
}
