/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_obj_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:11:46 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 18:28:01 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_obj_type(struct s_p_object *object)
{
	unsigned int	error_code;

	error_code = 0;
	if (object->plane && (error_code = validate_plane(object->plane)))
		parser_put_error_mapping("plane");
	else if (object->sphere && (error_code = validate_sphere(object->sphere)))
		parser_put_error_mapping("sphere");
	else if (object->cone && (error_code = validate_cone(object->cone)))
		parser_put_error_mapping("cone");
	else if (object->cylinder &&
		(error_code = validate_cylinder(object->cylinder)))
		parser_put_error_mapping("cylinder");
	else if (object->rectangle &&
		(error_code = validate_rectangle(object->rectangle)))
		parser_put_error_mapping("rectangle");
	else if (object->disk && (error_code = validate_disk(object->disk)))
		parser_put_error_mapping("disk");
	else if (object->torus && (error_code = validate_torus(object->torus)))
		parser_put_error_mapping("torus");
	else if (object->cuboid && (error_code = validate_cuboid(object->cuboid)))
		parser_put_error_mapping("cuboid");
	else if (object->paraboloid &&
		(error_code = validate_paraboloid(object->paraboloid)))
		parser_put_error_mapping("paraboloid");
	return (error_code);
}
