/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:11:32 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 15:14:22 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_PRIVATE_H
# define EVENT_PRIVATE_H

# include "SDL.h"
# include "key_defines.h"

# define NEED_REDRAW 1

# define MAX_PIXELS 10

# define REFLECTION_STEP	0.1
# define REFLECTION_MIN		0
# define REFLECTION_MAX		1
# define TRANSPARENCY_STEP	0.1
# define TRANSPARENCY_MIN	0
# define TRANSPARENCY_MAX	1
# define IOR_STEP			0.1
# define IOR_MIN			1
# define IOR_MAX			5

# define OBJECT_ROT_ANGLE 	(M_PI / 180.0) * 10.0
# define OBJECT_MOVE_STEP 	10

# define CAMERA_ROT_ANGLE 	(M_PI / 180.0) * 10.0
# define CAMERA_MOVE_STEP 	10

# define ADD_AND_CLAMP(v, step, a, b) v = clampd(v + step, a, b)

typedef struct s_options	t_options;
typedef struct s_scene		t_scene;
typedef struct s_canvas		t_canvas;

short	handle_key_down(const SDL_Event *event, t_options *opts,
		t_scene *scene, const t_canvas *canvas);
short	handle_mouse_down(const SDL_Event *event, t_options *opts,
		t_scene *scene, const t_canvas *canvas);
short	handle_object_actions(int key, t_options *optns, t_scene *scene);
short	handle_camera_actions(int key, t_options *optns, t_scene *scene);
short	handle_render_options(int key, t_options *optns, t_scene *scene);
short	handle_technical_effects(int key, t_options *optns, t_scene *scene,
		const t_canvas *canvas);

#endif
