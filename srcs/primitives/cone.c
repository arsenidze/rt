/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:09:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:10:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "mmath.h"
#include <stdlib.h>

#define EPS 0.001

short		cone_intersection(void *v_cone, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_cone		*cone;
	t_vect3d	x;
	t_vect3d	v;
	double		coefficients[3];
	double		t;

	cone = (t_cone *)v_cone;
	x = start - cone->pos;
	v = cone->axis;
	coefficients[0] = vect3d_dot(ray_dir, ray_dir)
					- square(vect3d_dot(ray_dir, v))
					* (1 + cone->k * cone->k);
	coefficients[1] = vect3d_dot(ray_dir, x)
					- vect3d_dot(ray_dir, v) * vect3d_dot(x, v)
					* (1 + cone->k * cone->k);
	coefficients[2] = vect3d_dot(x, x)
					- square(vect3d_dot(x, v))
					* (1 + cone->k * cone->k);
	t = get_positive_root(coefficients);
	if (t < 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	return (1);
}

void		cone_delete(void *cone)
{
	free(cone);
}

t_vect3d	cone_get_normal(void *v_cone, t_vect3d point)
{
	t_cone		*cone;
	t_vect3d	v;
	t_vect3d	c;
	double		m;
	t_vect3d	normal;

	cone = (t_cone *)v_cone;
	v = cone->axis;
	c = cone->pos;
	m = (vect3d_dot(v, point) - vect3d_dot(v, c)) / vect3d_dot(v, v);
	normal = point
			- (c + vect3d_mult_on_scalar(v, m * (1 + cone->k * cone->k)));
	normal = vect3d_norm(normal);
	return (normal);
}

t_cone		*cone_new(t_vect3d pos, t_vect3d axis, double k)
{
	t_cone	*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (NULL);
	cone->pos = pos;
	cone->axis = axis;
	cone->k = k;
	return (cone);
}
