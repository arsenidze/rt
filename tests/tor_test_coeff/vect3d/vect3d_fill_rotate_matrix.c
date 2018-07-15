/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_fill_rotate_matrix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:36:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:21:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"
#include <math.h>

void		vect3d_fill_rotate_ox_matrix(t_vect3d m[3], double angel)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angel);
	sin_a = sin(angel);
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = cos_a;
	m[1][2] = -sin_a;
	m[2][0] = 0;
	m[2][1] = sin_a;
	m[2][2] = cos_a;
}

void		vect3d_fill_rotate_oy_matrix(t_vect3d m[3], double angel)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angel);
	sin_a = sin(angel);
	m[0][0] = cos_a;
	m[0][1] = 0;
	m[0][2] = sin_a;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = -sin_a;
	m[2][1] = 0;
	m[2][2] = cos_a;
}

void		vect3d_fill_rotate_oz_matrix(t_vect3d m[3], double angel)
{
	double	cos_a;
	double	sin_a;

	cos_a = cos(angel);
	sin_a = sin(angel);
	m[0][0] = cos_a;
	m[0][1] = -sin_a;
	m[0][2] = 0;
	m[1][0] = sin_a;
	m[1][1] = cos_a;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
}
