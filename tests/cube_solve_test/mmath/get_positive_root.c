/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positive_root.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:36:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/05/03 18:37:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	get_positive_root(double c[3])
{
	double	discriminant_half;
	double	sqrt_disc_half;
	double	t;

	discriminant_half = c[1] * c[1] - c[0] * c[2];
	if (discriminant_half < 0)
		return (-1);
	sqrt_disc_half = sqrt(discriminant_half);
	t = (-c[1] - sqrt_disc_half) / c[0];
	if (t >= 0)
		return (t);
	t = (-c[1] + sqrt_disc_half) / c[0];
	if (t >= 0)
		return (t);
	return (-1);
}
