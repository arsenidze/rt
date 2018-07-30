/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/30 20:51:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disc.h"
#include "mmath.h"
#include <stdlib.h>

#define EPS 0.001

short		disc_intersection(void *v_disc, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_disc		*disc;
	t_vect3d	x;
	double		cos_between_ray_and_normal;
	double		t;

	disc = (t_disc *)v_disc;
	x = start - disc->pos;
	cos_between_ray_and_normal = vect3d_dot(ray_dir, disc->normal);
	if (cos_between_ray_and_normal == 0)
		return (0);
	t = -vect3d_dot(x, disc->normal) / cos_between_ray_and_normal;
	if (t <= 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	else
		return (1);
	if (vect3d_sq_len(*intersect_point - disc->pos) <= disc->r2)
		return (1);
	else
		return (0);
}

void		disc_delete(void *disc)
{
	free(disc);
}

t_vect3d	disc_get_normal(void *v_disc, t_vect3d point)
{
	t_disc		*disc;

	(void)point;
	disc = (t_disc *)v_disc;
	return (disc->normal);
}

t_disc		*disc_new(t_vect3d pos, t_vect3d normal, double r)
{
	t_disc	*disc;

	if (!(disc = malloc(sizeof(t_disc))))
		return (NULL);
	disc->pos = pos;
	disc->normal = normal;
	disc->r = r;
	disc->r2 = r * r;
	return (disc);
}
