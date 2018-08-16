/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:22:49 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/10 14:22:00 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

#define BYTE_PER_PIX	3

#define TEX_GET_PIXEL(tex,x,y) *(t_uint*)(tex.pixels+((y)*tex.w+(x))*BYTE_PER_PIX)

typedef unsigned int	t_uint;

typedef struct			s_texture
{
	t_uint	w;
	t_uint	h;
	t_uint	pitch;
	void	*pixels;
}						t_texture;

#endif
