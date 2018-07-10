/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:58:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 15:22:19 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "object.h"
#include "errors.h"
#include "libft.h"

static short	parse_object_attributes_failure(char *err)
{
	try_set_err(err);
	return (0);
}

static short	parse_object_attributes(char *line, int *i,
				t_vect3d components[3])
{
	if (!parse_attr_of_type_vect3d(line, i, AMBNT, &components[0])
		|| !vect3d_is_in_range(components[0], 0, 1))
		return (parse_object_attributes_failure(PARSER_OBJECT_AMBIENT_FAIL));
	if (!(skip_separator(line, i)))
		return (parse_object_attributes_failure(PARSER_OBJECT_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, i, DIFF, &components[1])
		|| !vect3d_is_in_range(components[1], 0, 1))
		return (parse_object_attributes_failure(PARSER_OBJECT_DIFFUSE_FAIL));
	if (!(skip_separator(line, i)))
		return (parse_object_attributes_failure(PARSER_OBJECT_SEPARATOR_FAIL));
	if (!parse_attr_of_type_vect3d(line, i, SPEC, &components[2])
		|| !vect3d_is_in_range(components[2], 0, 1))
		return (parse_object_attributes_failure(PARSER_OBJECT_SPECULAR_FAIL));
	if (!(skip_separator(line, i)))
		return (parse_object_attributes_failure(PARSER_OBJECT_SEPARATOR_FAIL));
	return (1);
}

static t_object	*(*match_primitive_parser(char *value))(char *line,
					t_vect3d components[3])
{
	if (ft_strnequ(value, SPHERE_ID, ID_LEN(SPHERE_ID)))
		return (&parse_sphere);
	if (ft_strnequ(value, CYLINDER_ID, ID_LEN(CYLINDER_ID)))
		return (&parse_cylinder);
	if (ft_strnequ(value, CONE_ID, ID_LEN(CONE_ID)))
		return (&parse_cone);
	if (ft_strnequ(value, PLANE_ID, ID_LEN(PLANE_ID)))
		return (&parse_plane);
	return (NULL);
}

static t_object	*parse_object_failure(char *err)
{
	try_set_err(err);
	return (NULL);
}

t_object		*parse_object(char *line)
{
	int			i;
	t_vect3d	components[3];
	char		*value;
	t_object	*(*primitive_parser)(char *line, t_vect3d components[3]);

	if (!ft_strnequ(line, "\t"OBJECT_ID":", ID_LEN(OBJECT_ID) + 2))
		return (parse_object_failure(PARSER_OBJECT_ID_FAIL));
	i = ID_LEN(OBJECT_ID) + 2;
	if (!parse_object_attributes(line, &i, components))
		return (parse_object_failure(""));
	if (!(value = get_value_of_attr_with_name(line, &i, PRIMIT)))
		return (parse_object_failure(PARSER_OBJECT_PRIMITIVE_FAIL));
	if (!(primitive_parser = match_primitive_parser(value)))
		return (parse_object_failure(PARSER_OBJECT_PRIMITIVE_FAIL));
	if (!(skip_separator(line, &i)))
		return (parse_object_failure(PARSER_OBJECT_SEPARATOR_FAIL));
	return (primitive_parser(&line[i], components));
}
