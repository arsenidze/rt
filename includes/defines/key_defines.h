/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_defines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:55:54 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 13:57:16 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_DEFINES_H
# define KEY_DEFINES_H

# include "SDL.h"

# define KEY_TO_QUIT	SDL_SCANCODE_ESCAPE

# define KEY_OBJ_MOVE_FORWARD	SDL_SCANCODE_Z
# define KEY_OBJ_MOVE_BACKWARD	SDL_SCANCODE_Z
# define KEY_OBJ_MOVE_RIGHT		SDL_SCANCODE_Z
# define KEY_OBJ_MOVE_LEFT		SDL_SCANCODE_Z
# define KEY_OBJ_MOVE_UP		SDL_SCANCODE_Z
# define KEY_OBJ_MOVE_DOWN		SDL_SCANCODE_Z

# define KEY_OBJ_ROT_ROLL_CLOCKWISE				SDL_SCANCODE_X	
# define KEY_OBJ_ROT_ROLL_COUNTER_CLOCKWISE		SDL_SCANCODE_X
# define KEY_OBJ_ROT_PITCH_CLOCKWISE			SDL_SCANCODE_X
# define KEY_OBJ_ROT_PITCH_COUNTER_CLOCKWISE	SDL_SCANCODE_X
# define KEY_OBJ_ROT_YAW_CLOCKWISE				SDL_SCANCODE_X
# define KEY_OBJ_ROT_YAW_COUNTER_CLOCKWISE		SDL_SCANCODE_X

# define KEY_OBJ_REFLECTION_UP					SDL_SCANCODE_C
# define KEY_OBJ_REFLECTION_DOWN				SDL_SCANCODE_C
# define KEY_OBJ_TRANSPARENCY_UP				SDL_SCANCODE_C
# define KEY_OBJ_TRANSPARENCY_DOWN				SDL_SCANCODE_C
# define KEY_OBJ_IOR_UP							SDL_SCANCODE_C
# define KEY_OBJ_IOR_DOWN						SDL_SCANCODE_C

#endif
