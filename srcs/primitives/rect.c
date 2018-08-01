/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/01 14:54:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"
#include "mmath.h"
#include <stdlib.h>

#define SIDE_X	0
#define SIDE_Y	1

#define EPS 0.001

short		rect_intersection(void *v_rect, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_rect		*rect;
	t_vect3d	x;
	double		cos_between_ray_and_normal;
	double		t;
	double		proj_on_axis;

	rect = (t_rect *)v_rect;
	x = start - rect->pos;
	cos_between_ray_and_normal = vect3d_dot(ray_dir, rect->basis.z);
	if (cos_between_ray_and_normal == 0)
		return (0);
	t = -vect3d_dot(x, rect->basis.z) / cos_between_ray_and_normal;
	if (t <= 0)
		return (0);
	*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	proj_on_axis = vect3d_dot(rect->basis.y, *intersect_point - rect->pos);
	if (proj_on_axis > rect->half_sides[SIDE_Y]
		|| proj_on_axis < -rect->half_sides[SIDE_Y])
		return (0);
	proj_on_axis = vect3d_dot(rect->basis.x, *intersect_point - rect->pos);
	if (proj_on_axis > rect->half_sides[SIDE_X]
		|| proj_on_axis < -rect->half_sides[SIDE_X])
		return (0);
	return (1);
}

void		rect_delete(void *rect)
{
	free(rect);
}

t_vect3d	rect_get_normal(void *v_rect, t_vect3d point)
{
	t_rect		*rect;

	(void)point;
	rect = (t_rect *)v_rect;
	return (rect->basis.z);
}

t_rect			*rect_new(t_vect3d pos, t_basis basis, double half_sides[2])
{
	t_rect	*rect;

	if (!(rect = malloc(sizeof(t_rect))))
		return (NULL);
	rect->pos = pos;
	rect->basis = basis;
	rect->half_sides[SIDE_X] = half_sides[SIDE_X];
	rect->half_sides[SIDE_Y] = half_sides[SIDE_Y];
	return (rect);
}
