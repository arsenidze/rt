/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 12:36:45 by amelihov         ###   ########.fr       */
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

#define FACE_TOP	0
#define FACE_BOTTOM	1
#define FACE_RIGHT	2
#define FACE_LEFT	3
#define FACE_NEAR	4
#define FACE_FAR	5

static void		cuboid_init_faces(t_cuboid cuboid, t_basis basis,
				t_rect rects[6], t_basis rects_basis[6])
{
	rects[FACE_TOP].half_sides[SIDE_X] = cuboid.half_sides[SIDE_X];
	rects[FACE_TOP].half_sides[SIDE_Y] = cuboid.half_sides[SIDE_Y];
	rects[FACE_BOTTOM] = rects[FACE_TOP];
	rects[FACE_RIGHT].half_sides[SIDE_X] = cuboid.half_sides[SIDE_Z];
	rects[FACE_RIGHT].half_sides[SIDE_Y] = cuboid.half_sides[SIDE_X];
	rects[FACE_LEFT] = rects[FACE_RIGHT];
	rects[FACE_NEAR].half_sides[SIDE_X] = cuboid.half_sides[SIDE_Z];
	rects[FACE_NEAR].half_sides[SIDE_Y] = cuboid.half_sides[SIDE_Y];
	rects[FACE_FAR] = rects[FACE_NEAR];
	rects_basis[FACE_TOP] = basis;
	rects_basis[FACE_BOTTOM] = (t_basis){-basis.x, basis.y, -basis.z};
	rects_basis[FACE_RIGHT] = (t_basis){-basis.z, -basis.x, basis.y};
	rects_basis[FACE_LEFT] = (t_basis){-basis.z, basis.x, -basis.y};
	rects_basis[FACE_NEAR] = (t_basis){-basis.z, basis.y, basis.x};
	rects_basis[FACE_FAR] = (t_basis){-basis.z, -basis.y, -basis.x};
}

static t_vect3d	cuboid_find_closest_intersection(t_rect rects[6],
				t_basis rects_basis[6], t_ray ray, t_vect3d positions[6])
{
	t_ray		shifted_ray;
	t_vect3d	min_isect;
	t_vect3d	curr_isect;
	int			i;

	shifted_ray = ray;
	min_isect = vect3d(INF, INF, INF);
	i = 0;
	while (i < 6)
	{
		shifted_ray.o = ray.o - positions[i];
		if (rect_intersection(PRIMITIVE_AS(rect, rects[i]),
			rects_basis[i], shifted_ray, &curr_isect))
		{
			curr_isect += positions[i];
			if (vect3d_sq_len(min_isect - ray.o)
				> vect3d_sq_len(curr_isect - ray.o))
			{
				min_isect = curr_isect;
			}
		}
		i++;
	}
	return (min_isect);
}

#define EPS 0.001

short			cuboid_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	t_basis		rect_basis[6];
	t_vect3d	positions[6];
	t_rect		rects[6];
	t_vect3d	min_isect;

	cuboid_init_faces(primitive.cuboid, basis, rects, rect_basis);
	positions[0] =
		vect3d_mult_on_scalar(basis.z, primitive.cuboid.half_sides[SIDE_Z]);
	positions[1] =
		vect3d_mult_on_scalar(basis.z, -primitive.cuboid.half_sides[SIDE_Z]);
	positions[2] =
		vect3d_mult_on_scalar(basis.y, primitive.cuboid.half_sides[SIDE_Y]);
	positions[3] =
		vect3d_mult_on_scalar(basis.y, -primitive.cuboid.half_sides[SIDE_Y]);
	positions[4] =
		vect3d_mult_on_scalar(basis.x, primitive.cuboid.half_sides[SIDE_X]);
	positions[5] =
		vect3d_mult_on_scalar(basis.x, -primitive.cuboid.half_sides[SIDE_X]);
	min_isect = cuboid_find_closest_intersection(rects, rect_basis, ray,
		positions);
	if (vect3d_is_equal(min_isect, vect3d(INF, INF, INF)))
		return (0);
	*intersect_point = min_isect;
	return (1);
}

#define DELTA		1e-2
#define DELTA_SQ	(DELTA * DELTA)

t_vect3d		cuboid_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d pnt)
{
	t_rect		rects[6];
	t_basis		r_basis[6];
	double		proj_on_axis;

	cuboid_init_faces(primitive.cuboid, basis, rects, r_basis);
	proj_on_axis = vect3d_dot(pnt, basis.z);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_Z]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rects[0]), r_basis[0], pnt));
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_Z]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rects[1]), r_basis[1], pnt));
	proj_on_axis = vect3d_dot(pnt, basis.y);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_Y]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rects[2]), r_basis[2], pnt));
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_Y]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rects[3]), r_basis[3], pnt));
	proj_on_axis = vect3d_dot(pnt, basis.x);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_X]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rects[4]), r_basis[4], pnt));
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_X]) < DELTA_SQ)
		return (rect_get_normal(PRIMITIVE_AS(rect, rects[5]), r_basis[5], pnt));
	return (vect3d(0, 0, 0));
}

/*
**	r -> rectangels
**	r_b -> rectangels basis
**	crd -> coordinates
*/

void			cuboid_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d pnt, float crd[2])
{
	t_rect		r[6];
	t_basis		r_b[6];
	double		proj_on_axis;

	cuboid_init_faces(primitive.cuboid, basis, r, r_b);
	proj_on_axis = vect3d_dot(pnt, basis.z);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_Z]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r[0]), r_b[0], pnt, crd));
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_Z]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r[1]), r_b[1], pnt, crd));
	proj_on_axis = vect3d_dot(pnt, basis.y);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_Y]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r[2]), r_b[2], pnt, crd));
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_Y]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r[3]), r_b[3], pnt, crd));
	proj_on_axis = vect3d_dot(pnt, basis.x);
	if (square(proj_on_axis - primitive.cuboid.half_sides[SIDE_X]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r[4]), r_b[4], pnt, crd));
	if (square(proj_on_axis - -primitive.cuboid.half_sides[SIDE_X]) < DELTA_SQ)
		return (rect_get_tex_coord(PRIMITIVE_AS(rect, r[5]), r_b[5], pnt, crd));
	crd[0] = 0;
	crd[1] = 0;
}
