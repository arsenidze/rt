/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr_of_type_vect3d.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:45:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:00:11 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "libft.h"

short	parse_attr_of_type_vect3d(char *line, int *line_index,
		char *attr_name, t_vect3d *res)
{
	char	*value;
	int		nchars;

	if (!(value = get_value_of_attr_with_name(line, line_index, attr_name)))
		return (PARSER_FAILURE);
	if (!parse_vect3d(value, res, &nchars))
		return (PARSER_FAILURE);
	if (!is_only_whitespaces(&value[nchars], RIGHT_BRACKET))
		return (PARSER_FAILURE);
	return (PARSER_SUCCESS);
}
