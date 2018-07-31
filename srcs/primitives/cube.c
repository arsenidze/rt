/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 22:19:59 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mmath.h"
#include "plane.h"
#include <stdlib.h>

#define FACE_TOP	0
#define FACE_BOT	1
#define FACE_LEFT	2
#define FACE_RIGHT	3
#define FACE_FAR	4
#define FACE_NEAR	5

#define EPS 0.001

short		cube_intersection(void *v_cube, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_cube		*cube;
	int			i;
	t_vect3d	tmp_isect_pnt;
	t_vect3d	closest_isect;

	cube = (t_cube *)v_cube;
	closest_isect = vect3d(INF, INF, INF);
	cube->index_closest_face = -1;
	i = 0;
	while (i < 6)
	{
		if (plane_intersection(&cube->faces[i], start, ray_dir, &tmp_isect_pnt))
		{
			if (vect3d_sq_len(closest_isect - start)
				> vect3d_sq_len(tmp_isect_pnt - start))
			{
				closest_isect = tmp_isect_pnt;
				cube->index_closest_face = i;
			}
		}
		i++;
	}
	if (cube->index_closest_face > 0)
	{
		*intersect_point = closest_isect;
		return (1);
	}
	else
		return (0);
}

void		cube_delete(void *cube)
{
	free(cube);
}
#include <stdio.h>
#include <stdlib.h>
t_vect3d	cube_get_normal(void *v_cube, t_vect3d point)
{
	t_cube		*cube;

	(void)point;
	cube = (t_cube *)v_cube;
	if (cube->index_closest_face < 0)
	{
		printf("fail in %s\n", __FILE__);
		exit(1);
		return (vect3d(1, 0, 0));
	}
	return (plane_get_normal(&cube->faces[cube->index_closest_face], point));
}

t_cube			*cube_new(t_vect3d pos, double a, t_vect3d axis)
{
	t_cube	*cube;

	if (!(cube = malloc(sizeof(t_cube))))
		return (NULL);
	cube->pos = pos;
	cube->a = a;
	cube->axis = axis;
	cube->faces[FACE_BOT].pos = pos;
	cube->faces[FACE_BOT].normal = -axis;
	cube->faces[FACE_TOP].pos = pos + vect3d_mult_on_scalar(axis, a);
	cube->faces[FACE_TOP].normal = axis;
	cube->faces[FACE_LEFT].pos = pos;
	cube->faces[FACE_LEFT].normal = vect3d(0, -1, 0);
	cube->faces[FACE_RIGHT].pos = pos + vect3d(0, a, 0);
	cube->faces[FACE_RIGHT].normal = vect3d(0, 1, 0);
	cube->faces[FACE_FAR].pos = pos;
	cube->faces[FACE_FAR].normal = vect3d(-1, 0, 0);
	cube->faces[FACE_NEAR].pos = pos + vect3d(a, 0, 0);
	cube->faces[FACE_NEAR].normal = vect3d(1, 0, 0);
	cube->index_closest_face = -1;
	return (cube);
}
