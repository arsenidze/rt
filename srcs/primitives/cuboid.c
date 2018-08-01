/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/01 16:23:58 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuboid.h"
#include "rect.h"
#include "mmath.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

#define SIDE_X	0
#define SIDE_Y	1
#define SIDE_Z	2

#define FACE_TOP	0
#define FACE_BOT	1
#define FACE_LEFT	2
#define FACE_RIGHT	3
#define FACE_FAR	4
#define FACE_NEAR	5

#define EPS 0.001

short		cuboid_intersection(void *v_cuboid, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_cuboid	*cuboid;
	int			i;
	t_vect3d	tmp_isect_pnt;
	t_vect3d	closest_isect;
	int			is_isect;
	t_rect		tmp_rect;

	cuboid = (t_cuboid *)v_cuboid;
	is_isect = 0;
	closest_isect = vect3d(INF, INF, INF);
	i = 0;
	while (i < 6)
	{
		tmp_rect = cuboid->faces[i];
		tmp_rect.pos += cuboid->pos;
		if (rect_intersection(&tmp_rect, start, ray_dir,
			&tmp_isect_pnt))
		{
			if (vect3d_sq_len(closest_isect - start)
				> vect3d_sq_len(tmp_isect_pnt - start))
				closest_isect = tmp_isect_pnt;
			is_isect = 1;
		}
		i++;
	}
	if (is_isect)
	{
		*intersect_point = closest_isect;
		return (1);
	}
	else
		return (0);
}

void		cuboid_delete(void *cuboid)
{
	free(cuboid);
}
#include <stdio.h>
#include <stdlib.h>
t_vect3d	cuboid_get_normal(void *v_cuboid, t_vect3d point)
{
	t_cuboid	*cuboid;
	double		proj_on_axis;

	cuboid = (t_cuboid *)v_cuboid;
	proj_on_axis = vect3d_dot(point - cuboid->pos, cuboid->basis.x);
	if (fabs(proj_on_axis - cuboid->half_sides[SIDE_X]) < 1e-1)
		return (rect_get_normal(&cuboid->faces[FACE_NEAR], point));
	if (fabs(proj_on_axis - -cuboid->half_sides[SIDE_X]) < 1e-1)
		return (rect_get_normal(&cuboid->faces[FACE_FAR], point));
	proj_on_axis = vect3d_dot(point - cuboid->pos, cuboid->basis.y);
	if (fabs(proj_on_axis - cuboid->half_sides[SIDE_Y]) < 1e-1)
		return (rect_get_normal(&cuboid->faces[FACE_RIGHT], point));
	if (fabs(proj_on_axis - -cuboid->half_sides[SIDE_Y]) < 1e-1)
		return (rect_get_normal(&cuboid->faces[FACE_LEFT], point));
	proj_on_axis = vect3d_dot(point - cuboid->pos, cuboid->basis.z);
	if (fabs(proj_on_axis - cuboid->half_sides[SIDE_Z]) < 1e-1)
		return (rect_get_normal(&cuboid->faces[FACE_TOP], point));
	if (fabs(proj_on_axis - -cuboid->half_sides[SIDE_Z]) < 1e-1)
		return (rect_get_normal(&cuboid->faces[FACE_BOT], point));
	else
	{
		printf("fail in %s\n", __FILE__);
		exit(1);
		return (vect3d(1, 0, 0));
	}
}

t_cuboid	*cuboid_new(t_vect3d pos, t_basis basis, double half_sides[3])
{
	t_cuboid	*cuboid;
	t_rect		rect;

	if (!(cuboid = malloc(sizeof(t_cuboid))))
		return (NULL);
	cuboid->pos = pos;
	cuboid->basis = basis;
	ft_memcpy(cuboid->half_sides, half_sides, sizeof(double) * 3);
	rect = (t_rect){- vect3d_mult_on_scalar(basis.z, half_sides[SIDE_Z]),
		basis, {half_sides[SIDE_X], half_sides[SIDE_Y]}};
	cuboid->faces[FACE_BOT] = rect;
	rect = (t_rect){vect3d_mult_on_scalar(basis.z, half_sides[SIDE_Z]),
		basis, {half_sides[SIDE_X], half_sides[SIDE_Y]}};
	cuboid->faces[FACE_TOP] = rect;
	rect = (t_rect){- vect3d_mult_on_scalar(basis.y, half_sides[SIDE_Y]),
		(t_basis){basis.z, -basis.x, -basis.y},
		{half_sides[SIDE_Z], half_sides[SIDE_X]}};
	cuboid->faces[FACE_LEFT] = rect;
	rect = (t_rect){vect3d_mult_on_scalar(basis.y, half_sides[SIDE_Y]),
		(t_basis){basis.z, basis.x, basis.y},
		{half_sides[SIDE_Z], half_sides[SIDE_X]}};
	cuboid->faces[FACE_RIGHT] = rect;
	rect = (t_rect){- vect3d_mult_on_scalar(basis.x, half_sides[SIDE_X]),
		(t_basis){basis.z, basis.y, -basis.x},
		{half_sides[SIDE_Z], half_sides[SIDE_Y]}};
	cuboid->faces[FACE_FAR] = rect;
	rect = (t_rect){vect3d_mult_on_scalar(basis.x, half_sides[SIDE_X]),
		(t_basis){-basis.z, basis.y, basis.x},
		{half_sides[SIDE_Z], half_sides[SIDE_Y]}};
	cuboid->faces[FACE_NEAR] = rect;
	return (cuboid);
}
