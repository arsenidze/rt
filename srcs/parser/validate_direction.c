/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 20:31:13 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/02 15:47:39 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include <stdio.h>

int		validate_direction(float *direction)
{
	if (direction[0] == 0.0 && direction[1] == 0.0 && direction[2] == 0.0)
		return (DIRECTION_CANNOT_BE_NULL_VECTOR);
	return (0);
}
