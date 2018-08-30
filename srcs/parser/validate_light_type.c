/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_type_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:30:32 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/30 17:40:06 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_180(float n)
{
	if (n > 180)
		return (VALUE_BIG);
	if (n < 0)
		return (VALUE_LOW);
	return (0);
}


int		validate_light_spot(struct s_p_spotlight *spotlight)
{
	unsigned int	error_code;

	if (!spotlight)
		return (0);
	error_code = 0;
	if ((error_code = validate_180(spotlight->cut_off)))
		parser_put_error_mapping("cut off");
	return (error_code);
}

int		validate_light_point(struct s_p_point *point)
{
	unsigned int	error_code;
	
	if (!point)
		return (0);
	error_code = 0;
	if ((error_code = validate_180(point->constant)))
		parser_put_error_mapping("constant");
	else if ((error_code = validate_180(point->linear)))
		parser_put_error_mapping("linear");
	else if ((error_code = validate_180(point->quadratic)))
		parser_put_error_mapping("quadratic");
	return (error_code);
}


