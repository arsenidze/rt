/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:01:14 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 17:08:14 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "SDL.h"
#include "drawer.h"
#include "scene.h"
#include "options.h"
#include "render.h"

static inline void	draw(t_drawer *drawer, const t_scene *scene,
					const t_options *options)
{
	if (options->is_stereoscopy)
		render_on_canvas_with_stereoscopy(scene, &drawer->canvas, options);
	else
		render_on_canvas(scene, &drawer->canvas, options);
	drawer_render_on_window(drawer);
}

void				event_handler_loop(t_drawer *drawer, t_scene *scene)
{
	SDL_Event	event;
	t_options	optns;
	short		need_redraw;

	options_init(&optns);
	draw(drawer, scene, &optns);
	while (!optns.quit && SDL_WaitEvent(&event))
	{
		need_redraw = 0;
		if (event.type == SDL_QUIT)
			optns.quit = 1;
		else if (event.type == SDL_KEYDOWN)
			need_redraw = handle_key_down(&event, &optns, scene,
				&drawer->canvas);
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			need_redraw = handle_mouse_down(&event, &optns, scene,
				&drawer->canvas);
		if (need_redraw)
			draw(drawer, scene, &optns);
	}
}
