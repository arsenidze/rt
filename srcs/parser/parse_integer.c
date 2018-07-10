/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:08:37 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 17:19:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

short	parse_integer(char *value, int *res, int *nchars_occupied)
{
	int	i;
	int	int_part;
	int	ndigits;

	i = 0;
	while (value[i] && IS_WHITESPACE(value[i]))
		i++;
	int_part = str_with_digits_to_int(&value[i], &ndigits);
	if (ndigits == 0 || ndigits > MAX_NDIGITS_INT || int_part > MAX_INT
		|| int_part < -MAX_INT)
		return (PARSER_FAILURE);
	*res = int_part;
	*nchars_occupied = i + ndigits;
	return (PARSER_SUCCESS);
}
