/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 23:11:37 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 17:38:14 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmath.h"
#include <math.h>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4

#define P	0
#define Q	1
#define R	2

static void	backward_substitution(double roots[4], double c[5], int nroots)
{
	int		i;

	i = -1;
	while (++i < nroots)
		roots[i] = roots[i] - c[B] / (4.0 * c[A]);
}

static void	fill_quartic_canonical_form_coeff(double c[5], double canon_c[3])
{
	canon_c[P] = (8.0 * c[A] * c[C] - 3.0 * (c[B] * c[B]))
		/ (8.0 * c[A] * c[A]);
	canon_c[Q] = (8.0 * c[A] * c[A] * c[D] + c[B] * c[B] * c[B]
			- 4.0 * c[A] * c[B] * c[C]) / (8.0 * c[A] * c[A] * c[A]);
	canon_c[R] = (16.0 * c[A] * c[B] * c[B] * c[C]
		- 64.0 * c[A] * c[A] * c[B] * c[D] - 3.0 * c[B] * c[B] * c[B] * c[B]
		+ 256.0 * c[A] * c[A] * c[A] * c[E])
		/ (256.0 * c[A] * c[A] * c[A] * c[A]);
}

int			solve4(double c[5], double roots[4])
{
	double		canon_c[3];
	double		cube_c[4];
	double		cube_roots[3];
	double		quad_c[3];
	int			nroots;

	fill_quartic_canonical_form_coeff(c, canon_c);
	cube_c[A] = 2;
	cube_c[B] = -canon_c[P];
	cube_c[C] = -2 * canon_c[R];
	cube_c[D] = canon_c[R] * canon_c[P] - canon_c[Q] * canon_c[Q] / 4.0;
	solve3(cube_c, cube_roots);
	quad_c[A] = 1;
	quad_c[B] = -sqrt(2.0 * cube_roots[0] - canon_c[P]);
	quad_c[C] = canon_c[Q] / (2.0 * sqrt(2.0 * cube_roots[0] - canon_c[P]))
				+ cube_roots[0];
	nroots = solve2(quad_c, roots);
	quad_c[B] = sqrt(2.0 * cube_roots[0] - canon_c[P]);
	quad_c[C] = -canon_c[Q] / (2.0 * sqrt(2.0 * cube_roots[0] - canon_c[P]))
				+ cube_roots[0];
	nroots += solve2(quad_c, &roots[nroots]);
	backward_substitution(roots, c, nroots);
	return (nroots);
}
