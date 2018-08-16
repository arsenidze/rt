/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:50:04 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 13:58:22 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIS_H
# define BASIS_H

# include "vect3d.h"

typedef struct	s_basis
{
	t_vect3d	x;
	t_vect3d	y;
	t_vect3d	z;
}				t_basis;

t_vect3d	basis_get_coord_in_basis(t_basis new_basis, t_vect3d point);
t_basis		basis_rotate_ox(t_basis basis, double angle);
t_basis		basis_rotate_oy(t_basis basis, double angle);
t_basis		basis_rotate_oz(t_basis basis, double angle);

#endif
