/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_torus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:13:47 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/17 14:23:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "object.h"
#include "torus.h"
#include "errors.h"
#include <stddef.h>

static t_object	*parse_torus_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_object		*parse_torus(char *line, t_vect3d components[3])
{
	int			i;
	t_vect3d	pos;
	t_vect3d	axis;
	double		r0;
	double		r1;

	i = 0;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &pos)
		|| !vect3d_is_in_range(pos, MIN_POS, MAX_POS))
		return (parse_torus_failure(PARSER_TORUS_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_torus_failure(PARSER_TORUS_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, AXIS, &axis))
		return (parse_torus_failure(PARSER_TORUS_AXIS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_torus_failure(PARSER_TORUS_SEPARATOR_FAIL));
	if (!parse_attr_of_type_double(line, &i, TOR_R0, &r0)
		|| (r0 < 0 || r0 > MAX_RADIUS))
		return (parse_torus_failure(PARSER_TORUS_RADIUS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_torus_failure(PARSER_TORUS_SEPARATOR_FAIL));
	if (!parse_attr_of_type_double(line, &i, TOR_R1, &r1)
		|| (r1 < 0 || r1 > MAX_RADIUS))
	if (!is_correct_eol(&line[i]))
		return (parse_torus_failure(PARSER_TORUS_EOL_FAIL));
	return (object_new(components, 0, PRIMITIVE(torus, pos,
		vect3d_norm(axis), r0, r1)));
}
