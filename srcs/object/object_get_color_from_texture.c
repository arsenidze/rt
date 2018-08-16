/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_get_color_from_texture.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:59:14 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/14 21:05:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "color.h"

t_vect3d	object_get_color_from_texture(const t_object *object,
			t_vect3d point)
{
	float		coord[2];
	t_color		col;
	t_vect3d	vect3d_col;

	object_get_tex_coord(object, point, coord);
	coord[0] *= object->texture.w;
	coord[1] *= object->texture.h;
	col.value = TEX_GET_PIXEL(object->texture, (int)coord[0], (int)coord[1]);
	vect3d_col[X] = col.rgba[RED] / 255.0;
	vect3d_col[Y] = col.rgba[GREEN] / 255.0;
	vect3d_col[Z] = col.rgba[BLUE] / 255.0;
	return (vect3d_col);
}
