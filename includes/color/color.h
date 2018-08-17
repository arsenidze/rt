/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:13:05 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/02 14:02:10 by amelihov         ###   ########.fr       */
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
# define COLOR_MULT(c, m) (t_color){.rgba ={c.rgba[BLUE]*m,\
											c.rgba[GREEN]*m,\
											c.rgba[RED]*m}}
# define COLOR_ADD(c1, c2) (t_color){.rgba = {c1.rgba[BLUE] + c2.rgba[BLUE],\
											c1.rgba[GREEN] + c2.rgba[GREEN],\
											c1.rgba[RED] + c2.rgba[RED]}}

typedef union	u_color
{
	unsigned int	value;
	unsigned char	rgba[4];
}				t_color;

#endif
