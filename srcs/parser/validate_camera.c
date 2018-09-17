/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:05:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/17 17:17:02 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "parser_values_limits.h"

int			validate_camera(struct s_p_camera *camera)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(*camera->position,
		PARS_POSITION_MIN, PARS_POSITION_MAX)))
	{
		parser_put_error_mapping("position");
		parser_put_error_mapping("camera");
	}
	return (error_code);
}
