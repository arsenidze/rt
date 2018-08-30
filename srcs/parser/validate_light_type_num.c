/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light_type_num.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:41:07 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/30 17:41:40 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	validate_light_type_num(struct s_p_light *light)
{
	int	type_count;

	type_count = 0;
	if (light->spotlight)
		type_count++;
	if (light->point)
		type_count++;
	if (light->directional)
		type_count++;
	if (type_count > 1)
		return (TOO_MANY_TYPES);
	if (type_count == 0)
		return (TOO_FEW_TYPES);
	return (0);
}
