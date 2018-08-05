/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/05 21:17:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#define NOBJECTS	1
#define NLIGHTS		1

void	get_test_scene(t_scene *scene)
{
	scene->objects = malloc(sizeof(t_object) * (NOBJECTS + 1));
	scene->nobjects = NOBJECTS;
	lights = malloc(sizeof(t_light) * (NLIGHTS + 1));
	camera = camera_new(vect3d(300, 0, 0), vect3d(-1, 0, 0), vect3d(0, 0, 1));

	objects[0].pos = vect3d(0, 0, 0);
	objects[0].basis = (t_basis)(vect3d(1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1));
	PRIMITIVE(&objects[0], cylinder, 50, 100);
	objects[0].material.reflection = 0.3;
	objects[0].material.transparency = 0.3;
	objects[0].texture.pixels = NULL:

	SDL_Surface	*surface = SDL_LoadBMP(PATH_TEX"pointillist.bmp");
	if (!surface)
	{
		printf("file in %s on line %d\n", __FILE__, __LINE__);
		exit(1);
	}
//	SDL_LockSurface(surface);	
//	objects[0]->tex.w = surface->w;
//	objects[0]->tex.h = surface->h;
//	objects[0]->tex.pitch = surface->pitch;
//	objects[0]->tex.pixels = malloc(surface->h * surface->pitch);
//	ft_memcpy(objects[0]->tex.pixels, surface->pixels,
//		surface->h * surface->pitch);
//	SDL_UnlockSurface(surface);
//	SDL_FreeSurface(surface);
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
	t_drawer	drawer;
	t_scene		scene;

//	if (argc != 2)
//		return (print_usage());
	if (drawer_init(&drawer, WIN_W, WIN_H, argv[0]) != DRAWER_SUCCESS)
		return (err_print(PROGNAME": "));
	get_test_scene(&scene);
//	if (scene_init_from_file(&scene, argv[0]) != SCENE_SUCCESS)
//		return (err_print(PROGNAME": "));
	event_handler_loop(drawer, scenes);
	drawer_deinit(&drawer);
	scene_deinit(&scene);
	return (0);
}
