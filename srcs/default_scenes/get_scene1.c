/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:13:55 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 16:11:33 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include <stdlib.h>

#define FIRST_SCENE_NOBJECTS	1
#define FIRST_SCENE_NLIGHTS		1

t_scene	*get_scene1(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object	**objects;
	t_light		**lights;

	if (!(objects = malloc(sizeof(t_object *) * (FIRST_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[FIRST_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (FIRST_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[FIRST_SCENE_NLIGHTS] = NULL;
	camera = camera_new(vect3d(500, 0, 0), vect3d(-1, 0, 0), vect3d(0, 0, 1));
	objects[0] = object_new(
	VECT3D_3(vect3d(0.05, 0., 0.), vect3d(0.25, 0., 0.), vect3d(0.4, 0.4, 0.4)),
		PRIMITIVE(sphere, vect3d(-100, 0, 0), 100));
	lights[0] = light_new(vect3d(400, 600, 50), VECT3D_3(vect3d(1, 1, 1),
		vect3d(1, 1, 1), vect3d(1, 1, 1)));
	scene = scene_new(camera, objects, lights);
	return (scene);
}
