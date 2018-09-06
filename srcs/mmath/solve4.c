/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 23:11:37 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/06 19:05:49 by amelihov         ###   ########.fr       */
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

static inline int	backward_substitution(double roots[4], double c[5],
					int nroots)
{
	int		i;

	i = -1;
	while (++i < nroots)
		roots[i] = roots[i] - c[B] / (4.0 * c[A]);
	return (nroots);
}

static inline void	fill_quartic_canonical_form_coeff(double c[5],
					double canon_c[3])
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

static inline int	special_case_solution(double canon_c[3], double roots[4])
{
	double	quad_c[3];
	int		nroots;
	double	quad_roots[2];

	quad_c[A] = 1;
	quad_c[B] = canon_c[P];
	quad_c[C] = canon_c[R];
	nroots = solve2(quad_c, quad_roots);
	if (nroots > 0)
	{
		nroots = 0;
		if (quad_roots[0] > 0.0)
		{
			roots[0] = sqrt(quad_roots[0]);
			roots[1] = -roots[0];
			nroots += 2;
		}
		if (quad_roots[1] > 0.0)
		{
			roots[nroots] = sqrt(quad_roots[1]);
			roots[nroots + 1] = -roots[nroots];
			nroots += 2;
		}
	}
	return (nroots);
}

static inline int	solve_two_quadratic(double canon_c[3], double cube_root,
					double roots[4])
{
	double	quad_c[3];
	int		nroots;
	double	tmp;

	tmp = canon_c[P] / 2.0 + cube_root;
	quad_c[A] = 1;
	quad_c[B] = -sqrt(2.0 * cube_root);
	quad_c[C] = tmp - 0.5 * canon_c[Q] / quad_c[B];
	nroots = solve2(quad_c, roots);
	quad_c[B] *= -1.0;
	quad_c[C] = tmp - 0.5 * canon_c[Q] / quad_c[B];
	nroots += solve2(quad_c, &roots[nroots]);
	return (nroots);
}

int					solve4(double c[5], double roots[4])
{
	double		canon_c[3];
	double		cube_c[4];
	double		cube_roots[3];
	int			nroots;

	fill_quartic_canonical_form_coeff(c, canon_c);
	if (canon_c[Q] == 0.0)
	{
		nroots = special_case_solution(canon_c, roots);
		return (backward_substitution(roots, c, nroots));
	}
	cube_c[A] = 1;
	cube_c[B] = canon_c[P];
	cube_c[C] = canon_c[P] * canon_c[P] / 4.0 - canon_c[R];
	cube_c[D] = -canon_c[Q] * canon_c[Q] / 8.0;
	solve3(cube_c, cube_roots);
	if (cube_roots[0] < 1e-4)
	{
		nroots = special_case_solution(canon_c, roots);
		return (backward_substitution(roots, c, nroots));
	}
	nroots = solve_two_quadratic(canon_c, cube_roots[0], roots);
	return (backward_substitution(roots, c, nroots));
}
