/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_fst_closer_snd_to.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:03:40 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 21:05:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"

short	vect3d_is_fst_closer_snd_to(t_vect3d v1, t_vect3d v2, t_vect3d c)
{
	return (vect3d_sq_len(v1 - c) < vect3d_sq_len(v2 - c));
}
