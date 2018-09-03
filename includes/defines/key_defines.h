/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_defines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:55:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/03 18:37:10 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_DEFINES_H
# define KEY_DEFINES_H

# include "SDL.h"

# define KEY_TO_QUIT	SDL_SCANCODE_ESCAPE

# define KEY_OBJ_MOVE_FORWARD	SDL_SCANCODE_Q
# define KEY_OBJ_MOVE_BACKWARD	SDL_SCANCODE_A
# define KEY_OBJ_MOVE_RIGHT		SDL_SCANCODE_W
# define KEY_OBJ_MOVE_LEFT		SDL_SCANCODE_S
# define KEY_OBJ_MOVE_UP		SDL_SCANCODE_E
# define KEY_OBJ_MOVE_DOWN		SDL_SCANCODE_D

# define KEY_OBJ_ROT_ROLL_CLOCKWISE				SDL_SCANCODE_R
# define KEY_OBJ_ROT_ROLL_COUNTER_CLOCKWISE		SDL_SCANCODE_F
# define KEY_OBJ_ROT_PITCH_CLOCKWISE			SDL_SCANCODE_T
# define KEY_OBJ_ROT_PITCH_COUNTER_CLOCKWISE	SDL_SCANCODE_G
# define KEY_OBJ_ROT_YAW_CLOCKWISE				SDL_SCANCODE_Y
# define KEY_OBJ_ROT_YAW_COUNTER_CLOCKWISE		SDL_SCANCODE_H

# define KEY_OBJ_REFLECTION_UP					SDL_SCANCODE_U
# define KEY_OBJ_REFLECTION_DOWN				SDL_SCANCODE_J
# define KEY_OBJ_TRANSPARENCY_UP				SDL_SCANCODE_I
# define KEY_OBJ_TRANSPARENCY_DOWN				SDL_SCANCODE_K
# define KEY_OBJ_IOR_UP							SDL_SCANCODE_O
# define KEY_OBJ_IOR_DOWN						SDL_SCANCODE_L

# define KEY_PIXELS_STEP_UP			SDL_SCANCODE_KP_PLUS
# define KEY_PIXELS_STEP_DOWN		SDL_SCANCODE_KP_MINUS
# define KEY_ANTIALIASING_SWITCH	SDL_SCANCODE_1
# define KEY_STEREOSCOPY_SWITCH		SDL_SCANCODE_2
# define KEY_SEPIA_SWITCH			SDL_SCANCODE_3
# define KEY_BLACK_AND_WHITE_SWITCH	SDL_SCANCODE_4

# define KEY_CAM_MOVE_FORWARD	SDL_SCANCODE_UP
# define KEY_CAM_MOVE_BACKWARD	SDL_SCANCODE_DOWN

# define KEY_CAM_ROT_UP					SDL_SCANCODE_KP_8
# define KEY_CAM_ROT_DOWN				SDL_SCANCODE_KP_5
# define KEY_CAM_ROT_LEFT				SDL_SCANCODE_KP_4
# define KEY_CAM_ROT_RIGHT				SDL_SCANCODE_KP_6
# define KEY_CAM_ROT_CLOCKWISE			SDL_SCANCODE_KP_7
# define KEY_CAM_ROT_COUNTER_CLOCKWISE	SDL_SCANCODE_KP_9

# define KEY_TO_MAKE_SCREENSHOT		SDL_SCANCODE_P

#endif
