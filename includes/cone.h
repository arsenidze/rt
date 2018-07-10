/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 22:05:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "vect3d.h"

typedef struct	s_cone
{
	t_vect3d	pos;
	t_vect3d	axis;
	double		k;
	double		radius;
}				t_cone;

t_cone			*cone_new(t_vect3d pos, t_vect3d axis, double k);
void			cone_delete(void *cone);
short			cone_intersection(void *cone, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		cone_get_normal(void *cone, t_vect3d point);

#endif
