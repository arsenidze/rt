/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ads.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:52:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 17:34:28 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

static int	validate_ads_values(t_vect3d value)
{
	unsigned int	error_code;
	unsigned int	i;

	error_code = 0;
	i = 0;
	while (i < 3)
	{
		if ((error_code = validate_value_float(value[i], 0, 1)))
		{
			parser_put_error_sequence(i);
			return (error_code);
		}
		i++;
	}
	return (0);
}

int			validate_light_ads(struct s_p_light *light)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_ads_values(
					vect3d_from_float(light->ambient))))
		parser_put_error_mapping("ambient");
	else if ((error_code = validate_ads_values(
					vect3d_from_float(light->diffuse))))
		parser_put_error_mapping("diffuse");
	else if ((error_code = validate_ads_values(
					vect3d_from_float(light->specular))))
		parser_put_error_mapping("specular");
	return (error_code);
}

int			validate_obj_ads(struct s_p_material *material)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_ads_values(
					vect3d_from_float(material->ambient))))
		parser_put_error_mapping("ambient");
	else if ((error_code = validate_ads_values(
					vect3d_from_float(material->diffuse))))
		parser_put_error_mapping("diffuse");
	else if ((error_code = validate_ads_values(
					vect3d_from_float(material->specular))))
		parser_put_error_mapping("specular");
	return (error_code);
}
