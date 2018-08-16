/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:30:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/10 15:23:38 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "primitive.h"

# define SHAPE(n,...) (t_shape){{.n = n##_create(__VA_ARGS__)},SHAPE_METHODS(n)}
# define SHAPE_METHODS(n) n##_intersection,n##_get_normal,n##_get_tex_coord

typedef struct	s_shape
{
	t_primitive	primitive;
	short		(*intersection)(t_primitive primitive, t_basis basis,
				t_ray ray, t_vect3d *intersect_point);
	t_vect3d	(*get_normal)(t_primitive primitive, t_basis basis,
				t_vect3d point);
	void		(*get_tex_coord)(t_primitive primitive, t_basis basis,
				t_vect3d point, float coord[2]);
}				t_shape;

#endif
