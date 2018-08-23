/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:45:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/23 14:16:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vect3d.h"
# include "basis.h"
# include "shape.h"
# include "material.h"
# include "texture.h"

# define OBJ_HAS_TEX(obj) (obj.texture.pixels ? 1 : 0)

typedef struct	s_object
{
	t_vect3d	pos;
	t_basis		basis;
	t_shape		shape;
	t_material	material;
	t_texture	texture;
}				t_object;

short			object_intersection(const t_object *object, t_ray ray,
				t_vect3d *intersect_point);
t_vect3d		object_get_normal(const t_object *object, t_vect3d point);
void			object_get_tex_coord(const t_object *object, t_vect3d point,
				float coord[2]);
t_vect3d		object_get_color_from_texture(const t_object *object,
				t_vect3d point);
void			object_update_material_according_to_tex(t_object *object,
				t_vect3d point);

#endif
