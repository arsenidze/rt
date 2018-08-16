/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/13 14:55:15 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuboid.h"
#include "primitive.h"
#include "rect.h"
#include "mmath.h"
#include <math.h>

#define SIDE_X	0
#define SIDE_Y	1
#define SIDE_Z	2

t_cuboid		cuboid_create(double sides[3])
{
	t_cuboid	cuboid;

	cuboid.half_sides[SIDE_X] = sides[SIDE_X] / 2.0;
	cuboid.half_sides[SIDE_Y] = sides[SIDE_Y] / 2.0;
	cuboid.half_sides[SIDE_Z] = sides[SIDE_Z] / 2.0;
	return (cuboid);
}

#define EPS 0.001

short			cuboid_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	t_basis		rect_basis[6];
	t_vect3d	p[6];
	t_rect		rects[6];
	int			i;
	t_ray		shifted_ray;
	int			is_isect;
	t_vect3d	min_isect;

	rects[0].half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_X];
	rects[0].half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_Y];
	p[0] = vect3d_mult_on_scalar(basis.z, primitive.cuboid.half_sides[SIDE_Z]);
	rect_basis[0] = basis;

	rects[1] = rects[0];
	p[1] = vect3d_mult_on_scalar(basis.z, -primitive.cuboid.half_sides[SIDE_Z]);
	rect_basis[1] = basis;

	rects[2].half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_Z];
	rects[2].half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_X];
	p[2] = vect3d_mult_on_scalar(basis.y, primitive.cuboid.half_sides[SIDE_Y]);
	rect_basis[2] = (t_basis){-basis.z, -basis.x, basis.y};

	rects[3] = rects[2];
	p[3] = vect3d_mult_on_scalar(basis.y, -primitive.cuboid.half_sides[SIDE_Y]);
	rect_basis[3] = rect_basis[2];

	rects[4].half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_Z];
	rects[4].half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_Y];
	p[4] = vect3d_mult_on_scalar(basis.x, primitive.cuboid.half_sides[SIDE_X]);
	rect_basis[4] = (t_basis){-basis.z, basis.y, basis.x};
	
	rects[5] = rects[4];
	p[5] = vect3d_mult_on_scalar(basis.x, -primitive.cuboid.half_sides[SIDE_X]);
	rect_basis[5] = rect_basis[4];
	
	shifted_ray = ray;
	min_isect = vect3d(INF, INF, INF);	
	is_isect = 0;
	i = 0;
	while (i < 6)
	{
		shifted_ray.o = ray.o - p[i];
		if (rect_intersection(PRIMITIVE_AS(rect, rects[i]),
			rect_basis[i], shifted_ray, intersect_point))
		{
			*intersect_point += p[i];
			if (vect3d_sq_len(min_isect - ray.o)
				> vect3d_sq_len(*intersect_point - ray.o))
			{
				min_isect = *intersect_point;
				is_isect = 1;
			}
		}
		i++;
	}
	*intersect_point = min_isect;
	return (is_isect);
}
#include <stdio.h>
#include <stdlib.h>

#define DELTA		1e-2
#define DELTA_SQ	(DELTA * DELTA)	

t_vect3d		cuboid_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	double		proj_on_axis;
	t_rect		rect;
	t_basis		r_basis;

	rect.half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_X];
	rect.half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_Y];
	r_basis = basis;
	proj_on_axis = vect3d_dot(point, basis.z);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_Z]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rect), r_basis, point));
	r_basis = (t_basis){-basis.x, basis.y, -basis.z};
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_Z]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rect), r_basis, point));
	rect.half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_Z];
	rect.half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_X];
	r_basis = (t_basis){-basis.z, -basis.x, basis.y};
	proj_on_axis = vect3d_dot(point, basis.y);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_Y]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rect), r_basis, point));
	r_basis = (t_basis){-basis.z, basis.x, -basis.y};
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_Y]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rect), r_basis, point));
	rect.half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_Z];
	rect.half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_Y];
	r_basis = (t_basis){-basis.z, basis.y, basis.x};
	proj_on_axis = vect3d_dot(point, basis.x);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_X]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rect), r_basis, point));
	r_basis = (t_basis){-basis.z, -basis.y, -basis.x};
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_X]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rect), r_basis, point));
	printf("cuboid normal\n");
	exit(1);
	return (vect3d(0, 0, 0));
}

void			cuboid_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d pnt, float coord[2])
{
	double		proj_on_axis;
	t_rect		r;
	t_basis		r_basis;

	r.half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_X];
	r.half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_Y];
	r_basis = basis;
	proj_on_axis = vect3d_dot(pnt, basis.z);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_Z]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r), r_basis, pnt, coord));
	r_basis = (t_basis){-basis.x, basis.y, -basis.z};
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_Z]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r), r_basis, pnt, coord));
	r.half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_Z];
	r.half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_X];
	r_basis = (t_basis){-basis.z, -basis.x, basis.y};
	proj_on_axis = vect3d_dot(pnt, basis.y);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_Y]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r), r_basis, pnt, coord));
	r_basis = (t_basis){-basis.z, basis.x, -basis.y};
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_Y]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r), r_basis, pnt, coord));
	r.half_sides[SIDE_X] = primitive.cuboid.half_sides[SIDE_Z];
	r.half_sides[SIDE_Y] = primitive.cuboid.half_sides[SIDE_Y];
	r_basis = (t_basis){-basis.z, basis.y, basis.x};
	proj_on_axis = vect3d_dot(pnt, basis.x);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_X]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r), r_basis, pnt, coord));
	r_basis = (t_basis){-basis.z, -basis.y, -basis.x};
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_X]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r), r_basis, pnt, coord));
	printf("cuboid tex_coord\n");
	exit(1);
}
