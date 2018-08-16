/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:43:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/14 18:57:38 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "vect3d.h"
#include <math.h>

double	fresnel(t_vect3d i, t_vect3d normal, float ior, int inside)
{
	double	n;
	double	n1;
	double	n2;
	double	sini2;
	double	sint2;
	double	cosi;
	double	cost;
	double	ro;
	double	rp;

	if (inside)
	{
		n1 = ior;
		n2 = 1.0;
	}
	else
	{
		n1 = 1.0;
		n2 = ior;
	}
	n = n1 / n2;
	cosi = -vect3d_dot(i, normal);
	sini2 = (1.0 - cosi * cosi);
	sint2 = (n * n) * sini2;
	if (sint2 > 1.0)
		return (1.0);
	cost = sqrt(1.0 - sint2);
	ro = (n1 * cosi - n2 * cost) / (n1 * cosi + n2 * cost);
	rp = (n2 * cosi - n1 * cost) / (n2 * cosi + n1 * cost);
	return ((ro * ro + rp * rp) / 2.0);
}
