/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/12 17:22:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBOID_H
# define CUBOID_H

# include "rect.h"
# include "ray.h"
# include "vect3d.h"
# include "basis.h"

typedef union u_primitive	t_primitive;

typedef struct	s_cuboid
{
	double		half_sides[3];
}				t_cuboid;

t_cuboid		cuboid_create(double sides[3]);
short			cuboid_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point);
t_vect3d		cuboid_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point);
void			cuboid_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2]);

#endif
