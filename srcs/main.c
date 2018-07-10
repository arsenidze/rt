/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:44:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 18:53:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"
#include "scene_ptr_arr.h"
#include "default_scenes.h"
#include "event_handler_loop.h"
#include "errors.h"
#include "libft.h"

static int	print_usage(void)
{
	ft_putendl(PROGNAME": ""[scene_file]");
	return (1);
}

int			main(int argc, char *argv[])
{
	t_drawer		*drawer;
	t_scene			**scenes;

	if (argc > 2)
		return (print_usage());
	if (argc == 2)
		scenes = get_scenes_from_file(argv[1]);
	else
		scenes = get_default_scenes();
	if (!scenes)
		return (err_print(PROGNAME": "));
	drawer = drawer_new();
	if (!drawer)
		return (err_print(PROGNAME": "));
	event_handler_loop(drawer, scenes);
	drawer_delete(drawer);
	scene_ptr_arr_delete(scenes);
	return (0);
}
