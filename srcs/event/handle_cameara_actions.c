/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cameara_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:49:25 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 20:08:48 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "key_defines.h"
#include "options_manipulations_defines.h"
#include "scene.h"
#include "options.h"
#include "camera.h"
#include "vect3d.h"

short	handle_camera_actions(int key, t_options *optns, t_scene *scene)
{
	(void)optns;
	if (key == KEY_CAM_MOVE_FORWARD)
		camera_move(&scene->camera, CAMERA_MOVE_STEP);
	else if (key == KEY_CAM_MOVE_BACKWARD)
		camera_move(&scene->camera, -CAMERA_MOVE_STEP);
	else if (key == KEY_CAM_ROT_UP)
		camera_rotate_oy(&scene->camera, CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_DOWN)
		camera_rotate_oy(&scene->camera, -CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_RIGHT)
		camera_rotate_oz(&scene->camera, CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_LEFT)
		camera_rotate_oz(&scene->camera, -CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_CLOCKWISE)
		camera_rotate_ox(&scene->camera, CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_COUNTER_CLOCKWISE)
		camera_rotate_ox(&scene->camera, -CAMERA_ROT_ANGLE);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}
