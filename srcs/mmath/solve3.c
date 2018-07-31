/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:56:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 22:19:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmath.h"
#include <math.h>

typedef struct	s_equation3
{
	double	q;
	double	p;
	double	quad_discrmnt;
	double	sqrt_quad_discrmnt;
	double	phi_by_3;
}				t_equation3;

#define A 0
#define B 1
#define C 2
#define D 3

#define IS_ZERO(a) (fabs(a) < 1e-5)

void	solve3(double c[4], double x[3])
{
	t_equation3	e;
	int			i;

	e.q = (2.0 * (c[B] * c[B] * c[B]) - 9.0 * c[A] * c[B] * c[C]
		+ 27.0 * c[A] * c[A] * c[D]) / (27.0 * c[A] * c[A] * c[A]);
	e.p = (3 * c[A] * c[C] - c[B] * c[B]) / (3 * c[A] * c[A]);
	e.quad_discrmnt = square(e.q / 2.0) + cb(e.p / 3.0);
	if (e.quad_discrmnt >= 0)
	{
		e.sqrt_quad_discrmnt = sqrt(e.quad_discrmnt);
		x[0] = cbrt(-e.q / 2.0 + e.sqrt_quad_discrmnt)
			+ cbrt(-e.q / 2.0 - e.sqrt_quad_discrmnt);
		x[1] = INF;
		x[2] = INF;
	}
	else
	{
		e.sqrt_quad_discrmnt = sqrt(-e.quad_discrmnt);
		if (IS_ZERO(e.q))
			e.phi_by_3 = M_PI / 2.0;
		else
		{
			e.phi_by_3 = atan(e.sqrt_quad_discrmnt / (-e.q / 2.0)) / 3.0;
			if (e.q > 0)
				e.phi_by_3 += M_PI;
		}
		i = -1;
		while (++i < 3)
		{
			x[i] = 2 * sqrt(-e.p / 3.0)
				* cos((e.phi_by_3 + i * 2.0 * M_PI / 3.0));
		}
	}
	i = -1;
	while (++i < 3)
		x[i] = x[i] - c[B] / (3 * c[A]);
}
