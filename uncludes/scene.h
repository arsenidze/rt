/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:51:12 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/05 21:17:36 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "object.h"
# include "light.h"

typedef struct	s_scene
{
	t_camera	camera;
	t_object	*objects;
	t_light		*lights;
	t_uint		nobjects;
	t_uint		nlights;
}				t_scene;

//t_scene			scene_new(t_camera *camera, t_object **objects,
//				t_light **lights);
//void			scene_delete(t_scene *scene);

#endif
