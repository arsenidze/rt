/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:49:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:15:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vect3d.h"

/*
**	components indexs
*/
# define L_AMBIENT		0
# define L_DIFFUSE		1
# define L_SPECULAR		2

typedef struct	s_light
{
	t_vect3d	pos;
	t_vect3d	components[3];
}				t_light;

t_light			*light_new(t_vect3d pos, t_vect3d components[3]);
void			light_delete(t_light *light);

#endif
