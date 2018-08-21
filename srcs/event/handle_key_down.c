/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:01:13 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 20:09:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "event_private.h"
#include "key_defines.h"
#include "SDL.h"
#include "scene.h"
#include "options.h"

short	handle_key_down(const SDL_Event *event, t_options *optns,
		t_scene *scene, const t_canvas *canvas)
{
	int	key;

	key = event->key.keysym.scancode;
	if (key == KEY_TO_QUIT && (optns->quit = 1))
		return (!NEED_REDRAW);
	else if (handle_object_actions(key, optns, scene))
		;
	else if (handle_camera_actions(key, optns, scene))
		;
	else if (handle_render_options(key, optns, scene))
		;
	else if (handle_technical_effects(key, optns, scene, canvas))
		;
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}
