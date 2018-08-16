/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_from_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:43:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/09 20:46:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"

t_vect3d	vect3d_from_number(int number)
{
	t_vect3d	v;

	v[Z] = number & 0xFF;
	v[Y] = number & (0xFF << 8);
	v[X] = number & (0xFF << 16);
	return (v);
}
