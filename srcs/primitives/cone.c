/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:09:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 20:56:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "mmath.h"
#include "disc.h"
#include "equation.h"
#include <stdlib.h>

typedef struct	s_ray
{
	t_vect3d	o;
	t_vect3d	d;
}				t_ray;

#define EPS 0.001
#include <stdio.h>
static short	cone_cap_intersect(t_cone *cone, t_ray ray,
				t_equation eq, t_vect3d *intersect_point)
{
	double	proj_on_axis;
	
	proj_on_axis = vect3d_dot(*intersect_point - cone->pos, cone->axis);
	if (proj_on_axis <= 0.0)
	{
		if (!equation_step_to_next_pos_root(&eq))
			return (0);
		*intersect_point = ray.o
			+ vect3d_mult_on_scalar(ray.d, equation_get_pos_root(eq) - EPS);
		proj_on_axis = vect3d_dot(*intersect_point - cone->pos, cone->axis);
		if (proj_on_axis <= 0.0)
			return (0);
	}
	if (proj_on_axis >= cone->h)	 
		return (disc_intersection(&(t_disc){cone->pos
					+ vect3d_mult_on_scalar(cone->axis, cone->h),
							cone->axis, cone->r, cone->r2},
							ray.o, ray.d, intersect_point));
	else
		return (1);
}

static void	fill_cone_coefficients(t_cone *cone, t_ray ray, double *coeffs)
{
	t_vect3d	x;
	t_vect3d	v;

	x = ray.o - cone->pos;
	v = cone->axis;
	coeffs[0] = vect3d_dot(ray.d, ray.d)
					- square(vect3d_dot(ray.d, v))
					* (1 + cone->k * cone->k);
	coeffs[1] = vect3d_dot(ray.d, x)
					- vect3d_dot(ray.d, v) * vect3d_dot(x, v)
					* (1 + cone->k * cone->k);
	coeffs[2] = vect3d_dot(x, x)
					- square(vect3d_dot(x, v))
					* (1 + cone->k * cone->k);
}
#include <stdio.h>
short		cone_intersection(void *v_cone, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_cone		*cone;
	double		coefficients[3];
	double		roots[2];
	t_equation	eq;

	t_ray		ray = (t_ray){start, ray_dir};

	cone = (t_cone *)v_cone;
	eq.degree = 2;
	eq.roots = roots;
	eq.coeffs = coefficients;
	fill_cone_coefficients(cone, ray, eq.coeffs);
	eq.coeffs[1] *= 2;
	solve2(eq.coeffs, eq.roots);
	equation_set_pos_root(&eq);
	if (equation_get_pos_root(eq) < 0.0)
		return (0);
	*intersect_point = ray.o
			+ vect3d_mult_on_scalar(ray.d, equation_get_pos_root(eq) - EPS);
	if (cone->h < 0.0)
		return (1);
	else
		return (cone_cap_intersect(cone, ray, eq, intersect_point));
}

void		cone_delete(void *cone)
{
	free(cone);
}

t_vect3d	cone_get_normal(void *v_cone, t_vect3d point)
{
	t_cone		*cone;
	t_vect3d	v;
	t_vect3d	c;
	double		m;
	t_vect3d	normal;
	double		proj_on_axis;

	cone = (t_cone *)v_cone;
	proj_on_axis = vect3d_dot(point - cone->pos, cone->axis);
	if (proj_on_axis >= cone->h)
		return (disc_get_normal(&(t_disc){cone->pos,
							cone->axis, cone->r, cone->r2},
							point));
	v = cone->axis;
	c = cone->pos;
	m = (vect3d_dot(v, point) - vect3d_dot(v, c)) / vect3d_dot(v, v);
	normal = point
			- (c + vect3d_mult_on_scalar(v, m * (1 + cone->k * cone->k)));
	normal = vect3d_norm(normal);
	return (normal);
}

t_cone		*cone_new(t_vect3d pos, t_vect3d axis, double k)
{
	t_cone	*cone;

	if (!(cone = malloc(sizeof(t_cone))))
		return (NULL);
	cone->pos = pos;
	cone->axis = axis;
	cone->k = k;

	cone->h = 100.0;

	cone->r = k * cone->h;
	cone->r2 = cone->r * cone->r;
	return (cone);
}
