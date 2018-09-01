/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parsed_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:49:06 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 17:26:22 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_parsed_values(struct s_p_scene *p_scene)
{
	unsigned int	error_code;

	//if (validate_camera_values(p_scene->camera))
	////do we need to validate cam values?
	//	return (1);
	error_code = 0;
	if ((error_code = validate_lights(p_scene->lights, p_scene->lights_count)))
	{
		parser_put_error_code(error_code);
		return (1);
	}
	if ((error_code = validate_objects(p_scene->objects, p_scene->objects_count)))
	{
		parser_put_error_code(error_code);
		return (1);
	}
	return (0);
}
