/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_to_basis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:32:16 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/16 18:33:10 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vect3d.h"
# include "basis.h"

t_basis	angles_to_basis(float *angles)
{
	t_basis	basis;

	basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0), vect3d(0, 0, 1)};
	basis = basis_rotate_ox(basis, angles[X]);
	basis = basis_rotate_oy(basis, angles[Y]);
	basis = basis_rotate_oz(basis, angles[Z]);
	return (basis);
}
