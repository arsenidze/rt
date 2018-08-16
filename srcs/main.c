/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/14 17:42:41 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "event.h"
#include "errors.h"
#include "libft.h"
#include "defines/rt_defines.h"

//
#include "scene.h"
#include <stdlib.h>

#define NOBJECTS	5
#define NLIGHTS		1

void	get_test_scene1(t_scene *scene)
{
	SDL_Surface	*surface = SDL_LoadBMP(PATH_TEX"pointillist.bmp");
	if (!surface)
	{
		printf("file in %s on line %d\n", __FILE__, __LINE__);
		exit(1);
	}
	SDL_LockSurface(surface);	
	t_texture	tex;

	tex.w = surface->w;
	tex.h = surface->h;
	tex.pitch = surface->pitch;
	tex.pixels = malloc(surface->h * surface->pitch);
	ft_memcpy(tex.pixels, surface->pixels, surface->h * surface->pitch);
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);

	scene->objects.data = malloc(sizeof(t_object) * NOBJECTS);
	scene->objects.size = NOBJECTS;
	scene->lights.data = malloc(sizeof(t_light) * NLIGHTS);
	scene->lights.size = NLIGHTS;
	scene->camera.pos = vect3d(300, 0, 0);
	scene->camera.basis = (t_basis){vect3d(-1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};

	t_object	*obj_it;
	obj_it = scene->objects.data;
	obj_it[0].pos = vect3d(0, 0, 0);
	obj_it[0].basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};
	obj_it[0].shape = SHAPE(sphere, 50);
	obj_it[0].material.reflection = 1.0;
	obj_it[0].material.transparency = 1.0;
	obj_it[0].material.ior = 1.5;
	obj_it[0].texture.pixels = NULL;
	obj_it[0].color = vect3d(1, 0, 0);

	obj_it[1].pos = vect3d(-100, 50, 0);
	obj_it[1].basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};
	obj_it[1].shape = SHAPE(sphere, 100);
	obj_it[1].material.reflection = 0.0;
	obj_it[1].material.transparency = 0.0;
	obj_it[1].texture = tex;
	obj_it[1].color = vect3d(0, 1, 0);

	obj_it[2].pos = vect3d(0, 0, -550);
	obj_it[2].basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};
	obj_it[2].shape = SHAPE(sphere, 500);
	obj_it[2].material.reflection = 0.0;
	obj_it[2].material.transparency = 0.0;
	obj_it[2].texture.pixels = NULL;
	obj_it[2].color = vect3d(0.4, 0.4, 0.3);

	obj_it[3].pos = vect3d(-1200, 0, 0);
	obj_it[3].basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};
	obj_it[3].shape = SHAPE(sphere, 1000);
	obj_it[3].material.reflection = 0.0;
	obj_it[3].material.transparency = 0.0;
	obj_it[3].texture.pixels = NULL;
	obj_it[3].color = vect3d(0.4, 0.4, 0.3);

	obj_it[4].pos = vect3d(-400, -200, 0);
	obj_it[4].basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};
	obj_it[4].shape = SHAPE(disk, 20);
	obj_it[4].material.reflection = 0.0;
	obj_it[4].material.transparency = 0.0;
	obj_it[4].texture.pixels = NULL;
	obj_it[4].color = vect3d(0.4, 0.8, 0.6);

	t_light	*light_it;

	light_it = scene->lights.data;
	light_it[0].pos = vect3d(0, 0, 500);
	light_it[0].components[L_AMBIENT] = vect3d(0.3, 0.3, 0.3);
	light_it[0].components[L_DIFFUSE] = vect3d(0.3, 0.3, 0.3);
	light_it[0].components[L_SPECULAR] = vect3d(0.3, 0.3, 0.3);
}
//

void	get_test_scene2(t_scene *scene)
{
	SDL_Surface	*surface = SDL_LoadBMP(PATH_TEX"pointillist.bmp");
	if (!surface)
	{
		printf("file in %s on line %d\n", __FILE__, __LINE__);
		exit(1);
	}
	SDL_LockSurface(surface);	
	t_texture	tex;

	tex.w = surface->w;
	tex.h = surface->h;
	tex.pitch = surface->pitch;
	tex.pixels = malloc(surface->h * surface->pitch);
	ft_memcpy(tex.pixels, surface->pixels, surface->h * surface->pitch);
	SDL_UnlockSurface(surface);
	SDL_FreeSurface(surface);

	scene->objects.data = malloc(sizeof(t_object) * 2);
	scene->objects.size = 2;
	scene->lights.data = malloc(sizeof(t_light) * 1);
	scene->lights.size = 1;
	scene->camera.pos = vect3d(300, 0, 0);
	scene->camera.basis = (t_basis){vect3d(-1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};

	t_object	*obj_it;
	obj_it = scene->objects.data;
	obj_it[0].pos = vect3d(0, 0, 0);
	obj_it[0].basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};
	obj_it[0].shape = SHAPE(cuboid, (double[3]){40, 40, 40});
	obj_it[0].material.reflection = 0.0;
	obj_it[0].material.transparency = 0.0;
	obj_it[0].material.ior = 1.5;
	obj_it[0].texture = tex;
	obj_it[0].color = vect3d(1, 0, 0);


	obj_it[1].pos = vect3d(0, 100, 0);
	obj_it[1].basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
						vect3d(0, 0, 1)};
	obj_it[1].shape = SHAPE(sphere, 50);
	obj_it[1].material.reflection = 0.0;
	obj_it[1].material.transparency = 0.0;
	obj_it[1].material.ior = 1.5;
	obj_it[1].texture.pixels = NULL;
	obj_it[1].color = vect3d(0, 0, 1);

	t_light	*light_it;

	light_it = scene->lights.data;
	light_it[0].pos = vect3d(0, 0, 10);
	light_it[0].components[L_AMBIENT] = vect3d(0.3, 0.3, 0.3);
	light_it[0].components[L_DIFFUSE] = vect3d(0.3, 0.3, 0.3);
	light_it[0].components[L_SPECULAR] = vect3d(0.3, 0.3, 0.3);
}

static int	print_usage(void)
{
	ft_putendl(PROGNAME": ""[scene_file]");
	return (1);
}

int			main(int argc, char *argv[])
{
	t_drawer	drawer;
	t_scene		scene;

	if (argc == 22)
		return (print_usage());
	if (drawer_init(&drawer, WIN_W, WIN_H, argv[0]) != DRAWER_SUCCESS)
		return (err_print(PROGNAME": "));
	//get_test_scene1(&scene);
	get_test_scene2(&scene);
//	if (scene_init_from_file(&scene, argv[0], &drawer) != SCENE_SUCCESS)
//		return (err_print(PROGNAME": "));
	event_handler_loop(&drawer, &scene);
	drawer_deinit(&drawer);
	scene_deinit(&scene);
	return (0);
}
