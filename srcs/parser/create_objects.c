/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:20:07 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/17 21:11:30 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"
#include "basis.h"
#include "scene.h"
#include "parser_private.h"
#include "array_object.h"
#include "object.h"
#include <stdlib.h>
#include <math.h>

static void	init_material(struct s_p_material *p_material,
		t_material *material)
{
	material->ambient = p_material->ambient;
	material->diffuse = p_material->diffuse;
	material->specular = p_material->specular;
	material->reflection = p_material->reflection;
	material->transparency = p_material->transparency;
	material->ior = p_material->refraction;
}

static void	init_figure(struct s_p_object *p_obj, t_object *obj)
{
	if (p_obj->plane)
		obj->shape = SHAPE(plane);
	if (p_obj->sphere)
		obj->shape = SHAPE(sphere, p_obj->sphere->radius);
	if (p_obj->cylinder)
		obj->shape = SHAPE(cylinder, p_obj->cylinder->radius,
			p_obj->cylinder->height);
	if (p_obj->cone)
		obj->shape = SHAPE(cone, tan(p_obj->cone->angle / 2),
			p_obj->cone->height);
	if (p_obj->cuboid)
		obj->shape = SHAPE(cuboid, (double[3]){p_obj->cuboid->width,
			p_obj->cuboid->height, p_obj->cuboid->depth});
	if (p_obj->rectangle)
		obj->shape = SHAPE(rect,
		(double[2]){p_obj->rectangle->width, p_obj->rectangle->height});
	if (p_obj->disk)
		obj->shape = SHAPE(disk, p_obj->disk->radius);
	if (p_obj->torus)
		obj->shape = SHAPE(torus, p_obj->torus->inner_radius,
			p_obj->torus->outer_radius);
	if (p_obj->paraboloid)
		obj->shape = SHAPE(paraboloid, p_obj->paraboloid->coefficient,
			p_obj->paraboloid->height);
}

static int	init_array_objects(struct s_p_scene *p_scene,
		t_array_object *objects)
{
	unsigned int	i;

	i = 0;
	while (i < objects->size)
	{
		objects->data[i].color[X] = 1;//
		objects->data[i].pos[X] = p_scene->objects[i].position[X];
		objects->data[i].pos[Y] = p_scene->objects[i].position[Y];
		objects->data[i].pos[Z] = p_scene->objects[i].position[Z];
		objects->data[i].basis =
			angles_to_basis(p_scene->objects[i].rotation);
		init_material(&p_scene->objects[i].material,
				&objects->data[i].material);
		init_figure(&p_scene->objects[i], &objects->data[i]);
		//texture
		i++;
	}
	return (0);
}

int			create_objects(struct s_p_scene *p_scene, t_scene *scene)
{
	scene->objects.size = p_scene->objects_count;
	if (!(scene->objects.data =
				malloc(sizeof(t_object) * p_scene->objects_count)))
		return (1);
	init_array_objects(p_scene, &scene->objects);
	return (0);
}
