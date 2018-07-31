/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 22:46:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"
#include "mmath.h"
#include <stdlib.h>

#define EPS 0.001

short		rect_intersection(void *v_rect, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_rect		*rect;
	t_vect3d	x;
	double		cos_between_ray_and_normal;
	double		t;

	rect = (t_rect *)v_rect;
	x = start - rect->pos;
	cos_between_ray_and_normal = vect3d_dot(ray_dir, rect->normal);
	if (cos_between_ray_and_normal == 0)
		return (0);
	t = -vect3d_dot(x, rect->normal) / cos_between_ray_and_normal;
	if (t <= 0)
		return (0);
	*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	if (vect3d_dot(u, *intersect_point - rect->pos) > w)
		return (0);
	if (vect3d_dot(v, *intersect_point - rect->pos) > h)
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
	return (rect->normal);
}

t_rect			*rect_new(t_vect3d pos, t_vect3 normal, t_vect3d u,
				t_vect3d v, double w, double h);
{
	t_rect	*rect;

	if (!(rect = malloc(sizeof(t_rect))))
		return (NULL);
	rect->pos = pos;
	rect->normal = normal;
	rect->u = u;
	rect->v = v;
	rect->w = w;
	rect->h = h;
	return (rect);
}
