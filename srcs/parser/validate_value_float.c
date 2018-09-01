/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_value_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:37:04 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 16:40:01 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_value_float(float val, float min_val, float max_val)
{
	if (val > max_val)
		return (VALUE_BIG);
	if (val < min_val)
		return (VALUE_LOW);
	return (0);
}
