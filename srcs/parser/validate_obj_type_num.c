/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_obj_type_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:36:15 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/30 16:53:29 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_obj_type_num(struct s_p_object *object)
{
	unsigned int	type_count;

	type_count = 0;
	if (object->plane)
		type_count++;
	if (object->sphere)
		type_count++;
	if (object->cone)
		type_count++;
	if (object->cylinder)
		type_count++;
	if (object->rectangle)
		type_count++;
	if (object->disk)
		type_count++;
	if (object->torus)
		type_count++;
	if (object->cuboid)
		type_count++;
	if (object->paraboloid)
		type_count++;
	if (type_count > 1)
		return (TOO_MANY_TYPES);
	return ((type_count < 1) ? TOO_FEW_TYPES : 0);
}
