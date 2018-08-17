/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuboid_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:36:20 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 12:36:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cuboid.h"

#define SIDE_X	0
#define SIDE_Y	1
#define SIDE_Z	2

t_cuboid		cuboid_create(double sides[3])
{
	t_cuboid	cuboid;

	cuboid.half_sides[SIDE_X] = sides[SIDE_X] / 2.0;
	cuboid.half_sides[SIDE_Y] = sides[SIDE_Y] / 2.0;
	cuboid.half_sides[SIDE_Z] = sides[SIDE_Z] / 2.0;
	return (cuboid);
}
