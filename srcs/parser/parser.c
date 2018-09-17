/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:59:18 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/17 17:02:25 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "cyaml.h"
#include "parser_private.h"
#include "parser.h"

static const cyaml_schema_value_t g_vector_entry =
{
	CYAML_VALUE_FLOAT(CYAML_FLAG_DEFAULT, float),
};

/*
** Camera
*/
static const cyaml_schema_field_t g_camera_fields_p_schema[] =
{
	CYAML_FIELD_SEQUENCE("position", CYAML_FLAG_POINTER,
			struct s_p_camera, position, &g_vector_entry,
			3, 3),
	CYAML_FIELD_SEQUENCE("rotation", CYAML_FLAG_POINTER,
			struct s_p_camera, rotation, &g_vector_entry,
			3, 3),
	CYAML_FIELD_END
};

/*
** Light
*/
static const cyaml_schema_field_t g_spotlight_fields_p_schema[] =
{
	CYAML_FIELD_SEQUENCE("position", CYAML_FLAG_POINTER,
		struct s_p_spotlight, position, &g_vector_entry,
		3, 3),
	CYAML_FIELD_SEQUENCE("direction", CYAML_FLAG_POINTER,
		struct s_p_spotlight, direction, &g_vector_entry,
		3, 3),
	CYAML_FIELD_FLOAT("cut off", CYAML_FLAG_DEFAULT,
		struct s_p_spotlight, cut_off),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_point_fields_p_schema[] =
{
	CYAML_FIELD_SEQUENCE("position", CYAML_FLAG_POINTER,
		struct s_p_point, position, &g_vector_entry,
		3, 3),
	CYAML_FIELD_FLOAT("constant", CYAML_FLAG_DEFAULT,
		struct s_p_point, constant),
	CYAML_FIELD_FLOAT("linear", CYAML_FLAG_DEFAULT,
		struct s_p_point, linear),
	CYAML_FIELD_FLOAT("quadratic", CYAML_FLAG_DEFAULT,
		struct s_p_point, quadratic),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_directional_fields_p_schema[] =
{
	CYAML_FIELD_SEQUENCE("direction", CYAML_FLAG_POINTER,
		struct s_p_directional, direction, &g_vector_entry,
		3, 3),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_light_fields_p_schema[] =
{
	CYAML_FIELD_SEQUENCE("ambient", CYAML_FLAG_POINTER,
		struct s_p_light, ambient, &g_vector_entry,
		3, 3),
	CYAML_FIELD_SEQUENCE("diffuse", CYAML_FLAG_POINTER,
		struct s_p_light, diffuse, &g_vector_entry,
		3, 3),
	CYAML_FIELD_SEQUENCE("specular", CYAML_FLAG_POINTER,
		struct s_p_light, specular, &g_vector_entry,
		3, 3),
	CYAML_FIELD_MAPPING_PTR(
		"spotlight", CYAML_FLAG_OPTIONAL,
		struct s_p_light, spotlight, g_spotlight_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
		"point light", CYAML_FLAG_OPTIONAL,
		struct s_p_light, point, g_point_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
		"directional light", CYAML_FLAG_OPTIONAL,
		struct s_p_light, directional, g_directional_fields_p_schema),
	CYAML_FIELD_END
};

static const cyaml_schema_value_t g_light_schema =
{
	CYAML_VALUE_MAPPING(CYAML_FLAG_DEFAULT,
			struct s_p_light, g_light_fields_p_schema),
};

/*
** Texture
*/
static const cyaml_schema_field_t g_texture_fields_p_schema[] = {
	CYAML_FIELD_STRING_PTR(
		"path", CYAML_FLAG_POINTER | CYAML_FLAG_OPTIONAL,
		struct s_p_texture, path, 0, CYAML_UNLIMITED),
	CYAML_FIELD_UINT("offset x", CYAML_FLAG_DEFAULT | CYAML_FLAG_OPTIONAL,
		struct s_p_texture, x_offset),
	CYAML_FIELD_UINT("offset y", CYAML_FLAG_DEFAULT | CYAML_FLAG_OPTIONAL,
		struct s_p_texture, y_offset),
	CYAML_FIELD_END
};

/*
** Material
*/
static const cyaml_schema_field_t g_material_fields_p_schema[] = {
	CYAML_FIELD_FLOAT("transparency", CYAML_FLAG_DEFAULT,
		struct s_p_material, transparency),
	CYAML_FIELD_FLOAT("reflection", CYAML_FLAG_DEFAULT,
		struct s_p_material, reflection),
	CYAML_FIELD_FLOAT("refraction", CYAML_FLAG_DEFAULT,
		struct s_p_material, refraction),
	CYAML_FIELD_FLOAT("shininess", CYAML_FLAG_DEFAULT,
		struct s_p_material, shininess),
	CYAML_FIELD_SEQUENCE("ambient", CYAML_FLAG_POINTER,
		struct s_p_material, ambient, &g_vector_entry,
		3, 3),
	CYAML_FIELD_SEQUENCE("diffuse", CYAML_FLAG_POINTER,
		struct s_p_material, diffuse, &g_vector_entry,
		3, 3),
	CYAML_FIELD_SEQUENCE("specular", CYAML_FLAG_POINTER,
		struct s_p_material, specular, &g_vector_entry,
		3, 3),
	CYAML_FIELD_MAPPING_PTR(
			"texture", CYAML_FLAG_OPTIONAL,
			struct s_p_material, texture, g_texture_fields_p_schema),
	CYAML_FIELD_END
};

/*
** Figures
*/
static const cyaml_schema_field_t g_plane_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("texture scale", CYAML_FLAG_DEFAULT,
		struct s_p_plane, texture_scale),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_sphere_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("radius", CYAML_FLAG_DEFAULT,
		struct s_p_sphere, radius),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_cylinder_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("radius", CYAML_FLAG_DEFAULT,
		struct s_p_cylinder, radius),
	CYAML_FIELD_FLOAT("height", CYAML_FLAG_DEFAULT,
		struct s_p_cylinder, height),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_cone_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("angle", CYAML_FLAG_DEFAULT,
		struct s_p_cone, angle),
	CYAML_FIELD_FLOAT("height", CYAML_FLAG_DEFAULT,
		struct s_p_cone, height),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_rectangle_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("width", CYAML_FLAG_DEFAULT,
		struct s_p_rectangle, width),
	CYAML_FIELD_FLOAT("height", CYAML_FLAG_DEFAULT,
		struct s_p_rectangle, height),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_cuboid_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("width", CYAML_FLAG_DEFAULT,
		struct s_p_cuboid, width),
	CYAML_FIELD_FLOAT("height", CYAML_FLAG_DEFAULT,
		struct s_p_cuboid, height),
	CYAML_FIELD_FLOAT("depth", CYAML_FLAG_DEFAULT,
		struct s_p_cuboid, depth),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_disk_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("radius", CYAML_FLAG_DEFAULT,
		struct s_p_disk, radius),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_paraboloid_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("coefficient", CYAML_FLAG_DEFAULT,
		struct s_p_paraboloid, coefficient),
	CYAML_FIELD_FLOAT("height", CYAML_FLAG_DEFAULT,
		struct s_p_paraboloid, height),
	CYAML_FIELD_END
};

static const cyaml_schema_field_t g_torus_p_fields_p_schema[] =
{
	CYAML_FIELD_FLOAT("inner radius", CYAML_FLAG_DEFAULT,
		struct s_p_torus, inner_radius),
	CYAML_FIELD_FLOAT("outer radius", CYAML_FLAG_DEFAULT,
		struct s_p_torus, outer_radius),
	CYAML_FIELD_END
};

/*
** Object
*/
static const cyaml_schema_field_t g_object_fields_p_schema[] = {
	CYAML_FIELD_SEQUENCE("position", CYAML_FLAG_POINTER,
			struct s_p_object, position, &g_vector_entry,
			3, 3),
	CYAML_FIELD_SEQUENCE("rotation", CYAML_FLAG_POINTER,
			struct s_p_object, rotation, &g_vector_entry,
			3, 3),
	CYAML_FIELD_MAPPING(
			"material", CYAML_FLAG_DEFAULT,
			struct s_p_object, material, g_material_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"plane", CYAML_FLAG_OPTIONAL,
			struct s_p_object, plane, g_plane_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"sphere", CYAML_FLAG_OPTIONAL,
			struct s_p_object, sphere, g_sphere_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"cone", CYAML_FLAG_OPTIONAL,
			struct s_p_object, cone, g_cone_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"cylinder", CYAML_FLAG_OPTIONAL,
			struct s_p_object, cylinder, g_cylinder_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"rectangle", CYAML_FLAG_OPTIONAL,
			struct s_p_object, rectangle, g_rectangle_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"disk", CYAML_FLAG_OPTIONAL,
			struct s_p_object, disk, g_disk_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"torus", CYAML_FLAG_OPTIONAL,
			struct s_p_object, torus, g_torus_p_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"cuboid", CYAML_FLAG_OPTIONAL,
			struct s_p_object, cuboid, g_cuboid_fields_p_schema),
	CYAML_FIELD_MAPPING_PTR(
			"paraboloid", CYAML_FLAG_OPTIONAL,
			struct s_p_object, paraboloid, g_paraboloid_fields_p_schema),
	CYAML_FIELD_END
};

static const cyaml_schema_value_t g_object_schema =
{
	CYAML_VALUE_MAPPING(CYAML_FLAG_DEFAULT,
			struct s_p_object, g_object_fields_p_schema),
};

/*
** Scene
*/
static const cyaml_schema_field_t g_scene_fields_p_schema[] = {
	CYAML_FIELD_MAPPING_PTR(
		"camera", CYAML_FLAG_DEFAULT,
		struct s_p_scene, camera, g_camera_fields_p_schema),
	CYAML_FIELD_SEQUENCE(
		"lights", CYAML_FLAG_POINTER,
		struct s_p_scene, lights,
		&g_light_schema, 0, PARS_MAX_LIGHTS_NUM),
	CYAML_FIELD_SEQUENCE(
		"objects", CYAML_FLAG_POINTER,
		struct s_p_scene, objects,
		&g_object_schema, 0, PARS_MAX_LIGHTS_NUM),
	CYAML_FIELD_END
};

static const cyaml_schema_value_t g_scene_schema = {
	CYAML_VALUE_MAPPING(CYAML_FLAG_POINTER,
			struct s_p_scene, g_scene_fields_p_schema),
};

static const cyaml_config_t g_config = {
	.log_level = CYAML_LOG_WARNING,
	.log_fn = cyaml_log,
	.mem_fn = cyaml_mem,
};

int		scene_init_from_file(char *file_path, t_scene *scene)
{
	cyaml_err_t			err;
	struct s_p_scene	*p_scene;

	ft_bzero(scene, sizeof(t_scene));
	err = cyaml_load_file(file_path, &g_config,
			&g_scene_schema, (cyaml_data_t **)&p_scene, NULL);
	if (!p_scene)
	{
		ft_putendl_fd("ERROR:\tInvalid input file", 2);
		return (PARSER_FAILURE);
	}
	if (err != CYAML_OK)
	{
		ft_putstr_fd(cyaml_strerror(err), 2);
		return (PARSER_FAILURE);
	}
	if ((validate_parsed_values(p_scene)) || (create_objects(p_scene, scene)))
	{
		cyaml_free(&g_config, &g_scene_schema, p_scene, 0);
		return (PARSER_FAILURE);
	}
	init_camera(p_scene, scene);
	create_lights(p_scene, scene);
	cyaml_free(&g_config, &g_scene_schema, p_scene, 0);
	return (PARSER_SUCCESS);
}
