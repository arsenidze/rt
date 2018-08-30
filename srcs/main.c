/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/30 18:53:37 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "event.h"
#include "err.h"
#include "libft.h"
#include "parser.h"
#include "defines/rt_defines.h"

//
#include "scene.h"
#include <stdlib.h>

//void	get_test_scene2(t_scene *scene)
//{
//	SDL_Surface	*surface = SDL_LoadBMP(PATH_TEX"pointillist.bmp");
//	if (!surface)
//	{
//		printf("file in %s on line %d\n", __FILE__, __LINE__);
//		exit(1);
//	}
//	SDL_LockSurface(surface);	
//	t_texture	tex;
//
//	tex.w = surface->w;
//	tex.h = surface->h;
//	tex.bpp = 3;
//	tex.pixels = malloc(surface->h * surface->pitch);
//	ft_memcpy(tex.pixels, surface->pixels, surface->h * surface->pitch);
//	SDL_UnlockSurface(surface);
//	SDL_FreeSurface(surface);
//
//	scene->objects.data = malloc(sizeof(t_object) * 1);
//	scene->objects.size = 1;
//	scene->lights.data = malloc(sizeof(t_light) * 1);
//	scene->lights.size = 1;
//	scene->camera.pos = vect3d(300, 0, 0);
//	scene->camera.basis = (t_basis){vect3d(-1, 0, 0), vect3d(0, -1, 0),
//						vect3d(0, 0, 1)};
//
//	t_object	*obj_it;
//	obj_it = scene->objects.data;
//	obj_it[0].pos = vect3d(0, 0, 0);
//	obj_it[0].basis = (t_basis){vect3d(1, 0, 0), vect3d(0, 1, 0),
//						vect3d(0, 0, 1)};
//	obj_it[0].shape = SHAPE(sphere, 50);
//	obj_it[0].material.reflection = 0.0;
//	obj_it[0].material.transparency = 0.0;
//	obj_it[0].material.ior = 1.5;
//	obj_it[0].texture.pixels = NULL;
//	texture_load(&obj_it[0].texture, PATH_TEX"pointillist.bmp");
//	obj_it[0].material.ambient = vect3d(0.4, 0.4, 0.4);
//	obj_it[0].material.diffuse = vect3d(0.4, 0.4, 0.4);
//	obj_it[0].material.specular = vect3d(0.4, 0.4, 0.4);
//	obj_it[0].material.shininess = 200;
//
//	t_light	*light_it;
//
//	light_it = scene->lights.data;
////	light_it[0].data.point.pos = vect3d(0, 0, 200);
////	light_it[0].data.point.ambient = vect3d(0.4, 0.4, 0.4);
////	light_it[0].data.point.diffuse = vect3d(0.4, 0.4, 0.4);
////	light_it[0].data.point.specular = vect3d(0.4, 0.4, 0.4);
////	light_it[0].data.point.constant = 1.0;
////	light_it[0].data.point.linear = 0.0014;
////	light_it[0].data.point.quadratic = 0.000007;
//	light_it[0].type = directional;
//	light_it[0].data.directional.ambient = vect3d(0.4, 0.4, 0.4);
//	light_it[0].data.directional.diffuse = vect3d(0.4, 0.4, 0.4);
//	light_it[0].data.directional.specular = vect3d(0.4, 0.4, 0.4);
//	light_it[0].data.directional.dir = vect3d(0, 0, -1);
//}

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
	//get_test_scene2(&scene);
	if (scene_init_from_file(argv[1], &scene) != PARSER_SUCCESS)
		return (err_print(PROGNAME": "));
	scene.camera.basis = (t_basis){vect3d(-1, 0, 0), vect3d(0, -1, 0),
						vect3d(0, 0, 1)};

	event_handler_loop(&drawer, &scene);
	drawer_deinit(&drawer);
	scene_deinit(&scene);
	return (0);
}
