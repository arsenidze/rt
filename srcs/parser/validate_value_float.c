/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_value_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:37:04 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/17 18:13:35 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int		validate_vector_float(float *vec, float min_val, float max_val)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (vec[i] > max_val)
			return (VALUE_BIG);
		if (vec[i] < min_val)
			return (VALUE_LOW);
		i++;
	}
	return (0);
}

int		validate_value_float(float val, float min_val, float max_val)
{
	if (val > max_val)
		return (VALUE_BIG);
	if (val < min_val)
		return (VALUE_LOW);
	return (0);
}
