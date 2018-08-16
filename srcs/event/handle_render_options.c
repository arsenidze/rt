/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_render_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:51:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 12:53:53 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "SDL.h"
#include "scene.h"
#include "options.h"
#include "camera.h"
#include "vect3d.h"
#include "mmath.h"

#define MAX_PIXELS 10

short	handle_render_options(int key, t_options *optns, t_scene *scene)
{
	if (key == SDL_SCANCODE_N)
		optns->object_index = clampi(++optns->object_index, 0,
			scene->objects.size - 1);
	else if (key == SDL_SCANCODE_P)
		optns->object_index = clampi(--optns->object_index, 0,
			scene->objects.size - 1);
	else if (key == SDL_SCANCODE_KP_PLUS)
	{
		optns->pixels_step_w = clampi(++optns->pixels_step_w, 1, MAX_PIXELS);
		optns->pixels_step_h = clampi(++optns->pixels_step_h, 1, MAX_PIXELS);
	}
	else if (key == SDL_SCANCODE_KP_MINUS)
	{
		optns->pixels_step_w = clampi(--optns->pixels_step_w, 1, MAX_PIXELS);
		optns->pixels_step_h = clampi(--optns->pixels_step_h, 1, MAX_PIXELS);
	}
	else if (key == SDL_SCANCODE_K)
		optns->is_antialiasing = !optns->is_antialiasing;
	else if (key == SDL_SCANCODE_L)
		optns->is_stereoscopy = !optns->is_stereoscopy;
	else if (key == SDL_SCANCODE_O)
		optns->is_sepia = !optns->is_sepia;
	else if (key == SDL_SCANCODE_I)
		optns->is_black_and_white = !optns->is_black_and_white;
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}
