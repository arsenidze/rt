/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:51:12 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/06 17:24:27 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "array_object.h"
# include "array_light.h"

typedef struct	s_scene
{
	t_camera		camera;
	t_array_object	objects;
	t_array_light	lights;
}				t_scene;

//t_scene			scene_new(t_camera *camera, t_object **objects,
//				t_light **lights);
void			scene_deinit(t_scene *scene);

#endif
