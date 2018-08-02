/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:10:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/02 17:53:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vect3d.h"
# include "basis.h"

typedef struct	s_cylinder
{
	t_vect3d	pos;
	t_basis		basis;
	t_vect3d	axis;
	double		r;
	double		r2;
	double		h;
}				t_cylinder;

t_cylinder		*cylinder_new(t_vect3d pos, t_vect3d axis, double radius);
void			cylinder_delete(void *cylinder);
short			cylinder_intersection(void *cylinder, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		cylinder_get_normal(void *cylinder, t_vect3d point);
void			cylinder_get_tex_coord(void *cylinder, t_vect3d point,
				float coord[2]);

#endif
