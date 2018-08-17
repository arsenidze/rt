/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:34:11 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/17 17:34:02 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"
#include "basis.h"
#include "scene.h"
#include "parser_private.h"
#include "array_light.h"
#include "light.h"
#include <stdlib.h>

int		init_lights(struct s_p_scene *p_scene, t_array_light *lights)
{
	unsigned int	i;

	i = 0;
	while (i < lights->size)
	{
		lights->data[i].color[X] = 255.0 / (float)p_scene->lights[i].color[X];
		lights->data[i].color[Y] = 255.0 / (float)p_scene->lights[i].color[Y];
		lights->data[i].color[Z] = 255.0 / (float)p_scene->lights[i].color[Z];

		lights->data[i].pos[X] = p_scene->lights[i].position[X];
		lights->data[i].pos[Y] = p_scene->lights[i].position[Y];
		lights->data[i].pos[Z] = p_scene->lights[i].position[Z];

		lights->data[i].components[L_AMBIENT] = vect3d(0.9, 0.9, 0.9);//
		lights->data[i].components[L_DIFFUSE] = vect3d(0.9, 0.9, 0.9);//
		lights->data[i].components[L_SPECULAR] = vect3d(0.9, 0.9, 0.9);//

		i++;
	}
	return (0);
}

int		create_lights(struct s_p_scene *p_scene, t_scene *scene)
{	
	scene->lights.size = p_scene->lights_count;
	if (!(scene->lights.data =
				malloc(sizeof(t_light) * p_scene->lights_count)))
		return (1);
	init_lights(p_scene, &scene->lights);
	return (0);
}
