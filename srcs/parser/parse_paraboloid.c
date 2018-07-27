/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:17:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/27 17:24:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "object.h"
#include "paraboloid.h"
#include "errors.h"
#include <stddef.h>

static t_object	*parse_paraboloid_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_object		*parse_paraboloid(char *line, t_vect3d components[3])
{
	int			i;
	t_vect3d	pos;
	t_vect3d	axis;
	double		k;

	i = 0;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &pos)
		|| !vect3d_is_in_range(pos, MIN_POS, MAX_POS))
		return (parse_paraboloid_failure(PARSER_PARABOLOID_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_paraboloid_failure(PARSER_PARABOLOID_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, AXIS, &axis))
		return (parse_paraboloid_failure(PARSER_PARABOLOID_AXIS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_paraboloid_failure(PARSER_PARABOLOID_SEPARATOR_FAIL));
	if (!parse_attr_of_type_double(line, &i, SLOPE, &k))
		return (parse_paraboloid_failure(PARSER_PARABOLOID_SLOPE_FAIL));
	if (!is_correct_eol(&line[i]))
		return (parse_paraboloid_failure(PARSER_PARABOLOID_EOL_FAIL));
	return (object_new(components, 0, PRIMITIVE(paraboloid, pos, axis, k)));
}
