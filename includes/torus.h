/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:36:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/15 15:39:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TORUS_H
# define TORUS_H

# include "vect3d.h"

typedef struct	s_torus
{
	t_vect3d	pos;
	t_vect3d	axis;
	double		r0;
	double		r1;
}				t_torus;

t_torus			*torus_new(t_vect3d pos, double axis, double r0, double r1);
void			torus_delete(void *torus);
short			torus_intersection(void *torus, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		torus_get_normal(void *torus, t_vect3d point);

#endif
