/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:20:07 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/23 17:19:19 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3d.h"
#include "basis.h"
#include "scene.h"
#include "parser_private.h"
#include "parser_values_limits.h"
#include "array_object.h"
#include "object.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

static void	init_material(struct s_p_material *p_material,
		t_material *material)
{
	material->ambient = vect3d_from_float(p_material->ambient);
	material->diffuse = vect3d_from_float(p_material->diffuse);
	material->specular = vect3d_from_float(p_material->specular);
	material->reflection = p_material->reflection;
	material->transparency = p_material->transparency;
	material->shininess = p_material->shininess;
	material->ior = p_material->refraction;
}

static void	init_figure(struct s_p_object *p_obj, t_object *obj)
{
	if (p_obj->plane)
		obj->shape = SHAPE(plane, p_obj->plane->texture_scale);
	if (p_obj->sphere)
		obj->shape = SHAPE(sphere, p_obj->sphere->radius);
	if (p_obj->cylinder)
		obj->shape = SHAPE(cylinder, p_obj->cylinder->radius,
			p_obj->cylinder->height);
	if (p_obj->cone)
		obj->shape = SHAPE(cone, tan(TO_RAD(p_obj->cone->angle / 2)),
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

static int	init_texture(struct s_p_texture *p_texture, t_texture *texture)
{
	if (p_texture)
	{
		if (texture_load(texture, p_texture->path) == TEXTURE_FAILURE)
		{
			ft_putendl_fd("ERROR:\tFailed to load texture", 2);
			return (1);
		}
		if (p_texture->x_offset > texture->w
				|| p_texture->y_offset > texture->h)
		{
			ft_putendl_fd("ERROR:\tInvalid texture offset values", 2);
			return (1);
		}
		texture->offset[0] = p_texture->x_offset;
		texture->offset[1] = p_texture->y_offset;
		texture->scale = PARS_TEX_SCALE_DEFAULT;
	}
	return (0);
}

static int	init_array_objects(struct s_p_scene *p_scene,
		t_array_object *objects)
{
	unsigned int	i;

	i = 0;
	while (i < objects->size)
	{
		init_figure(&p_scene->objects[i], &objects->data[i]);
		objects->data[i].pos[X] = p_scene->objects[i].position[X];
		objects->data[i].pos[Y] = p_scene->objects[i].position[Y];
		objects->data[i].pos[Z] = p_scene->objects[i].position[Z];
		objects->data[i].texture.pixels = NULL;
		if (init_texture(p_scene->objects[i].material.texture,
					&objects->data[i].texture))
			return (1);
		objects->data[i].basis =
			angles_to_basis(p_scene->objects[i].rotation);
		init_material(&p_scene->objects[i].material,
				&objects->data[i].material);
		i++;
	}
	return (0);
}

int			create_objects(struct s_p_scene *p_scene, t_scene *scene)
{
	scene->objects.size = p_scene->objects_count;
	if (!(scene->objects.data =
				ft_memalloc(sizeof(t_object) * p_scene->objects_count)))
		return (1);
	if (init_array_objects(p_scene, &scene->objects))
		return (1);
	return (0);
}
