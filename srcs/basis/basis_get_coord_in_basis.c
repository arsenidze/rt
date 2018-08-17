/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis_get_coord_in_basis.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:54:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 22:43:20 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basis.h"

t_vect3d	basis_get_coord_in_basis(t_basis new_basis, t_vect3d point)
{
	t_vect3d	new_point;

	new_point[X] = vect3d_dot(new_basis.x, point);
	new_point[Y] = vect3d_dot(new_basis.y, point);
	new_point[Z] = vect3d_dot(new_basis.z, point);
	return (new_point);
}
