/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/11 17:47:20 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"
#include "primitive.h"
#include "mmath.h"

#define SIDE_X	0
#define SIDE_Y	1

t_rect			rect_create(double sides[2])
{
	t_rect	rect;

	rect.half_sides[SIDE_X] = sides[SIDE_X] / 2.0;
	rect.half_sides[SIDE_Y] = sides[SIDE_Y] / 2.0;
	return (rect);
}

#define EPS 0.001

short			rect_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		cos_between_ray_and_normal;
	double		t;
	double		proj_on_axis;

	cos_between_ray_and_normal = vect3d_dot(ray.d, basis.z);
	if (cos_between_ray_and_normal == 0)
		return (0);
	t = -vect3d_dot(ray.o, basis.z) / cos_between_ray_and_normal;
	if (t <= 0)
		return (0);
	*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, t - EPS);
	proj_on_axis = vect3d_dot(basis.y, *intersect_point);
	if (proj_on_axis > primitive.rect.half_sides[SIDE_Y]
		|| proj_on_axis < -primitive.rect.half_sides[SIDE_Y])
		return (0);
	proj_on_axis = vect3d_dot(basis.x, *intersect_point);
	if (proj_on_axis > primitive.rect.half_sides[SIDE_X]
		|| proj_on_axis < -primitive.rect.half_sides[SIDE_X])
		return (0);
	return (1);
}

t_vect3d		rect_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	(void)primitive;
	(void)point;
	return (basis.z);
}

void			rect_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2])
{
	(void)primitive;
	point = basis_get_coord_in_basis(basis, point);
	coord[0] = 0.5 * point[Y] / primitive.rect.half_sides[SIDE_Y] + 0.5;
	coord[1] = 0.5 * point[X] / primitive.rect.half_sides[SIDE_X] + 0.5;
}
