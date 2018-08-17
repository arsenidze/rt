/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cameara_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:49:25 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 17:10:55 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "SDL.h"
#include "scene.h"
#include "options.h"
#include "camera.h"
#include "vect3d.h"

short	handle_camera_actions(int key, t_options *optns, t_scene *scene)
{
	(void)optns;
	if (key == SDL_SCANCODE_SPACE)
		camera_move(&scene->camera, CAMERA_MOVE_STEP);
	else if (key == SDL_SCANCODE_M)
		camera_move(&scene->camera, -CAMERA_MOVE_STEP);
	else if (key == SDL_SCANCODE_KP_8)
		camera_rotate_oy(&scene->camera, CAMERA_ROT_ANGLE);
	else if (key == SDL_SCANCODE_KP_5)
		camera_rotate_oy(&scene->camera, -CAMERA_ROT_ANGLE);
	else if (key == SDL_SCANCODE_KP_4)
		camera_rotate_oz(&scene->camera, CAMERA_ROT_ANGLE);
	else if (key == SDL_SCANCODE_KP_6)
		camera_rotate_oz(&scene->camera, -CAMERA_ROT_ANGLE);
	else if (key == SDL_SCANCODE_KP_7)
		camera_rotate_ox(&scene->camera, CAMERA_ROT_ANGLE);
	else if (key == SDL_SCANCODE_KP_9)
		camera_rotate_ox(&scene->camera, -CAMERA_ROT_ANGLE);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}
