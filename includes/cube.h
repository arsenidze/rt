/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 22:11:12 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "vect3d.h"
# include "plane.h"

typedef struct	s_cube
{
	t_vect3d	pos;
	double		a;
	t_vect3d	axis;
	t_plane		faces[6];
	int			index_closest_face;
}				t_cube;

t_cube			*cube_new(t_vect3d pos, double a, t_vect3d axis);
void			cube_delete(void *cube);
short			cube_intersection(void *cube, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		cube_get_normal(void *cube, t_vect3d point);

#endif
