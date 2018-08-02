/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:13:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/02 18:07:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "mmath.h"
#include "disc.h"
#include "basis.h"
#include <stdlib.h>
#include <math.h>

static short	cylinder_cap_intersect(t_cylinder *cylinder, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	double	proj_on_axis;
	
	proj_on_axis = vect3d_dot(*intersect_point - cylinder->pos, cylinder->axis);
	if (proj_on_axis <= 0.0)
		return (disc_intersection(&(t_disc){cylinder->pos,
							cylinder->axis, cylinder->r, cylinder->r2},
							start, ray_dir, intersect_point));
	else if (proj_on_axis >= cylinder->h)	 
		return (disc_intersection(&(t_disc){cylinder->pos
					+ vect3d_mult_on_scalar(cylinder->axis, cylinder->h),
							cylinder->axis, cylinder->r, cylinder->r2},
							start, ray_dir, intersect_point));
	else
		return (1);
}

#define EPS 0.001

short		cylinder_intersection(void *v_cylinder, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_cylinder	*cylinder;
	t_vect3d	x;
	double		coefficients[3];
	double		t;

	cylinder = (t_cylinder *)v_cylinder;
	x = start - cylinder->pos;
	coefficients[0] = vect3d_dot(ray_dir, ray_dir)
					- square(vect3d_dot(ray_dir, cylinder->axis));
	coefficients[1] = vect3d_dot(ray_dir, x)
					- vect3d_dot(ray_dir, cylinder->axis)
					* vect3d_dot(x, cylinder->axis);
	coefficients[2] = vect3d_dot(x, x)
					- square(vect3d_dot(x, cylinder->axis))
					- cylinder->r2;
	t = get_positive_root(coefficients);
	if (t < 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	if (cylinder->h < 0.0)
		return (1);
	else
		return (cylinder_cap_intersect(cylinder, start, ray_dir,
										intersect_point));
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
	double		proj_on_axis;

	cylinder = (t_cylinder *)v_cylinder;
	proj_on_axis = vect3d_dot(point - cylinder->pos, cylinder->axis);
	if (proj_on_axis <= 0.0)
		return (disc_get_normal(&(t_disc){cylinder->pos,
							cylinder->axis, cylinder->r, cylinder->r2},
							point));
	else if (proj_on_axis >= cylinder->h)	 
		return (disc_get_normal(&(t_disc){cylinder->pos
					+ vect3d_mult_on_scalar(cylinder->axis, cylinder->h),
							cylinder->axis, cylinder->r, cylinder->r2},
							point));
	v = cylinder->axis;
	c = cylinder->pos;
	m = (vect3d_dot(v, point) - vect3d_dot(v, c)) / vect3d_dot(v, v);
	normal = point - (c + vect3d_mult_on_scalar(v, m));
	normal = vect3d_norm(normal);
	return (normal);
}

t_vect3d		change_basis(t_basis basis, t_vect3d point)
{
	t_vect3d	new_point;

	new_point[X] = vect3d_dot(basis.x, point);
	new_point[Y] = vect3d_dot(basis.y, point);
	new_point[Z] = vect3d_dot(basis.z, point);
	return (new_point);
}
#include <stdio.h>
void			cylinder_get_tex_coord(void *v_cylinder, t_vect3d point,
				float coord[2])
{
	
	t_cylinder	*cylinder;
	double		phi;
	//double		r;

	cylinder = (t_cylinder *)v_cylinder;
	point = change_basis(cylinder->basis, point - cylinder->pos);
	//r = sqrt(square(point[X]) + square(point[Y]));
	phi = atan(point[Y] / point[X]);
	coord[X] = phi / (2.0 * M_PI);
	coord[Y] = point[Z] / cylinder->h;
	printf("%f %f\n", coord[X], coord[Y]);
	vect3d_print(point);
	printf("\n");
//	coord[X] = 0;
//	coord[Y] = 0;
}

t_cylinder	*cylinder_new(t_vect3d pos, t_vect3d axis, double radius)
{
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		return (NULL);
	cylinder->pos = pos;
	cylinder->axis = axis;
	cylinder->r = radius;
	cylinder->r2 = radius * radius;
	cylinder->h = 50.0;

	cylinder->basis.x = vect3d(1, 0, 0);
	cylinder->basis.y = vect3d(0, 1, 0);
	cylinder->basis.z = axis;


	return (cylinder);
}
