/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 23:06:26 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 23:06:46 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paraboloid.h"

t_paraboloid	paraboloid_create(double k, double h)
{
	t_paraboloid	paraboloid;

	paraboloid.k = k;
	paraboloid.h = h;
	return (paraboloid);
}
