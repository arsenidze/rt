/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/01 16:14:23 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_defines.h"
#include "drawer.h"
#include "scene_ptr_arr.h"
#include "default_scenes.h"
#include "event_handler_loop.h"
#include "errors.h"
#include "libft.h"

//
#include "scene.h"
#include "plane.h"
#include "composed.h"
#include <stdlib.h>
#include "disc.h"
#include "cuboid.h"
#include "rect.h"

#define TEST_SCENE_NOBJECTS	1
#define TEST_SCENE_NLIGHTS		1
t_scene	**get_test_scene(void)
{
	t_scene		*scene;
	t_camera	*camera;
	t_object	**objects;
	t_light		**lights;
//	t_object	**comp_obj;

	if (!(objects = malloc(sizeof(t_object *) * (TEST_SCENE_NOBJECTS + 1))))
		return (NULL);
	objects[TEST_SCENE_NOBJECTS] = NULL;
	if (!(lights = malloc(sizeof(t_light *) * (TEST_SCENE_NLIGHTS + 1))))
		return (NULL);
	lights[TEST_SCENE_NLIGHTS] = NULL;
	camera = camera_new(vect3d(300, 0, 0), vect3d(-1, 0, 0), vect3d(0, 0, 1));

//	if (!(comp_obj = malloc(sizeof(t_object *) * 6)))
//		return (NULL);
//	comp_obj[0] = object_new(
//	VECT3D_3(vect3d(1, 1, 1), vect3d(1, 1, 1), vect3d(1, 1, 1)),
//		0, PRIMITIVE(plane, vect3d(0, 0, -50), vect3d(0, 0, 1)));
//
//	comp_obj[1] = object_new(
//	VECT3D_3(vect3d(1, 1, 1), vect3d(1, 1, 1), vect3d(1, 1, 1)),
//		0, PRIMITIVE(plane, vect3d(0, 0, 50), vect3d(0, 0, -1)));
//
//	comp_obj[2] = object_new(
//	VECT3D_3(vect3d(1, 1, 1), vect3d(1, 1, 1), vect3d(1, 1, 1)),
//		0, PRIMITIVE(plane, vect3d(-50, 0, 0), vect3d(1, 0, 0)));
//
//	comp_obj[3] = object_new(
//	VECT3D_3(vect3d(1, 1, 1), vect3d(1, 1, 1), vect3d(1, 1, 1)),
//		0, PRIMITIVE(plane, vect3d(50, 0, 0), vect3d(-1, 0, 0)));
//
//	comp_obj[4] = object_new(
//	VECT3D_3(vect3d(1, 1, 1), vect3d(1, 1, 1), vect3d(1, 1, 1)),
//		0, PRIMITIVE(plane, vect3d(0, 50, 0), vect3d(0, -1, 0)));
//
//	comp_obj[5] = object_new(
//	VECT3D_3(vect3d(1, 1, 1), vect3d(1, 1, 1), vect3d(1, 1, 1)),
//		0, PRIMITIVE(plane, vect3d(0, -50, 0), vect3d(0, 1, 0)));
//
//	objects[0] = object_new(
//	VECT3D_3(vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4)),
//		0, PRIMITIVE(composed, vect3d(0, 0, 0), comp_obj, 6));
//

//	objects[0] = object_new(
//	VECT3D_3(vect3d(0.4, 0.4, 0.4),
//		vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4)),
//		0, PRIMITIVE(disc, vect3d(0, 0, -10), vect3d(0, 0, 1), 10));


	objects[0] = object_new(
	VECT3D_3(vect3d(0.4, 0.4, 0.4),
		vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4)),
		0, PRIMITIVE(cuboid, vect3d(0, 0, 0),
			(t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0), vect3d(0, 0, 1)},
			(double[3]){30, 30, 30}));

//	objects[0] = object_new(
//	VECT3D_3(vect3d(0.4, 0.4, 0.4),
//		vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4)),
//		0, PRIMITIVE(rect, vect3d(0, 0, -10),
//			(t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
//					vect3d(0, 0, 1)}, (double[]){5, 10}));

	lights[0] = light_new(vect3d(400, 600, 50), VECT3D_3(vect3d(1, 1, 1),
		vect3d(1, 1, 1), vect3d(1, 1, 1)));
	scene = scene_new(camera, objects, lights);
	t_scene **scenes;

	scenes = malloc(sizeof(t_scene *) * (2));
	scenes[0] = scene;
	scenes[1] = NULL;
	return (scenes);
}

//

static int	print_usage(void)
{
	ft_putendl(PROGNAME": ""[scene_file]");
	return (1);
}

int			main(int argc, char *argv[])
{
	t_drawer		*drawer;
	t_scene			**scenes;

	if (argc != 2)
		return (print_usage());
//	scenes = get_scenes_from_file(argv[1]);
	scenes = get_test_scene();
	if (!scenes)
		return (err_print(PROGNAME": "));
	drawer = drawer_new(WIN_W, WIN_H, argv[0]);
	if (!drawer)
		return (err_print(PROGNAME": "));
	event_handler_loop(drawer, scenes);
	drawer_delete(drawer);
	scene_ptr_arr_delete(scenes);
	return (0);
}
