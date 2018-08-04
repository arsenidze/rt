/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:49:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/04 16:25:54 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "libft.h"
#include <stdlib.h>

t_object	*object_new(t_vect3d k[3], int is_glass, void *var_arg[])
{
	t_object	*new_obj;

	if (!(new_obj = malloc(sizeof(t_object))))
		return (NULL);
	if (!(new_obj->primitive = var_arg[0]))
		return (NULL);
	new_obj->intersection = var_arg[1];
	new_obj->get_normal = var_arg[2];
	new_obj->get_tex_coord = var_arg[3];
	new_obj->delete_primitive = var_arg[4];
	ft_memcpy(new_obj->k, k, sizeof(t_vect3d) * 3);
	new_obj->is_glass = is_glass;
	return (new_obj);
}

void		object_delete(t_object *object)
{
	if (!object)
		return ;
	object->delete_primitive(object->primitive);
	free(object);
}
