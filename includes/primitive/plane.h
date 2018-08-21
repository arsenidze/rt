/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 19:50:58 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "ray.h"
# include "vect3d.h"
# include "basis.h"

typedef union u_primitive	t_primitive;

typedef struct	s_plane
{
	double	tex_scale;
}				t_plane;

t_plane			plane_create(void);
short			plane_intersection(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point);
t_vect3d		plane_get_normal(t_primitive primitive, t_basis basis,
				t_vect3d point);
void			plane_get_tex_coord(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2]);

#endif
