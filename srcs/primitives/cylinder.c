/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:13:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:13:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "mmath.h"
#include <stdlib.h>

#define EPS 0.001

short		cylinder_intersection(void *v_cylinder, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_cylinder	*cylinder;
	t_vect3d	x;
	t_vect3d	v;
	double		coefficients[3];
	double		t;

	cylinder = (t_cylinder *)v_cylinder;
	x = start - cylinder->pos;
	v = cylinder->axis;
	coefficients[0] = vect3d_dot(ray_dir, ray_dir)
					- square(vect3d_dot(ray_dir, v));
	coefficients[1] = vect3d_dot(ray_dir, x)
					- vect3d_dot(ray_dir, v) * vect3d_dot(x, v);
	coefficients[2] = vect3d_dot(x, x)
					- square(vect3d_dot(x, v))
					- (cylinder->radius * cylinder->radius);
	t = get_positive_root(coefficients);
	if (t < 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	return (1);
}

void		cylinder_delete(void *cylinder)
{
	free(cylinder);
}

t_vect3d	cylinder_get_normal(void *v_cylinder, t_vect3d point)
{
	t_cylinder	*cylinder;
	t_vect3d	v;
	t_vect3d	c;
	double		m;
	t_vect3d	normal;

	cylinder = (t_cylinder *)v_cylinder;
	v = cylinder->axis;
	c = cylinder->pos;
	m = (vect3d_dot(v, point) - vect3d_dot(v, c)) / vect3d_dot(v, v);
	normal = point - (c + vect3d_mult_on_scalar(v, m));
	normal = vect3d_norm(normal);
	return (normal);
}

t_cylinder	*cylinder_new(t_vect3d pos, t_vect3d axis, double radius)
{
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (NULL);
	cylinder->pos = pos;
	cylinder->axis = axis;
	cylinder->radius = radius;
	return (cylinder);
}
