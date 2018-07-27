/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_rotate_around_axis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:10:32 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/18 15:16:22 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"
#include <math.h>

/*
**	Rodrigues' rotation formula
**	k -> axis
*/
t_vect3d	vect3d_rotate_around_axis(t_vect3d v, t_vect3d k, double angel)
{
	t_vect3d	v_rot;
	double		cos_a;
	double		sin_a;

	cos_a = cos(angel);
	sin_a = sin(angel);
	v_rot = vect3d_mult_on_scalar(v, cos_a)
		+ vect3d_mult_on_scalar(vect3d_cross(k, v), sin_a)
		+ vect3d_mult_on_scalar(k, vect3d_dot(k, v) * (1 - cos_a));
	return (v_rot);
}
