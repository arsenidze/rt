/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:34:11 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/03 18:19:21 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"
#include "basis.h"
#include "scene.h"
#include "parser_private.h"
#include "array_light.h"
#include "light.h"
#include <stdlib.h>
#include <math.h>

static void	init_spotlight(struct s_p_light *p_light,
		t_spotlight_light *spotlight)
{
	spotlight->pos = vect3d_from_float(p_light->spotlight->position);
	spotlight->dir = vect3d_from_float(p_light->spotlight->direction);
	spotlight->cos_of_cut_off = cos(TO_RAD(p_light->spotlight->cut_off / 2));
	spotlight->ambient = vect3d_from_float(p_light->ambient);
	spotlight->diffuse = vect3d_from_float(p_light->diffuse);
	spotlight->specular = vect3d_from_float(p_light->specular);
}

static void	init_point(struct s_p_light *p_light, t_point_light *point)
{
	point->pos = vect3d_from_float(p_light->point->position);
	point->constant = p_light->point->constant;
	point->linear = p_light->point->linear;
	point->quadratic = p_light->point->quadratic;
	point->ambient = vect3d_from_float(p_light->ambient);
	point->diffuse = vect3d_from_float(p_light->diffuse);
	point->specular = vect3d_from_float(p_light->specular);
}

static void	init_directional(struct s_p_light *p_light,
		t_directional_light *directional)
{
	directional->dir = vect3d_from_float(p_light->directional->direction);
	directional->ambient = vect3d_from_float(p_light->ambient);
	directional->diffuse = vect3d_from_float(p_light->diffuse);
	directional->specular = vect3d_from_float(p_light->specular);
}

static void	init_light_type(struct s_p_light *p_light, t_light *light)
{
	if (p_light->spotlight)
	{
		init_spotlight(p_light, &light->data.spotlight);
		light->type = spotlight;
	}
	else if (p_light->point)
	{
		init_point(p_light, &light->data.point);
		light->type = point;
	}
	else if (p_light->directional)
	{
		init_directional(p_light, &light->data.directional);
		light->type = directional;
	}
}

int			create_lights(struct s_p_scene *p_scene, t_scene *scene)
{
	unsigned int	i;

	scene->lights.size = p_scene->lights_count;
	if (!(scene->lights.data =
		malloc(sizeof(t_light) * p_scene->lights_count)))
		return (1);
	i = 0;
	while (i < scene->lights.size)
	{
		init_light_type(&p_scene->lights[i], &scene->lights.data[i]);
		i++;
	}
	return (0);
}
