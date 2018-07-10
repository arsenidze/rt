/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_defines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:12:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:13:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_DEFINES_H
# define ERRORS_DEFINES_H

# define DRAWER_NEW_MEM					"Not enough memory to init drawer"
# define DRAWER_NEW_SDL_INIT			(char *)SDL_GetError()
# define DRAWER_NEW_SDL_CREATE_WINDOW 	(char *)SDL_GetError()
# define DRAWER_NEW_SDL_CREATE_RENDERER	(char *)SDL_GetError()
# define DRAWER_NEW_SDL_CREATE_TEXTURE 	(char *)SDL_GetError()

# define SCENE_NEW_MEM					"Not enough memory to init scene"

# define CAMERA_NEW_MEM					"Not enough memory to init scene"

# define SCENES_INITIAL_FAIL			"Failed to init scenes"

# define PARSER_PARSE_FAIL				"Parsing failed"
# define PARSER_MEM_FAIL				"Not enough memory for parser"
# define PARSER_NOT_ENOUGH_LINES		"Not enough lines"
# define PARSER_NLINES_FAIL				"Wrong number of lines"

# define PARSER_NOBJECTS_FAIL	"Problem with number of lines for objects"
# define PARSER_NLIGTHS_FAIL	"Problem with number of lines for lights"

# define PARSER_SCENE_ID_FAIL			"Problem with scene identifier"

# define PARSER_CAMERA_ID_FAIL			"Problem with camera identifier"
# define PARSER_CAMERA_POS_FAIL			"Problem with camera position"
# define PARSER_CAMERA_UP_FAIL			"Problem with camera up vector"
# define PARSER_CAMERA_DIRECTION_FAIL	"Problem with camera direction"
# define PARSER_CAMERA_SEPARATOR_FAIL	"Problem with camera separator"
# define PARSER_CAMERA_EOL_FAIL			"Problem with camera end of line"

# define PARSER_OBJECT_ID_FAIL			"Problem with object identifier"
# define PARSER_OBJECT_POS_FAIL			"Problem with object position"
# define PARSER_OBJECT_AMBIENT_FAIL		"Problem with object ambient"
# define PARSER_OBJECT_DIFFUSE_FAIL		"Problem with object diffuse"
# define PARSER_OBJECT_SPECULAR_FAIL	"Problem with object specular"
# define PARSER_OBJECT_SEPARATOR_FAIL	"Problem with object separator"
# define PARSER_OBJECT_PRIMITIVE_FAIL	"Problem with object primitive"
# define PARSER_OBJECT_EOL_FAIL			"Problem with object end of line"

# define PARSER_LIGHT_ID_FAIL			"Problem with light identifier"
# define PARSER_LIGHT_POS_FAIL			"Problem with light position"
# define PARSER_LIGHT_AMBIENT_FAIL		"Problem with light ambient"
# define PARSER_LIGHT_DIFFUSE_FAIL		"Problem with light diffuse"
# define PARSER_LIGHT_SPECULAR_FAIL		"Problem with light specular"
# define PARSER_LIGHT_SEPARATOR_FAIL	"Problem with light separator"
# define PARSER_LIGHT_EOL_FAIL			"Problem with light end of line"

# define PARSER_OBJECT_NLINES			"Problem with number of objects lines"
# define PARSER_LIGHTS_NLINES			"Problem with number of lights lines"

# define PARSER_SPHERE_POS_FAIL			"Problem with sphere position"
# define PARSER_SPHERE_RADIUS_FAIL		"Problem with sphere radius"
# define PARSER_SPHERE_SEPARATOR_FAIL	"Problem with sphere separator"
# define PARSER_SPHERE_EOL_FAIL			"Problem with sphere end of line"

# define PARSER_CONE_POS_FAIL			"Problem with cone position"
# define PARSER_CONE_AXIS_FAIL			"Problem with cone axis vector"
# define PARSER_CONE_SLOPE_FAIL			"Problem with cone slope"
# define PARSER_CONE_SEPARATOR_FAIL		"Problem with cone separator"
# define PARSER_CONE_EOL_FAIL			"Problem with cone end of line"

# define PARSER_CYLINDER_POS_FAIL			"Problem with cylinder position"
# define PARSER_CYLINDER_AXIS_FAIL			"Problem with cylinder axis vector"
# define PARSER_CYLINDER_RADIUS_FAIL		"Problem with cylinder radius"
# define PARSER_CYLINDER_SEPARATOR_FAIL		"Problem with cylinder separator"
# define PARSER_CYLINDER_EOL_FAIL			"Problem with cylinder end of line"

# define PARSER_PLANE_POS_FAIL			"Problem with plane position"
# define PARSER_PLANE_NORMAL_FAIL		"Problem with plane normal"
# define PARSER_PLANE_SEPARATOR_FAIL	"Problem with plane separator"
# define PARSER_PLANE_EOL_FAIL			"Problem with plane end of line"

#endif
