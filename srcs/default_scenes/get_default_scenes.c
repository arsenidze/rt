/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_default_scenes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 21:39:25 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 16:12:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default_scenes.h"
#include "scene.h"
#include "scene_ptr_arr.h"
#include "errors.h"
#include <stdlib.h>

static void		*get_default_scenes_err_exit(t_scene **scenes, char *err)
{
	scene_ptr_arr_delete(scenes);
	try_set_err(err);
	return (NULL);
}

#define NSCENES 2

static t_scene	*get_scene(short i)
{
	static t_scene	*(*scenes_getters[NSCENES])(void) = {
		get_scene1,
		get_scene2
	};

	if (i < 0 || i >= NSCENES)
		return (NULL);
	return ((*scenes_getters[i])());
}

t_scene			**get_default_scenes(void)
{
	int		i;
	t_scene	**scenes;

	if (!(scenes = malloc(sizeof(t_scene *) * (NSCENES + 1))))
		return (NULL);
	scenes[NSCENES] = NULL;
	i = 0;
	while (i < NSCENES)
	{
		scenes[i] = get_scene(i);
		if (!scenes[i])
			return (get_default_scenes_err_exit(scenes, SCENES_INITIAL_FAIL));
		i++;
	}
	return (scenes);
}
