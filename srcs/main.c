/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/11 14:44:06 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene.h"
#include "event.h"
#include "err.h"
#include "libft.h"
#include "parser.h"
#include "rt_defines.h"

static int	print_usage(void)
{
	ft_putendl(PROGNAME": ""[scene_file]");
	return (1);
}

int			main(int argc, char *argv[])
{
	t_drawer	drawer;
	t_scene		scene;

	if (argc != 2)
		return (print_usage());
	if (drawer_init(&drawer, WIN_W, WIN_H, argv[0]) != DRAWER_SUCCESS)
		return (err_print(PROGNAME": "));
	if (scene_init_from_file(argv[1], &scene) != PARSER_SUCCESS)
		return (1);
	event_handler_loop(&drawer, &scene);
	drawer_deinit(&drawer);
	scene_deinit(&scene);
	return (0);
}
