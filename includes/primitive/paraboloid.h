/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/11 20:24:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_H
# define PARABOLOID_H

# include "ray.h"
# include "vect3d.h"
# include "basis.h"

typedef union u_primitive	t_primitive;

typedef struct	s_paraboloid
{
	double		k;
	double		h;
}				t_paraboloid;

t_paraboloid	paraboloid_create(double k, double h);
short			paraboloid_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point);
t_vect3d		paraboloid_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point);
void			paraboloid_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2]);

#endif
