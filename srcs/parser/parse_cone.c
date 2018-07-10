/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:20:18 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:00:30 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "object.h"
#include "cone.h"
#include "errors.h"
#include <stddef.h>

static t_object	*parse_cone_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_object		*parse_cone(char *line, t_vect3d components[3])
{
	int			i;
	t_vect3d	pos;
	t_vect3d	axis;
	double		slope;

	i = 0;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &pos)
		|| !vect3d_is_in_range(pos, MIN_POS, MAX_POS))
		return (parse_cone_failure(PARSER_CONE_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_cone_failure(PARSER_CONE_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, AXIS, &axis))
		return (parse_cone_failure(PARSER_CONE_AXIS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_cone_failure(PARSER_CONE_SEPARATOR_FAIL));
	if (!parse_attr_of_type_double(line, &i, SLOPE, &slope)
		|| (slope <= 0 || slope > MAX_SLOPE))
		return (parse_cone_failure(PARSER_CONE_SLOPE_FAIL));
	if (!is_correct_eol(&line[i]))
		return (parse_cone_failure(PARSER_CONE_EOL_FAIL));
	return (object_new(components, PRIMITIVE(cone, pos,
		vect3d_norm(axis), slope)));
}
