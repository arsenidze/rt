/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:53:25 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 22:53:47 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

t_cone			cone_create(double slope, double h)
{
	t_cone	cone;

	cone.slope = slope;
	cone.slope2 = slope * slope;
	cone.h = h;
	cone.r = slope * h;
	return (cone);
}
