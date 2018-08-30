/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_from_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 17:47:16 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/20 17:47:44 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"

t_vect3d	vect3d_from_float(float *data)
{
	t_vect3d	vec;

	vec[X] = data[X];
	vec[Y] = data[Y];
	vec[Z] = data[Z];
	return (vec);
}
