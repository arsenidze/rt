/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/04 16:39:03 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vect3d.h"
# include "basis.h"

typedef struct	s_plane
{
	t_vect3d	pos;
	t_basis		basis;
	t_vect3d	normal;
}				t_plane;

t_plane			*plane_new(t_vect3d pos, t_vect3d normal);
void			plane_delete(void *plane);
short			plane_intersection(void *plane, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		plane_get_normal(void *plane, t_vect3d point);
void			plane_get_tex_coord(void *plane, t_vect3d point,
				float coord[2]);

#endif
