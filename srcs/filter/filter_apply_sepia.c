/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_apply_sepia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:26:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 16:27:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"
#include "vect3d.h"

t_vect3d	filter_apply_sepia(t_vect3d color)
{
	t_vect3d	new_color;

	new_color[X] = vect3d_dot(color, vect3d(0.393, 0.769, 0.189));
	new_color[Y] = vect3d_dot(color, vect3d(0.349, 0.686, 0.168));
	new_color[Z] = vect3d_dot(color, vect3d(0.272, 0.534, 0.131));
	return (vect3d_clamp(new_color, 0, 1));
}
