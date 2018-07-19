/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:01:14 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/17 20:27:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "drawer.h"
#include "scene.h"
#include "scene_ptr_arr.h"
#include "object_ptr_arr.h"
#include "sphere.h"
#include "userinput.h"
#include "raytracing.h"
#include "parallelism.h"
#include "vect3d.h"
#include "mmath.h"
#include "libft.h"

void	move_current_object(t_scene **scenes, t_userinput *userinput,
		t_vect3d step)
{
	((t_sphere*)(scenes[userinput->scene_index]
		->objects[userinput->object_index]
		->primitive))->pos += step;
}

#define NEED_REDRAW			1
#define DELTA_CAM_STEP		10
#define DELTA_CAM_ANGEL		(M_PI / 180.0) * 10.0

short	cam_actions(int key, t_userinput *ui, t_scene **scenes)
{
	if (key == SDL_SCANCODE_SPACE)
		camera_move(scenes[ui->scene_index]->camera, DELTA_CAM_STEP);
	else if (key == SDL_SCANCODE_M)
		camera_move(scenes[ui->scene_index]->camera, -DELTA_CAM_STEP);
	else if (key == SDL_SCANCODE_KP_8)
		camera_rotate_oy(scenes[ui->scene_index]->camera, DELTA_CAM_ANGEL);
	else if (key == SDL_SCANCODE_KP_5)
		camera_rotate_oy(scenes[ui->scene_index]->camera, -DELTA_CAM_ANGEL);
	else if (key == SDL_SCANCODE_KP_4)
		camera_rotate_oz(scenes[ui->scene_index]->camera, DELTA_CAM_ANGEL);
	else if (key == SDL_SCANCODE_KP_6)
		camera_rotate_oz(scenes[ui->scene_index]->camera, -DELTA_CAM_ANGEL);
	else if (key == SDL_SCANCODE_KP_7)
		camera_rotate_ox(scenes[ui->scene_index]->camera, DELTA_CAM_ANGEL);
	else if (key == SDL_SCANCODE_KP_9)
		camera_rotate_ox(scenes[ui->scene_index]->camera, -DELTA_CAM_ANGEL);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

short	object_actions(int key, t_userinput *userinput,
		t_scene **scenes)
{
	if (key == SDL_SCANCODE_Q)
		move_current_object(scenes, userinput, vect3d(DELTA_CAM_STEP, 0, 0));
	else if (key == SDL_SCANCODE_A)
		move_current_object(scenes, userinput, vect3d(-DELTA_CAM_STEP, 0, 0));
	else if (key == SDL_SCANCODE_W)
		move_current_object(scenes, userinput, vect3d(0, DELTA_CAM_STEP, 0));
	else if (key == SDL_SCANCODE_S)
		move_current_object(scenes, userinput, vect3d(0, -DELTA_CAM_STEP, 0));
	else if (key == SDL_SCANCODE_E)
		move_current_object(scenes, userinput, vect3d(0, 0, DELTA_CAM_STEP));
	else if (key == SDL_SCANCODE_D)
		move_current_object(scenes, userinput, vect3d(0, 0, -DELTA_CAM_STEP));
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

#define MAX_PIXELS			10

short	handle_key_down(int key, t_userinput *ui, t_scene **scenes)
{
	if (key == SDL_SCANCODE_ESCAPE && (ui->quit = 1))
		return (!NEED_REDRAW);
	else if (key == SDL_SCANCODE_KP_MULTIPLY)
	{
		ui->scene_index = clampi(++ui->scene_index, 0, ui->nscenes - 1);
		ui->nobjects = object_ptr_arr_size(scenes[ui->scene_index]->objects);
	}
	else if (key == SDL_SCANCODE_KP_DIVIDE)
	{
		ui->scene_index = clampi(--ui->scene_index, 0, ui->nscenes - 1);
		ui->nobjects = object_ptr_arr_size(scenes[ui->scene_index]->objects);
	}
	else if (key == SDL_SCANCODE_N)
		ui->object_index = clampi(++ui->object_index, 0, ui->nobjects - 1);
	else if (key == SDL_SCANCODE_P)
		ui->object_index = clampi(--ui->object_index, 0, ui->nobjects - 1);
	else if (key == SDL_SCANCODE_KP_PLUS)
		ui->step_in_pixels = clampi(++ui->step_in_pixels, 1, MAX_PIXELS);
	else if (key == SDL_SCANCODE_KP_MINUS)
		ui->step_in_pixels = clampi(--ui->step_in_pixels, 1, MAX_PIXELS);
	else if (key == SDL_SCANCODE_K)
		ui->is_antialiasing = 1;
	else if (key == SDL_SCANCODE_L)
		ui->is_antialiasing = 0;
	else if ((cam_actions(key, ui, scenes) || object_actions(key, ui, scenes)))
		;
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

static inline void	draw(t_drawer *drawer, t_scene *scene,
					const t_userinput *userinput)
{
	render_scene_parallel(scene, drawer->canvas, userinput);
//	render_scene(scene, (t_canvas){drawer->canvas.pixels,
//						.w = drawer->canvas.w, .h = drawer->canvas.h},
//						userinput);
	drawer_render(drawer);
	//exit(1);
}

void	event_handler_loop(t_drawer *drawer, t_scene **scenes)
{
	SDL_Event	event;
	t_userinput	ui;

	srand(time(0));
	init_userinput(&ui, object_ptr_arr_size(scenes[0]->objects),
						scene_ptr_arr_size(scenes));
	draw(drawer, scenes[ui.scene_index], &ui);
	while (!ui.quit)
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				ui.quit = 1;
				break ;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (handle_key_down(event.key.keysym.scancode, &ui, scenes))
				{
					draw(drawer, scenes[ui.scene_index], &ui);
				}
			}
		}
}
