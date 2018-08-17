/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/10 14:56:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "ray.h"
# include "vect3d.h"
# include "basis.h"

typedef union u_primitive	t_primitive;

typedef struct	s_cylinder
{
	double		r;
	double		r2;
	double		h;
}				t_cylinder;

t_cylinder		cylinder_create(double r, double h);
short			cylinder_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point);
t_vect3d		cylinder_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point);
void			cylinder_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2]);

#endif
