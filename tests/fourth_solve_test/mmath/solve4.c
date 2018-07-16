/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 23:11:37 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/16 23:46:04 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmath.h"
#include <math.h>

typedef struct	s_equation4
{
	double	p;
	double	q;
	double	r;
}				t_equation4;

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4

void	solve4(double c[5], double roots[4])
{
	t_equation4	e;
	double		cube_coef[4];
	double		cube_roots[3];
	double		quad_coef[3];
	int			i;
	//double		roots[2];

	e.p = (8.0 * c[A] * c[B] - 3 * (c[B] * c[B])) / (8.0 * c[A] * c[A]);
	e.q = (8.0 * c[A] * c[A] * c[D] + c[B] * c[B] * c[B]
			- 4.0 * c[A] * c[B] * c[C]) / (8.0 * c[A] * c[A]);
	e.r = (16.0 * c[A] * c[B] * c[B] * c[C] - 64.0 * c[A] * c[A] * c[B] * c[D]
			- 3.0 * c[B] * c[B] * c[B] * c[B] + 256.0 * c[A] * c[A] * c[A] * c[E])
		/ (256.0 * c[A] * c[A] * c[A] * c[A]);
	cube_coef[A] = 2;
	cube_coef[B] = -e.p;
	cube_coef[C] = -2 * e.r;
	cube_coef[D] = e.r * e.p - e.q * e.q / 4.0;
	solve3(cube_coef, cube_roots);
	quad_coef[A] = 1;
	quad_coef[B] = -sqrt(2.0 * cube_roots[0] - e.p);
	quad_coef[C] = e.q / (2.0 * sqrt(2.0 * cube_roots[0] - e.p)) + cube_roots[0];
	roots[0] = get_positive_root(quad_coef);
	quad_coef[B] = sqrt(2.0 * cube_roots[0] - e.p);
	quad_coef[C] = -e.q / (2.0 * sqrt(2.0 * cube_roots[0] - e.p)) + cube_roots[0];
	roots[1] = get_positive_root(quad_coef);
	roots[2] = INF;
	roots[3] = INF;
	i = -1;
	while (++i < 4)
		roots[i] = roots[i] - c[B] / (4.0 * c[A]);
}
