/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cameara_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:49:25 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/06 19:17:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "key_defines.h"
#include "options_manipulations_defines.h"
#include "scene.h"
#include "options.h"
#include "camera.h"
#include "vect3d.h"

static inline short	handle_camera_moving_actions(int key, t_scene *scene)
{
	if (key == KEY_CAM_MOVE_FORWARD)
		camera_move_forward_backward(&scene->camera, CAMERA_MOVE_STEP);
	else if (key == KEY_CAM_MOVE_BACKWARD)
		camera_move_forward_backward(&scene->camera, -CAMERA_MOVE_STEP);
	else if (key == KEY_CAM_MOVE_UP)
		camera_move_up_down(&scene->camera, CAMERA_MOVE_STEP);
	else if (key == KEY_CAM_MOVE_DOWN)
		camera_move_up_down(&scene->camera, -CAMERA_MOVE_STEP);
	else if (key == KEY_CAM_MOVE_LEFT)
		camera_move_left_right(&scene->camera, CAMERA_MOVE_STEP);
	else if (key == KEY_CAM_MOVE_RIGHT)
		camera_move_left_right(&scene->camera, -CAMERA_MOVE_STEP);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

static inline short	handle_camera_rotation_actions(int key, t_scene *scene)
{
	if (key == KEY_CAM_ROT_UP)
		camera_rotate_oy(&scene->camera, -CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_DOWN)
		camera_rotate_oy(&scene->camera, CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_RIGHT)
		camera_rotate_oz(&scene->camera, -CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_LEFT)
		camera_rotate_oz(&scene->camera, CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_CLOCKWISE)
		camera_rotate_ox(&scene->camera, -CAMERA_ROT_ANGLE);
	else if (key == KEY_CAM_ROT_COUNTER_CLOCKWISE)
		camera_rotate_ox(&scene->camera, CAMERA_ROT_ANGLE);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

short				handle_camera_actions(int key, t_options *optns,
					t_scene *scene)
{
	(void)optns;
	if (handle_camera_moving_actions(key, scene))
		;
	else if (handle_camera_rotation_actions(key, scene))
		;
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}
