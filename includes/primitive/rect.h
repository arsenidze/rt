/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/11 17:46:51 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
# define RECT_H

# include "ray.h"
# include "vect3d.h"
# include "basis.h"

typedef union u_primitive	t_primitive;

typedef struct	s_rect
{
	double		half_sides[2];
}				t_rect;

t_rect			rect_create(double sides[2]);
short			rect_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point);
t_vect3d		rect_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point);
void			rect_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2]);

#endif
