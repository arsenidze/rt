/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/11 17:37:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"
#include "primitive.h"
#include "mmath.h"
#include <math.h>

t_disk			disk_create(double r)
{
	t_disk	disk;

	disk.r = r;
	disk.r2 = r * r;
	return (disk);
}

#define EPS 0.001

short			disk_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point)
{
	double		cos_between_ray_and_normal;
	double		t;

	cos_between_ray_and_normal = vect3d_dot(ray.d, basis.z);
	if (cos_between_ray_and_normal == 0)
		return (0);
	t = -vect3d_dot(ray.o, basis.z) / cos_between_ray_and_normal;
	if (t <= 0)
		return (0);
	*intersect_point = ray.o + vect3d_mult_on_scalar(ray.d, t - EPS);
	if (vect3d_sq_len(*intersect_point) <= primitive.disk.r2)
		return (1);
	else
		return (0);
}

t_vect3d		disk_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point)
{
	(void)primitive;
	(void)point;
	return (basis.z);
}

void			disk_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2])
{
	(void)primitive;
	point = basis_get_coord_in_basis(basis, point);
	coord[0] = 0.5 * point[Y] / primitive.disk.r + 0.5;
	coord[1] = 0.5 * point[X] / primitive.disk.r + 0.5;
}
