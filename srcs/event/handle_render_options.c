/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_render_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:51:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 16:01:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "SDL.h"
#include "scene.h"
#include "options.h"
#include "mmath.h"

short	handle_render_options(int key, t_options *optns, t_scene *scene)
{
	(void)scene;
	if (key == KEY_PIXELS_STEP_UP)
	{
		ADD_AND_CLAMP(optns->pixels_step_w, 1, 1, MAX_PIXELS);
		ADD_AND_CLAMP(optns->pixels_step_h, 1, 1, MAX_PIXELS);
	}
	else if (key == KEY_PIXELS_STEP_DOWN)
	{
		ADD_AND_CLAMP(optns->pixels_step_w, -1, 1, MAX_PIXELS);
		ADD_AND_CLAMP(optns->pixels_step_h, -1, 1, MAX_PIXELS);
	}
	else if (key == KEY_ANTIALIASING_SWITCH)
		optns->is_antialiasing = !optns->is_antialiasing;
	else if (key == KEY_STEREOSCOPY_SWITCH)
		optns->is_stereoscopy = !optns->is_stereoscopy;
	else if (key == KEY_SEPIA_SWITCH)
		optns->is_sepia = !optns->is_sepia;
	else if (key == KEY_BLACK_AND_WHITE_SWITCH)
		optns->is_black_and_white = !optns->is_black_and_white;
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}
