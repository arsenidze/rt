/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:55:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 23:19:55 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "errors.h"
#include "libft.h"
#include <stdlib.h>

void			scene_delete(t_scene *scene)
{
	int		i;

	(void)i;
	if (!scene)
		return ;
	if (scene->camera)
		camera_delete(scene->camera);
	if (scene->objects)
	{
		i = -1;
		while (scene->objects[++i])
			object_delete(scene->objects[i]);
		free(scene->objects);
	}
	if (scene->lights)
	{
		i = -1;
		while (scene->lights[++i])
			light_delete(scene->lights[i]);
		free(scene->lights);
	}
	free(scene);
}

static void		*scene_err_exit(t_scene *scene, char *err)
{
	scene_delete(scene);
	try_set_err(err);
	return (NULL);
}

t_scene			*scene_new(t_camera *camera, t_object **objects,
				t_light **lights)
{
	t_scene	*scene;

	if (!(scene = malloc(sizeof(t_scene))))
		return (scene_err_exit(scene, SCENE_NEW_MEM));
	scene->camera = camera;
	scene->objects = objects;
	scene->lights = lights;
	return (scene);
}
