/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:11:32 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 13:56:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_PRIVATE_H
# define EVENT_PRIVATE_H

# include "SDL.h"
# include "key_defines.h"

# define NEED_REDRAW 1
# define CAM_STEP		10
# define CAM_ANGEL		(M_PI / 180.0) * 10.0

# define REFLECTION_STEP	0.1
# define TRANSPARENCY_STEP	0.1
# define IOR_STEP			0.1

# define OBJECT_ROT_ANGLE 	(M_PI / 180.0) * 10.0
# define OBJECT_MOVE_STEP 	10	

typedef struct s_options	t_options;
typedef struct s_scene		t_scene;
typedef struct s_canvas		t_canvas;

short	handle_key_down(const SDL_Event *event, t_options *opts,
		t_scene *scene);
short	handle_mouse_down(const SDL_Event *event, t_options *opts,
		t_scene *scene, const t_canvas *canvas);
short	handle_object_actions(int key, t_options *optns, t_scene *scene);
short	handle_camera_actions(int key, t_options *optns, t_scene *scene);
short	handle_render_options(int key, t_options *optns, t_scene *scene);

#endif
