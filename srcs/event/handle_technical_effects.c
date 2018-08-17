/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_technical_effects.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:16:07 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 17:22:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "options.h"
#include "scene.h"
#include "canvas.h"
#include "technical_effect.h"

short	handle_technical_effects(int key, t_options *optns, t_scene *scene,
		const t_canvas *canvas)
{
	(void)optns;
	(void)scene;
	(void)canvas;
	if (key == KEY_TO_MAKE_SCREENSHOT)
		technical_effect_make_screenshot(canvas);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}
