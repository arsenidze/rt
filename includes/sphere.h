/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/04 16:32:22 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vect3d.h"
# include "basis.h"

typedef struct	s_sphere
{
	t_vect3d	pos;
	t_basis		basis;
	double		radius;
	double		h;
}				t_sphere;

t_sphere		*sphere_new(t_vect3d pos, double radius);
void			sphere_delete(void *sphere);
short			sphere_intersection(void *sphere, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
t_vect3d		sphere_get_normal(void *sphere, t_vect3d point);
void			sphere_get_tex_coord(void *sphere, t_vect3d point,
				float coord[2]);

#endif
