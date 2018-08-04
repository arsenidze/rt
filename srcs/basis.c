/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:58:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/04 15:58:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basis.h"

t_vect3d	basis_get_coord_in_basis(t_basis basis, t_vect3d point)
{
	t_vect3d	new_point;

	new_point[X] = vect3d_dot(basis.x, point);
	new_point[Y] = vect3d_dot(basis.y, point);
	new_point[Z] = vect3d_dot(basis.z, point);
	return (new_point);
}
