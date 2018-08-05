/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/01 14:52:51 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
# define RECT_H

# include "vect3d.h"
# include "basis.h"

typedef struct	s_rect
{
	t_vect3d	pos;
	t_basis		basis;
	double		half_sides[2];
}				t_rect;

t_rect			*rect_new(t_vect3d pos, t_basis basis, double half_sides[2]);
void			rect_delete(void *rect);
short			rect_intersection(void *rect, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		rect_get_normal(void *rect, t_vect3d point);

#endif
