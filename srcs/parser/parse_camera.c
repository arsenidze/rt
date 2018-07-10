/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:58:09 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 18:48:36 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "camera.h"
#include "errors.h"
#include "libft.h"

static t_camera	*parse_camera_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_camera		*parse_camera(char *line)
{
	int			i;
	t_vect3d	components[3];

	if (!ft_strnequ(line, "\t"CAMERA_ID":", ID_LEN(CAMERA_ID) + 2))
		return (parse_camera_failure(PARSER_CAMERA_ID_FAIL));
	i = ID_LEN(CAMERA_ID) + 2;
	if (!parse_attr_of_type_vect3d(line, &i, POS, &components[0])
		|| !vect3d_is_in_range(components[0], MIN_POS, MAX_POS))
		return (parse_camera_failure(PARSER_CAMERA_POS_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_camera_failure(PARSER_CAMERA_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, DIRECTION, &components[1]))
		return (parse_camera_failure(PARSER_CAMERA_DIRECTION_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_camera_failure(PARSER_CAMERA_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, &i, UP, &components[2]))
		return (parse_camera_failure(PARSER_CAMERA_UP_FAIL));
	if (!is_correct_eol(&line[i]))
		return (parse_camera_failure(PARSER_CAMERA_EOL_FAIL));
	return (camera_new(components[0], vect3d_norm(components[1]),
		vect3d_norm(components[2])));
}
