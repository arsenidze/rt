/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ads.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:52:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/30 17:36:59 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

static int	validate_ads_values(t_vect3d value)
{
	unsigned int	i;

	i = 0;
	while (i < 3)
	{
		if (value[i] < 0)
		{
			parser_put_error_sequence(i);
			return (VALUE_LOW);
		}
		if (value[i] > 1)
		{
			parser_put_error_sequence(i);
			return (VALUE_BIG);
		}	
		i++;
	}
	return (0);
}

int	validate_light_ads(struct s_p_light *light)
{
	unsigned int	error_code;
	
	error_code = 0;
	if ((error_code = validate_ads_values(vect3d_from_float(light->ambient))))
		parser_put_error_mapping("ambient");
	else if ((error_code = validate_ads_values(vect3d_from_float(light->diffuse))))
		parser_put_error_mapping("diffuse");
	else if ((error_code = validate_ads_values(vect3d_from_float(light->specular))))
		parser_put_error_mapping("specular");
	return (error_code);
}
