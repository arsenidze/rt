/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_obj_material.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:32:35 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 17:07:54 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_obj_material(struct s_p_material *material)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_obj_ads(material)))
		;
	else if ((error_code = validate_value_float(material->transparency, 0, 1)))
		parser_put_error_mapping("transparency");
	else if ((error_code = validate_value_float(material->reflection, 0, 1)))
		parser_put_error_mapping("reflection");
	else if ((error_code = validate_value_float(material->refraction, 1, 5)))
		parser_put_error_mapping("refraction");
	if (error_code)
		parser_put_error_mapping("material");
	return (error_code);
}
