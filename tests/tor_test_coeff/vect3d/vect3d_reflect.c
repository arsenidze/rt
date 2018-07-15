/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:07:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/10 20:22:52 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"

t_vect3d	vect3d_reflect(t_vect3d ray, t_vect3d normal)
{
	return (ray - vect3d_mult_on_scalar(normal, 2 * vect3d_dot(ray, normal)));
}
