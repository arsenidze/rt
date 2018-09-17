/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:55:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/17 17:22:52 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "array_object.h"
#include "array_light.h"

void			scene_deinit(t_scene *scene)
{
	array_object_deinit(scene->objects);
	array_light_deinit(scene->lights);
}
