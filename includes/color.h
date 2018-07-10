/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:13:05 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:07:20 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED	2
# define GREEN	1
# define BLUE	0
# define ALPHA	3

# define COLOR(c) (t_color)(unsigned int)c
# define COLOR_RGBA(r, g, b, a) (t_color){.rgba = {b,g,r,a}}

typedef union	u_color
{
	unsigned char	rgba[4];
	unsigned int	value;
}				t_color;

#endif
