/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/02 17:58:13 by amelihov         ###   ########.fr       */
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
#include "cylinder.h"
#include "texture.h"

#include "rtv1_defines.h"

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

//	objects[0] = object_new(
//	VECT3D_3(vect3d(0.4, 0.4, 0.4),
//		vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4)),
//		0, PRIMITIVE(disc, vect3d(0, 0, -10), vect3d(0, 0, 1), 10));

//	objects[0] = object_new(
//	VECT3D_3(vect3d(0.4, 0.4, 0.4),
//		vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4)),
//		0, PRIMITIVE(cuboid, vect3d(0, 0, 0),
//			(t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0), vect3d(0, 0, 1)},
//			(double[3]){30, 30, 30}));
	
//	objects[0] = object_new(
//	VECT3D_3(vect3d(0.4, 0.4, 0.4),
//		vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4)),
//		0, PRIMITIVE(rect, vect3d(0, 0, -10),
//			(t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
//					vect3d(0, 0, 1)}, (double[]){5, 10}));


	objects[0] = object_new(
	VECT3D_3(vect3d(0.4, 0.4, 0.4),
		vect3d(0.4, 0.4, 0.4), vect3d(0.4, 0.4, 0.4)),
		0, PRIMITIVE(cylinder, vect3d(0, 0, 0), vect3d(0, 0, 1), 10));

	objects[0]->get_tex_coord = cylinder_get_tex_coord;

	SDL_Surface	*surface = SDL_LoadBMP(PATH_TEX"pointillist.bmp");
	if (!surface)
	{
		printf("file in %s on line %d\n", __FILE__, __LINE__);
		exit(1);
	}
	SDL_LockSurface(surface);	
	objects[0]->tex.w = surface->w;
	objects[0]->tex.h = surface->h;
	objects[0]->tex.pitch = surface->pitch;
	objects[0]->tex.pixels = malloc(surface->h * surface->pitch);
	ft_memcpy(objects[0]->tex.pixels, surface->pixels, surface->h * surface->pitch);
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);
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
	drawer = drawer_new(WIN_W, WIN_H, argv[0]);
	if (!drawer)
		return (err_print(PROGNAME": "));
//	scenes = get_scenes_from_file(argv[1]);
	scenes = get_test_scene();
	if (!scenes)
		return (err_print(PROGNAME": "));
	event_handler_loop(drawer, scenes);
	drawer_delete(drawer);
	scene_ptr_arr_delete(scenes);
	return (0);
}
