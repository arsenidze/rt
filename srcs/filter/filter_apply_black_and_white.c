/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_apply_black_and_white.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:27:10 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 16:27:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"
#include "vect3d.h"
#include <math.h>

t_vect3d	filter_apply_black_and_white(t_vect3d color)
{
	t_vect3d	new_color;
	double		tmp;
	
	tmp = sqrt(vect3d_dot(color, color) / 3);		
	new_color[X] = tmp;
	new_color[Y] = tmp;
	new_color[Z] = tmp;
	return (new_color);
}
