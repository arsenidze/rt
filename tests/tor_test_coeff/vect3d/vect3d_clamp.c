/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_clamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 20:39:27 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 21:02:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"
#include "mmath.h"

t_vect3d	vect3d_clamp(t_vect3d v, double a, double b)
{
	return (vect3d(clampd(v[X], a, b),
				clampd(v[Y], a, b),
				clampd(v[Z], a, b)));
}
