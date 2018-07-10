/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_is_in_range_abs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:41:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 18:46:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

short	vect3d_is_in_range_abs(t_vect3d v, double a, double b)
{
	t_vect3d	absed_v;

	absed_v[X] = ABS(v[X]);
	absed_v[Y] = ABS(v[Y]);
	absed_v[Z] = ABS(v[Z]);
	return ((absed_v[X] >= a && absed_v[X] <= b)
		&& (absed_v[Y] >= a && absed_v[Y] <= b)
		&& (absed_v[Z] >= a && absed_v[Z] <= b));
}
