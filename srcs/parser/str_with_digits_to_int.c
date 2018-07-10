/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_with_digits_to_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:44:03 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 23:03:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	str_with_digits_to_int(char *str, int *ndigits)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	else
		sign = 1;
	res = 0;
	while (IS_DIGIT(str[i]))
	{
		res = 10 * res + (str[i] - '0');
		i++;
	}
	*ndigits = i;
	return (sign * res);
}
