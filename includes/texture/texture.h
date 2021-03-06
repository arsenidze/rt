/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:22:49 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/23 16:24:09 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# define TEXTURE_SUCCESS	0
# define TEXTURE_FAILURE	1

# define TEX_GET_PIXEL(tex,x,y) *(t_uint*)(tex.pixels+((y)*tex.w+(x))*tex.bpp)

typedef unsigned int	t_uint;

typedef struct			s_texture
{
	t_uint	w;
	t_uint	h;
	t_uint	bpp;
	void	*pixels;
	int		offset[2];
	float	scale;
}						t_texture;

short					texture_load(t_texture *tex, const char *tex_name);
void					texture_deinit(t_texture *tex);

#endif
