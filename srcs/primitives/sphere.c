/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:11:07 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "mmath.h"
#include <stdlib.h>

#define EPS 0.001

short		sphere_intersection(void *v_sphere, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_sphere	*sphere;
	double		coefficients[3];
	double		t;

	sphere = (t_sphere *)v_sphere;
	coefficients[0] = vect3d_dot(ray_dir, ray_dir);
	coefficients[1] = vect3d_dot(start, ray_dir)
						- vect3d_dot(sphere->pos, ray_dir);
	coefficients[2] = vect3d_dot(start, start)
						- 2 * vect3d_dot(start, sphere->pos)
						+ vect3d_dot(sphere->pos, sphere->pos)
						- (sphere->radius * sphere->radius);
	t = get_positive_root(coefficients);
	if (t < 0)
		return (0);
	if (intersect_point)
		*intersect_point = start + vect3d_mult_on_scalar(ray_dir, t - EPS);
	return (1);
}

void		sphere_delete(void *sphere)
{
	free(sphere);
}

t_vect3d	sphere_get_normal(void *v_sphere, t_vect3d point)
{
	t_sphere	*sphere;
	t_vect3d	normal;

	sphere = (t_sphere *)v_sphere;
	normal = point - sphere->pos;
	normal = vect3d_norm(normal);
	return (normal);
}

t_sphere	*sphere_new(t_vect3d pos, double radius)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->pos = pos;
	sphere->radius = radius;
	return (sphere);
}
