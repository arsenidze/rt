/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:22:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/18 22:26:12 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <stdio.h>
static double	times(double x, int times)
{
	double	res;

	res = 1;
	while (times > 0)
	{
		res *= x;
		times--;
	}
	return (res);
}

static double	newton_step(double x0, double c[], int degree)
{
	double	func;
	double	deriv;
	int		i;

	func = 0;
	i = -1;
	while (++i < degree + 1)
		func += c[degree - i] * times(x0, i);
	deriv = 0;
	i = 0;
	while (++i < degree + 1)
		deriv += i * c[degree - i] * times(x0, i - 1);
	return (func / deriv);
}

#define EPS 		1e-4
#define MAX_ITER	10
#define STEP 		0.25

double			newton(double x0, double c[], int degree)
{
	double	x_prev;
	double	x_next;
	int		i;
	int		j;
	int		num_roots;

	num_roots = degree;
	j = 1;
	x_next = x0;
	i = 0;
	while (i < MAX_ITER)
	{
		x_prev = x_next;
		x_next = x_prev - newton_step(x_prev, c, degree);
		if (fabs(x_next - x_prev) < EPS)
		{
			if (x_next > 0)
				return (x_next);
			x_next = x0 + j * STEP;
			j++;
			num_roots--;
			if (num_roots == 0)
				return (-1);
		}
		i++;
	}
	return (-1);
}
