/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:43:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/05 20:12:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "object.h"
# include "vect3d.h"

typedef struct	s_sphere
{
	double		radius;
	double		h;
}				t_sphere;

short			sphere_intersection(t_object *object, t_ray ray,
				t_vect3d *intersect_point);
t_vect3d		sphere_get_normal(t_object *object, t_vect3d point);
void			sphere_get_tex_coord(t_object *object, t_vect3d point,
				float coord[2]);

#endif
