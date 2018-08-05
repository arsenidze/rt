/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/01 16:16:56 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBOID_H
# define CUBOID_H

# include "vect3d.h"
# include "basis.h"
# include "rect.h"

typedef struct	s_cuboid
{
	t_vect3d	pos;
	t_basis		basis;
	double		half_sides[3];
	t_rect		faces[6];
}				t_cuboid;

t_cuboid		*cuboid_new(t_vect3d pos, t_basis basis, double sides[3]);
void			cuboid_delete(void *cuboid);
short			cuboid_intersection(void *cuboid, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		cuboid_get_normal(void *cuboid, t_vect3d point);

#endif
