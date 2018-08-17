/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:56:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 17:23:15 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmath.h"
#include <math.h>

static void	negative_discrmnt_solution(double x[3], double q, double p,
			double cubic_discrmnt)
{
	double	sqrt_cubic_discrmnt;
	double	phi_by_3;
	int		i;

	sqrt_cubic_discrmnt = sqrt(-cubic_discrmnt);
	phi_by_3 = atan2(sqrt_cubic_discrmnt, -q / 2.0) / 3.0;
	i = 0;
	while (i < 3)
	{
		x[i] = 2.0 * sqrt(-p / 3.0) * cos(phi_by_3 + i * 2.0 * M_PI / 3.0);
		i++;
	}
}

static void	positive_discrmnt_solution(double x[3], double q, double p,
			double cubic_discrmnt)
{
	double	sqrt_cubic_discrmnt;

	(void)p;
	sqrt_cubic_discrmnt = sqrt(cubic_discrmnt);
	x[0] = cbrt(-q / 2.0 + sqrt_cubic_discrmnt)
		+ cbrt(-q / 2.0 - sqrt_cubic_discrmnt);
}

#define A 0
#define B 1
#define C 2
#define D 3

static void	fill_cubic_canonical_form_coeff(double c[4], double *p, double *q)
{
	*q = (2.0 * (c[B] * c[B] * c[B]) - 9.0 * c[A] * c[B] * c[C]
		+ 27.0 * c[A] * c[A] * c[D]) / (27.0 * c[A] * c[A] * c[A]);
	*p = (3 * c[A] * c[C] - c[B] * c[B]) / (3 * c[A] * c[A]);
}

int			solve3(double c[4], double x[3])
{
	int			nroots;
	double		q;
	double		p;
	double		cubic_discrmnt;
	int			i;

	nroots = 0;
	fill_cubic_canonical_form_coeff(c, &p, &q);
	cubic_discrmnt = square(q / 2.0) + cb(p / 3.0);
	if (cubic_discrmnt >= 0)
	{
		positive_discrmnt_solution(x, q, p, cubic_discrmnt);
		nroots = 1;
	}
	else
	{
		negative_discrmnt_solution(x, q, p, cubic_discrmnt);
		nroots = 3;
	}
	i = -1;
	while (++i < nroots)
		x[i] = x[i] - c[B] / (3 * c[A]);
	return (nroots);
}
