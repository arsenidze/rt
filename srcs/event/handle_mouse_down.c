/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:45:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 21:59:20 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "SDL.h"
#include "options.h"
#include "scene.h"
#include "canvas.h"
#include "raytracing.h"

short	handle_mouse_down(const SDL_Event *event, t_options *opts,
		t_scene *scene, const t_canvas *canvas)
{
	if (event->button.button != SDL_BUTTON_LEFT)
		return (0);
	opts->object_index = raytracing_get_obj_idx_on_coord(scene,
			event->button.x, event->button.y, canvas);
	return (0);
}
