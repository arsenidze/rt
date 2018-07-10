/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:57:44 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:07:51 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "scene.h"
#include "errors.h"
#include "libft.h"

static t_scene	*parser_parse_scene_failure(t_scene *scene, char *err)
{
	try_set_err(err);
	scene_delete(scene);
	return (NULL);
}

#define MINIMUM_NLINES 4

static t_scene	*prepare_scene(char **lines, int *nlines, int *nobjects,
				int *nlights)
{
	t_scene	*scene;
	int		ndigits;

	scene = NULL;
	*nlines = ft_get_size_of_str_arr(lines);
	if (*nlines == -1 || *nlines < MINIMUM_NLINES)
		return (parser_parse_scene_failure(scene, PARSER_NOT_ENOUGH_LINES));
	if (!parse_integer(lines[0], nobjects, &ndigits)
		|| ndigits > MAX_NOBJECTS_NDIGITS || *nobjects > MAX_NOBJECTS)
		return (parser_parse_scene_failure(scene, PARSER_NOBJECTS_FAIL));
	if (!parse_integer(lines[1], nlights, &ndigits)
		|| ndigits > MAX_NLIGHTS_NDIGITS || *nlights > MAX_NLIGHTS)
		return (parser_parse_scene_failure(scene, PARSER_NLIGTHS_FAIL));
	if (*nlines != *nobjects + *nlights + MINIMUM_NLINES)
		return (parser_parse_scene_failure(scene, PARSER_NLINES_FAIL));
	if (!ft_strequ(lines[2], SCENE_ID":"))
		return (parser_parse_scene_failure(scene, PARSER_SCENE_ID_FAIL));
	if (!(scene = malloc(sizeof(t_scene))))
		return (parser_parse_scene_failure(scene, PARSER_MEM_FAIL));
	ft_memset(scene, 0, sizeof(t_scene));
	return (scene);
}

t_scene			*parser_parse_scene(char **lines)
{
	t_scene	*scene;
	int		nlines;
	int		nobjects;
	int		nlights;

	scene = NULL;
	if (!(scene = prepare_scene(lines, &nlines, &nobjects, &nlights)))
		return (parser_parse_scene_failure(scene, PARSER_PARSE_FAIL));
	if (!(scene->camera = parse_camera(lines[3])))
		return (parser_parse_scene_failure(scene, PARSER_PARSE_FAIL));
	if (!(scene->objects = parse_objects(&lines[4], nobjects)))
		return (parser_parse_scene_failure(scene, PARSER_PARSE_FAIL));
	if (!(scene->lights = parse_lights(&lines[4 + nobjects],
		nlights)))
		return (parser_parse_scene_failure(scene, PARSER_PARSE_FAIL));
	return (scene);
}
