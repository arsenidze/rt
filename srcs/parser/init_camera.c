/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:24:53 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/30 18:53:27 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"
#include "basis.h"
#include "scene.h"
#include "camera.h"
#include "parser_private.h"

int		init_camera(struct s_p_scene *p_scene, t_scene *scene)
{
	scene->camera.pos = vect3d(p_scene->camera->position[0],
		p_scene->camera->position[1], p_scene->camera->position[2]);
	scene->camera.basis = angles_to_basis(p_scene->camera->rotation);
	return (0);//void?
}
