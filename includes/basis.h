/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:50:04 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/01 14:52:02 by amelihov         ###   ########.fr       */
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

#endif
