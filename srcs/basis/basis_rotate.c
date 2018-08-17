/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:58:42 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 22:43:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basis.h"

t_basis	basis_rotate_ox(t_basis basis, double angel)
{
	t_basis	new_basis;

	new_basis.x = basis.x;
	new_basis.y = vect3d_rotate_around_axis(basis.y,
		basis.x, angel);
	new_basis.z = vect3d_rotate_around_axis(basis.z,
		basis.x, angel);
	return (new_basis);
}

t_basis	basis_rotate_oy(t_basis basis, double angel)
{
	t_basis	new_basis;

	new_basis.y = basis.y;
	new_basis.x = vect3d_rotate_around_axis(basis.x,
		basis.y, angel);
	new_basis.z = vect3d_rotate_around_axis(basis.z,
		basis.y, angel);
	return (new_basis);
}

t_basis	basis_rotate_oz(t_basis basis, double angel)
{
	t_basis	new_basis;

	new_basis.z = basis.z;
	new_basis.x = vect3d_rotate_around_axis(basis.x,
		basis.z, angel);
	new_basis.y = vect3d_rotate_around_axis(basis.y,
		basis.z, angel);
	return (new_basis);
}
