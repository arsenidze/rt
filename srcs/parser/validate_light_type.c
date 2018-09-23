/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_type_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:30:32 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/17 18:12:11 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "parser_values_limits.h"

int		validate_light_directional(struct s_p_directional *directional)
{
	unsigned int	error_code;

	if (!directional)
		return (0);
	error_code = 0;
	if ((error_code = validate_direction(directional->direction)))
		parser_put_error_mapping("direction");
	return (error_code);
}

int		validate_light_spot(struct s_p_spotlight *spotlight)
{
	unsigned int	error_code;

	if (!spotlight)
		return (0);
	error_code = 0;
	if ((error_code = validate_value_float(spotlight->cut_off,
		PARS_CUTOFF_MIN, PARS_CUTOFF_MAX)))
		parser_put_error_mapping("cut off");
	else if ((error_code = validate_direction(spotlight->direction)))
		parser_put_error_mapping("direction");
	else if ((error_code = validate_vector_float(spotlight->position,
		PARS_POSITION_MIN, PARS_POSITION_MAX)))
		parser_put_error_mapping("position");
	return (error_code);
}

int		validate_light_point(struct s_p_point *point)
{
	unsigned int	error_code;

	if (!point)
		return (0);
	error_code = 0;
	if ((error_code = validate_value_float(point->constant,
		PARS_CONSTANT_MIN, PARS_CONSTANT_MAX)))
		parser_put_error_mapping("constant");
	else if ((error_code = validate_value_float(point->linear,
		PARS_LINEAR_MIN, PARS_QUADRATIC_MAX)))
		parser_put_error_mapping("linear");
	else if ((error_code = validate_value_float(point->quadratic,
		PARS_QUADRATIC_MIN, PARS_QUADRATIC_MAX)))
		parser_put_error_mapping("quadratic");
	else if ((error_code = validate_vector_float(point->position,
		PARS_POSITION_MIN, PARS_POSITION_MAX)))
		parser_put_error_mapping("position");
	return (error_code);
}
