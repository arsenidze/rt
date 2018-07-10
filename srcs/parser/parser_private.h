/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:31:07 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 18:54:11 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include "parser.h"
# include "camera.h"
# include "object.h"
# include "light.h"
# include "vect3d.h"

# define PARSER_SUCCESS	1
# define PARSER_FAILURE	!PARSER_SUCCESS

/*
**	Length of identifiers
*/
# define ID_LEN(ID)	(sizeof(ID) - 1)

/*
**	Attribute identifiers
*/
# define AMBNT		"ambient"
# define DIFF		"diffuse"
# define SPEC		"specular"
# define POS			"pos"
# define RADIUS		"radius"
# define AXIS		"axis"
# define DIRECTION	"dir"
# define UP			"up"
# define NORMAL		"normal"
# define PRIMIT		"primitive"
# define SLOPE		"slope"
# define SPHERE_ID	"sphere"
# define CYLINDER_ID	"cylinder"
# define CONE_ID		"cone"
# define PLANE_ID	"plane"

# define LEFT_BRACKET	'['
# define RIGHT_BRACKET	']'
# define SEPARATOR		','
# define EOL				';'

# define IS_WHITESPACE(c) ((c) == ' ' || (c) == '\t')
# define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')

# define MAX_NOBJECTS_NDIGITS	2
# define MAX_NLIGHTS_NDIGITS		2

# define MAX_DOUBLE				99999.99999
# define MAX_INT				99999

# define MAX_NDIGITS_INT		5
# define MAX_NDIGITS_FRACT		5
# define MAX_NDIGITS_DOUBLE		(MAX_NDIGITS_INT + 1 + MAX_NDIGITS_FRACT)

# define MIN_POS				-100000
# define MAX_POS				100000
# define MAX_RADIUS				1000
# define MAX_SLOPE				1

t_camera	*parse_camera(char *line);
t_object	**parse_objects(char **lines, int nobjects_expected);
t_light		**parse_lights(char **lines, int nlights_expected);
t_object	*parse_object(char *line);
t_light		*parse_light(char *line);
t_object	*parse_sphere(char *line, t_vect3d components[3]);
t_object	*parse_cylinder(char *line, t_vect3d components[3]);
t_object	*parse_cone(char *line, t_vect3d components[3]);
t_object	*parse_plane(char *line, t_vect3d components[3]);

short		parse_attr_of_type_vect3d(char *line, int *line_index,
			char *attr_name, t_vect3d *res);
short		parse_attr_of_type_double(char *line, int *line_index,
			char *attr_name, double *res);
char		*get_value_of_attr_with_name(char *line, int *line_index,
			char *attr_name);
short		parse_vect3d(char *value, t_vect3d *res, int *nchars_occupied);
short		parse_integer(char *value, int *res, int *nchars_occupied);
short		parse_double(char *value, double *res, int *nchars_occupied);

short		skip_separator(char *line, int *line_index);
short		is_correct_eol(char *end_of_line);
short		is_only_whitespaces(char *line, char terminate_char);
int			str_with_digits_to_int(char *str, int *ndigits);

#endif
