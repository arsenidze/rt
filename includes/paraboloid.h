/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/04 16:29:41 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_H
# define PARABOLOID_H

# include "vect3d.h"

typedef struct	s_paraboloid
{
	t_vect3d	pos;
	t_vect3d	axis;
	double		k;
}				t_paraboloid;

t_paraboloid	*paraboloid_new(t_vect3d pos, t_vect3d axis, double k);
void			paraboloid_delete(void *paraboloid);
short			paraboloid_intersection(void *paraboloid, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		paraboloid_get_normal(void *paraboloid, t_vect3d point);
void			paraboloid_get_tex_coord(void *paraboloid, t_vect3d point,
				float coord[2]);

#endif
