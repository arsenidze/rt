/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:20:13 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:00:47 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "object.h"
#include "cylinder.h"
#include "errors.h"
#include <stddef.h>

static t_object	*parse_cylinder_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_object		*parse_cylinder(char *line, t_vect3d components[3])
{
	int			i;
	t_vect3d	pos;
	t_vect3d	axis;
	double		radius;

	i = 0;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &pos)
		|| !vect3d_is_in_range(pos, MIN_POS, MAX_POS))
		return (parse_cylinder_failure(PARSER_CYLINDER_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_cylinder_failure(PARSER_CYLINDER_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, AXIS, &axis))
		return (parse_cylinder_failure(PARSER_CYLINDER_AXIS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_cylinder_failure(PARSER_CYLINDER_SEPARATOR_FAIL));
	if (!parse_attr_of_type_double(line, &i, RADIUS, &radius)
		|| (radius < 0 || radius > MAX_RADIUS))
		return (parse_cylinder_failure(PARSER_CYLINDER_RADIUS_FAIL));
	if (!is_correct_eol(&line[i]))
		return (parse_cylinder_failure(PARSER_CYLINDER_EOL_FAIL));
	return (object_new(components, PRIMITIVE(cylinder, pos,
		vect3d_norm(axis), radius)));
}
