/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:58:25 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:07:19 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "object.h"
#include "object_ptr_arr.h"
#include "errors.h"
#include "libft.h"

static t_object	**parse_objects_failure(t_object **objects, char *err)
{
	try_set_err(err);
	object_ptr_arr_delete(objects);
	return (NULL);
}

t_object		**parse_objects(char **lines, int nobjects_nexpected)
{
	t_object	**objects;
	int			nlines;
	int			i;

	objects = NULL;
	nlines = ft_get_size_of_str_arr(lines);
	if (nobjects_nexpected > nlines)
		return (parse_objects_failure(objects, PARSER_OBJECT_NLINES));
	if (!(objects = malloc(sizeof(t_object *) * (nobjects_nexpected + 1))))
		return (parse_objects_failure(objects, PARSER_MEM_FAIL));
	objects[nobjects_nexpected] = NULL;
	i = 0;
	while (i < nobjects_nexpected)
	{
		if (!(objects[i] = parse_object(lines[i])))
			return (parse_objects_failure(objects, PARSER_PARSE_FAIL));
		i++;
	}
	return (objects);
}
