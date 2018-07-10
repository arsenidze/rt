/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:23:20 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:07:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "object.h"
#include "plane.h"
#include "errors.h"
#include <stddef.h>

static t_object	*parse_plane_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_object		*parse_plane(char *line, t_vect3d components[3])
{
	int			i;
	t_vect3d	pos;
	t_vect3d	normal;

	i = 0;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &pos)
		|| !vect3d_is_in_range(pos, MIN_POS, MAX_POS))
		return (parse_plane_failure(PARSER_PLANE_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_plane_failure(PARSER_PLANE_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, NORMAL, &normal))
		return (parse_plane_failure(PARSER_PLANE_NORMAL_FAIL));
	if (!is_correct_eol(&line[i]))
		return (parse_plane_failure(PARSER_PLANE_EOL_FAIL));
	return (object_new(components, PRIMITIVE(plane, pos, vect3d_norm(normal))));
}
