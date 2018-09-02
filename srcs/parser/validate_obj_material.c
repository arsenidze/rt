/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_obj_material.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:32:35 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/02 16:56:44 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "parser_values_limits.h"

int		validate_obj_material(struct s_p_material *material)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_obj_ads(material)))
		;
	else if ((error_code = validate_value_float(material->transparency,
		PARS_TRANSPARENCY_MIN, PARS_TRANSPARENCY_MAX)))
		parser_put_error_mapping("transparency");
	else if ((error_code = validate_value_float(material->reflection,
		PARS_REFLECTION_MIN, PARS_REFLECTION_MAX)))
		parser_put_error_mapping("reflection");
	else if ((error_code = validate_value_float(material->refraction,
		PARS_REFRACTION_MIN, PARS_REFRACTION_MAX)))
		parser_put_error_mapping("refraction");
	else if ((error_code = validate_value_float(material->shininess,
		PARS_SHININESS_MIN, PARS_SHININESS_MAX)))
		parser_put_error_mapping("shininess");
	if (error_code)
		parser_put_error_mapping("material");
	return (error_code);
}
