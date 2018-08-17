/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_object_actions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:39:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 15:15:50 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_private.h"
#include "SDL.h"
#include "scene.h"
#include "options.h"
#include "vect3d.h"
#include "mmath.h"

static short	handle_object_material_parameters(int key, t_object *obj)
{
	if (key == KEY_OBJ_REFLECTION_UP)
		ADD_AND_CLAMP(obj->material.reflection, REFLECTION_STEP,
			REFLECTION_MIN, REFLECTION_MAX);
	else if (key == KEY_OBJ_REFLECTION_DOWN)
		ADD_AND_CLAMP(obj->material.reflection, -REFLECTION_STEP,
			REFLECTION_MIN, REFLECTION_MAX);
	else if (key == KEY_OBJ_TRANSPARENCY_UP)
		ADD_AND_CLAMP(obj->material.transparency, TRANSPARENCY_STEP,
			TRANSPARENCY_MIN, TRANSPARENCY_MAX);
	else if (key == KEY_OBJ_TRANSPARENCY_DOWN)
		ADD_AND_CLAMP(obj->material.transparency, -TRANSPARENCY_STEP,
			TRANSPARENCY_MIN, TRANSPARENCY_MAX);
	else if (key == KEY_OBJ_IOR_UP)
		ADD_AND_CLAMP(obj->material.ior, IOR_STEP, IOR_MIN, IOR_MAX);
	else if (key == KEY_OBJ_IOR_DOWN)
		ADD_AND_CLAMP(obj->material.ior, -IOR_STEP, IOR_MIN, IOR_MAX);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

static short	handle_object_rotation(int key, t_object *obj)
{
	if (key == KEY_OBJ_ROT_ROLL_CLOCKWISE)
		obj->basis = basis_rotate_ox(obj->basis, OBJECT_ROT_ANGLE);
	else if (key == KEY_OBJ_ROT_ROLL_COUNTER_CLOCKWISE)
		obj->basis = basis_rotate_ox(obj->basis, -OBJECT_ROT_ANGLE);
	else if (key == KEY_OBJ_ROT_PITCH_CLOCKWISE)
		obj->basis = basis_rotate_oy(obj->basis, OBJECT_ROT_ANGLE);
	else if (key == KEY_OBJ_ROT_PITCH_COUNTER_CLOCKWISE)
		obj->basis = basis_rotate_oy(obj->basis, -OBJECT_ROT_ANGLE);
	else if (key == KEY_OBJ_ROT_YAW_CLOCKWISE)
		obj->basis = basis_rotate_oz(obj->basis, OBJECT_ROT_ANGLE);
	else if (key == KEY_OBJ_ROT_YAW_COUNTER_CLOCKWISE)
		obj->basis = basis_rotate_oz(obj->basis, -OBJECT_ROT_ANGLE);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

static short	handle_object_movement(int key, t_object *obj)
{
	if (key == KEY_OBJ_MOVE_FORWARD)
		obj->pos += vect3d(OBJECT_MOVE_STEP, 0, 0);
	else if (key == KEY_OBJ_MOVE_BACKWARD)
		obj->pos += vect3d(-OBJECT_MOVE_STEP, 0, 0);
	else if (key == KEY_OBJ_MOVE_RIGHT)
		obj->pos += vect3d(0, OBJECT_MOVE_STEP, 0);
	else if (key == KEY_OBJ_MOVE_LEFT)
		obj->pos += vect3d(0, -OBJECT_MOVE_STEP, 0);
	else if (key == KEY_OBJ_MOVE_UP)
		obj->pos += vect3d(0, 0, OBJECT_MOVE_STEP);
	else if (key == KEY_OBJ_MOVE_DOWN)
		obj->pos += vect3d(0, 0, -OBJECT_MOVE_STEP);
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}

short			handle_object_actions(int key, t_options *optns, t_scene *scene)
{
	t_object	*obj;

	obj = &scene->objects.data[optns->object_index];
	if (handle_object_movement(key, obj))
		;
	else if (handle_object_rotation(key, obj))
		;
	else if (handle_object_material_parameters(key, obj))
		;
	else
		return (!NEED_REDRAW);
	return (NEED_REDRAW);
}
