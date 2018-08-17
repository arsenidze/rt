/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:43:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 16:22:53 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "vect3d.h"
#include <math.h>

static short	is_total_internal_reflection(double n[2], double cosi,
				double *cost)
{
	double	sini2;
	double	sint2;
	double	iors_ratio;

	iors_ratio = n[0] / n[1];
	sini2 = (1.0 - cosi * cosi);
	sint2 = (iors_ratio * iors_ratio) * sini2;
	if (sint2 > 1.0)
		return (1.0);
	*cost = sqrt(1.0 - sint2);
	return (0);
}

double			fresnel(t_vect3d i, t_vect3d normal, float obj_ior, int inside)
{
	double	n[2];
	double	cosi;
	double	cost;
	double	ro;
	double	rp;

	if (inside)
	{
		n[0] = obj_ior;
		n[1] = 1.0;
	}
	else
	{
		n[0] = 1.0;
		n[1] = obj_ior;
	}
	cosi = -vect3d_dot(i, normal);
	if (is_total_internal_reflection(n, cosi, &cost))
		return (1);
	ro = (n[0] * cosi - n[1] * cost) / (n[0] * cosi + n[1] * cost);
	rp = (n[1] * cosi - n[0] * cost) / (n[1] * cosi + n[0] * cost);
	return ((ro * ro + rp * rp) / 2.0);
}
