/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composed.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/27 21:27:05 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPOSED_H
# define COMPOSED_H

# include "vect3d.h"
# include "object.h"

typedef struct	s_composed
{
	t_vect3d	pos;
	t_object	**parts;
	int			n;
	int			closest_part_index;
}				t_composed;

t_composed				*composed_new(t_vect3d pos, t_object **parts, int n);
void					composed_delete(void *composed);
short					composed_intersection(void *composed, t_vect3d start,
						t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d				composed_get_normal(void *composed, t_vect3d point);

#endif
