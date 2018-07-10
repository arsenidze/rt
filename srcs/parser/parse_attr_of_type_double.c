/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr_of_type_double.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:03:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:00:04 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "libft.h"

short	parse_attr_of_type_double(char *line, int *line_index,
		char *attr_name, double *res)
{
	char	*value;
	int		nchars;

	if (!(value = get_value_of_attr_with_name(line, line_index, attr_name)))
		return (PARSER_FAILURE);
	if (!parse_double(value, res, &nchars) || nchars > MAX_NDIGITS_DOUBLE
		|| *res > MAX_DOUBLE || *res < -MAX_DOUBLE)
		return (PARSER_FAILURE);
	if (!is_only_whitespaces(&value[nchars], RIGHT_BRACKET))
		return (PARSER_FAILURE);
	return (PARSER_SUCCESS);
}
