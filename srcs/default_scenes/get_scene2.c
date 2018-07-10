/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:14:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 16:11:40 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "sphere.h"
#include "plane.h"
#include "cylinder.h"
#include <stdlib.h>

#define SECOND_SCENE_NOBJECTS	3
#define SECOND_SCENE_NLIGHTS	1

t_scene	*get_scene2(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object	**objects;
	t_light		**lights;

	if (!(objects = malloc(sizeof(t_object *) * (SECOND_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[SECOND_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (SECOND_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[SECOND_SCENE_NLIGHTS] = NULL;
	camera = camera_new(vect3d(1000, 0, 0), vect3d(-1, 0, 0), vect3d(0, 0, 1));
	objects[0] = object_new(
	VECT3D_3(vect3d(0.2, 0.2, 0.2), vect3d(0.3, 0.2, 0.2), vect3d(1, 1, 1)),
		PRIMITIVE(plane, vect3d(0, 0, -100), vect3d(0, 0, 1)));
	objects[1] = object_new(
	VECT3D_3(vect3d(0.05, 0.1, 0.2), vect3d(0.05, 0.1, 0.2), vect3d(0, 0, 0)),
		PRIMITIVE(plane, vect3d(-200, 0, 0), vect3d(1, 0, 0)));
	objects[2] = object_new(
	VECT3D_3(vect3d(0.05, 0.1, 0.2), vect3d(0.05, 0.1, 0.2), vect3d(0, 0, 0)),
		PRIMITIVE(cylinder, vect3d(0, -200, 0), vect3d(0, 0, 1), 40));
	lights[0] = light_new(vect3d(500, 600, 200), VECT3D_3(vect3d(1, 1, 1),
		vect3d(1, 1, 1), vect3d(1, 1, 1)));
	scene = scene_new(camera, objects, lights);
	return (scene);
}
