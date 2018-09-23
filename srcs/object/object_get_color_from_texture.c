/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_get_color_from_texture.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:59:14 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/23 17:11:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "color.h"
#include "texture.h"

static inline void	apply_tex_offset(float coord[2], const t_texture *texture)
{
	if (texture->offset[0] != 0)
	{
		coord[0] += texture->offset[0];
		if (coord[0] > texture->h)
			coord[0] -= texture->h;
	}
	if (texture->offset[1] != 0)
	{
		coord[1] += texture->offset[1];
		if (coord[1] > texture->h)
			coord[1] -= texture->h;
	}
}

static inline void	apply_tex_scale(float coord[2], const t_texture *texture)
{
	coord[0] *= texture->scale;
	coord[1] *= texture->scale;
}

t_vect3d			object_get_color_from_texture(const t_object *object,
					t_vect3d point)
{
	float		coord[2];
	t_color		col;
	t_vect3d	vect3d_col;

	object_get_tex_coord(object, point, coord);
	coord[0] *= object->texture.w;
	coord[1] *= object->texture.h;
	apply_tex_scale(coord, &object->texture);
	apply_tex_offset(coord, &object->texture);
	col.value = TEX_GET_PIXEL(object->texture, (int)coord[0], (int)coord[1]);
	vect3d_col[X] = col.rgba[RED] / 255.0;
	vect3d_col[Y] = col.rgba[GREEN] / 255.0;
	vect3d_col[Z] = col.rgba[BLUE] / 255.0;
	return (vect3d_col);
}
