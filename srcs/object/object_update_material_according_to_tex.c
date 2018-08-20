/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_update_material_according_to_tex.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 22:41:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 22:44:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void		object_update_material_according_to_tex(t_object *object,
			t_vect3d point)
{
	object->material.ambient = object_get_color_from_texture(object, point);
	object->material.diffuse = object->material.ambient;
}
