/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_cos_normed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 20:39:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 20:39:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"

double		vect3d_cos_normed(t_vect3d v1, t_vect3d v2)
{
	return (vect3d_dot(v1, v2));
}
