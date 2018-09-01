/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:22:06 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 17:30:55 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

static int	validate_light(struct s_p_light *light)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_light_type_num(light)))
		return (error_code);
	if ((error_code = validate_light_ads(light)))
		return (error_code);
	if ((error_code = validate_light_spot(light->spotlight)))
		return (error_code);
	if ((error_code = validate_light_point(light->point)))
		return (error_code);
	return (0);
}

int			validate_lights(struct s_p_light *lights,
	unsigned int lights_count)
{
	unsigned int	error_code;
	unsigned int	i;

	error_code = 0;
	i = 0;
	while (i < lights_count)
	{
		if ((error_code = validate_light(&lights[i])))
		{
			parser_put_error_sequence(i);
			parser_put_error_mapping("lights");
			return (error_code);
		}
		i++;
	}
	return (0);
}
