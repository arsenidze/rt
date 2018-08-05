/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:45:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/05 20:59:49 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vect3d.h"
# include "basis.h"
# include "primitive.h"
# include "material.h"
# include "texture.h"

typedef struct	s_object
{
	t_vect3d	pos;
	t_basis		basis;
	t_primitive	primitive;
	t_material	material;
	t_texture	texture;
	short		(*intersection)(t_object *object, t_ray ray,
				t_vect3d *intersect_point);
	t_vect3d	(*get_normal)(t_object *object, t_vect3d point);
	void		(*get_tex_coord)(t_object *object, t_vect3d point,
				float coord[2]);
}				t_object;

#endif
