/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 22:47:53 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
# define RECT_H

# include "vect3d.h"

typedef struct	s_rect
{
	t_vect3d	pos;
	t_vect3d	normal;
	double		w;
	double		h;
	t_vect3d	u;
	t_vect3d	v;
}				t_rect;

t_rect			*rect_new(t_vect3d pos, t_vect3 normal, t_vect3d u,
				t_vect3d v, double w, double h);
void			rect_delete(void *rect);
short			rect_intersection(void *rect, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		rect_get_normal(void *rect, t_vect3d point);

#endif
