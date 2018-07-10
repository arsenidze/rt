/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:14:35 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/04 11:29:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vect3d.h"
# include "color.h"
# include "primitive.h"

# define GET_NORMAL(obj, p) obj->get_normal(obj->primitive, p)

# define K_AMBIENT	0
# define K_DIFFUSE	1
# define K_SPECULAR 2

typedef struct	s_object
{
	void		*primitive;
	short		(*intersection)(void *primitive, t_vect3d start,
				t_vect3d ray_dir, t_vect3d *intersect_point);
	t_vect3d	(*get_normal)(void *primitive, t_vect3d point);
	void		(*delete_primitive)(void *primitive);
	t_vect3d	k[3];
}				t_object;

/*
**	!!! Use PRIMITIVE macro from primitive.h on 'var_args' place !!!
*/
t_object		*object_new(t_vect3d k[3], void *var_args[]);
void			object_delete(t_object *object);

#endif
