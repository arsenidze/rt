/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 20:37:49 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/30 20:43:14 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISC_H
# define DISC_H

# include "vect3d.h"

typedef struct	s_disc
{
	t_vect3d	pos;
	t_vect3d	normal;
	double		r;
	double		r2;
}				t_disc;

t_disc			*disc_new(t_vect3d pos, t_vect3d normal, double r);
void			disc_delete(void *disc);
short			disc_intersection(void *disc, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		disc_get_normal(void *disc, t_vect3d point);

#endif
