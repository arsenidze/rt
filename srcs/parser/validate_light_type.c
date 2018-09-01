/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_type_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:30:32 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 17:02:32 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_light_spot(struct s_p_spotlight *spotlight)
{
	unsigned int	error_code;

	if (!spotlight)
		return (0);
	error_code = 0;
	if ((error_code = validate_value_float(spotlight->cut_off, 0, 180)))
		parser_put_error_mapping("cut off");
	return (error_code);
}

int		validate_light_point(struct s_p_point *point)
{
	unsigned int	error_code;

	if (!point)
		return (0);
	error_code = 0;
	if ((error_code = validate_value_float(point->constant, 0, 180)))
		parser_put_error_mapping("constant");
	else if ((error_code = validate_value_float(point->linear, 0, 180)))
		parser_put_error_mapping("linear");
	else if ((error_code = validate_value_float(point->quadratic, 0, 180)))
		parser_put_error_mapping("quadratic");
	return (error_code);
}
