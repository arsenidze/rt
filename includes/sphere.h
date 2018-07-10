/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/14 19:20:27 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vect3d.h"

typedef struct	s_sphere
{
	t_vect3d	pos;
	double		radius;
}				t_sphere;

t_sphere		*sphere_new(t_vect3d pos, double radius);
void			sphere_delete(void *sphere);
short			sphere_intersection(void *sphere, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		sphere_get_normal(void *sphere, t_vect3d point);

#endif
