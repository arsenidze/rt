/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parsed_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:49:06 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/02 16:27:40 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_parsed_values(struct s_p_scene *p_scene)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_lights(p_scene->lights, p_scene->lights_count))
		|| (error_code = validate_objects(p_scene->objects,
			p_scene->objects_count)))
	{
		parser_put_error_code(error_code);
		return (1);
	}
	return (0);
}
