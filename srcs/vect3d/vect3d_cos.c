/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_cos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 20:37:48 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 20:38:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"

double		vect3d_cos(t_vect3d v1, t_vect3d v2)
{
	return (vect3d_dot(v1, v2) / (vect3d_len(v1) * vect3d_len(v2)));
}
