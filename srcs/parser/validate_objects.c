/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:21:22 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/17 17:59:08 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "parser_values_limits.h"

static int	validate_object(struct s_p_object *object)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_obj_type_num(object))
	|| (error_code = validate_obj_type(object))
	|| (error_code = validate_obj_material(&object->material)))
		;
	else if ((error_code = validate_vector_float(object->position,
		PARS_POSITION_MIN, PARS_POSITION_MAX)))
		parser_put_error_mapping("position");
	return (error_code);
}

int			validate_objects(struct s_p_object *objects,
		unsigned int objects_count)
{
	unsigned int	error_code;
	unsigned int	i;

	error_code = 0;
	i = 0;
	while (i < objects_count)
	{
		if ((error_code = validate_object(&objects[i])))
		{
			parser_put_error_sequence(i);
			parser_put_error_mapping("objects");
			return (error_code);
		}
		i++;
	}
	return (0);
}
