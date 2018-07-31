/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:44:07 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 19:59:38 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmath.h"
#include <math.h>

#define A 0
#define B 1
#define C 2

void	solve2(double c[3], double roots[2])
{
	double	discrmnt;
	double	discrmnt_sqrt;

	discrmnt = c[B] * c[B] - 4.0 * c[A] * c[C];
	if (discrmnt < 0)
	{
		roots[0] = -1.0;
		roots[1] = -1.0;
		return ;
	}
	discrmnt_sqrt = sqrt(discrmnt);
	roots[0] = -c[B] / (2.0 * c[A]) - discrmnt_sqrt / (2.0 * c[A]);
	roots[1] = -c[B] / (2.0 * c[A]) + discrmnt_sqrt / (2.0 * c[A]);
}
