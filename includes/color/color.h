/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:13:05 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 19:57:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define ALPHA	3
# define RED	2
# define GREEN	1
# define BLUE	0

# define COLOR(c) (t_color)(unsigned int)c
# define COLOR_RGBA(r, g, b, a) (t_color){.rgba = {b,g,r,a}}

typedef union	u_color
{
	unsigned int	value;
	unsigned char	rgba[4];
}				t_color;

#endif
