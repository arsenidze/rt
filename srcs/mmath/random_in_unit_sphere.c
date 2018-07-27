/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_in_unit_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:19:29 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/26 14:26:09 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmath.h"
#include "vect3d.h"

t_vect3d	random_in_unit_sphere(void)
{
	t_vect3d	p;

	while (1)
	{
		p = vect3d_mult_on_scalar(vect3d(get_rand(), get_rand(), get_rand()), 2)
		  - vect3d(1, 1, 1);
		if (vect3d_dot(p, p) <= 1)
			break ;
	}
	return (p);
}
