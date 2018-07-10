/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vect3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:30:48 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:03:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "vect3d.h"

short	parse_vect3d(char *value, t_vect3d *res, int *nchars_occupied)
{
	int			i;
	double		accum[3];
	int			nchars;

	i = 0;
	if (!parse_double(&value[i], &accum[0], &nchars))
		return (PARSER_FAILURE);
	i += nchars;
	if (!skip_separator(value, &i))
		return (PARSER_FAILURE);
	if (!parse_double(&value[i], &accum[1], &nchars))
		return (PARSER_FAILURE);
	i += nchars;
	if (!skip_separator(value, &i))
		return (PARSER_FAILURE);
	if (!parse_double(&value[i], &accum[2], &nchars))
		return (PARSER_FAILURE);
	i += nchars;
	*nchars_occupied = i;
	*res = vect3d(accum[0], accum[1], accum[2]);
	return (PARSER_SUCCESS);
}
