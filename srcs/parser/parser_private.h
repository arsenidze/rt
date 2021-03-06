/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:57:00 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/17 17:57:02 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include "light.h"
# include "scene.h"
# include "primitive.h"
# include "rect.h"
# include "sphere.h"
# include "torus.h"
# include "basis.h"

# define PARS_MAX_OBJECTS_NUM 100
# define PARS_MAX_LIGHTS_NUM 100

# define TO_RAD(n) ((n) * (M_PI / 180.0))

struct		s_p_camera
{
	float			*position;
	unsigned int	position_count;
	float			*rotation;
	unsigned int	rotation_count;
};

struct		s_p_spotlight
{
	float			*position;
	unsigned int	position_count;
	float			*direction;
	unsigned int	direction_count;
	float			cut_off;
};

struct		s_p_point
{
	float			*position;
	unsigned int	position_count;
	float			constant;
	float			linear;
	float			quadratic;
};

struct		s_p_directional
{
	float			*direction;
	unsigned int	direction_count;
};

struct		s_p_light
{
	float					*ambient;
	unsigned int			ambient_count;
	float					*diffuse;
	unsigned int			diffuse_count;
	float					*specular;
	unsigned int			specular_count;
	struct s_p_spotlight	*spotlight;
	struct s_p_point		*point;
	struct s_p_directional	*directional;
};

struct		s_p_sphere
{
	float	radius;
};

struct		s_p_plane
{
	float	texture_scale;
};

struct		s_p_cylinder
{
	float	radius;
	float	height;
};

struct		s_p_cone
{
	float	angle;
	float	height;
};

struct		s_p_cuboid
{
	float	width;
	float	height;
	float	depth;
};

struct		s_p_rectangle
{
	float	width;
	float	height;
};

struct		s_p_disk
{
	float	radius;
};

struct		s_p_torus
{
	float	inner_radius;
	float	outer_radius;
};

struct		s_p_paraboloid
{
	float	coefficient;
	float	height;
};

struct		s_p_texture
{
	char			*path;
	unsigned int	x_offset;
	unsigned int	y_offset;
};

struct		s_p_material
{
	float				transparency;
	float				reflection;
	float				refraction;
	float				shininess;
	float				*ambient;
	unsigned int		ambient_count;
	float				*diffuse;
	unsigned int		diffuse_count;
	float				*specular;
	unsigned int		specular_count;
	struct s_p_texture	*texture;
};

struct		s_p_object
{
	struct s_p_plane		*plane;
	struct s_p_sphere		*sphere;
	struct s_p_cone			*cone;
	struct s_p_cylinder		*cylinder;
	struct s_p_rectangle	*rectangle;
	struct s_p_disk			*disk;
	struct s_p_torus		*torus;
	struct s_p_cuboid		*cuboid;
	struct s_p_paraboloid	*paraboloid;
	float					*position;
	unsigned int			position_count;
	float					*rotation;
	unsigned int			rotation_count;
	struct s_p_material		material;
};

struct		s_p_scene
{
	struct s_p_camera	*camera;
	struct s_p_light	*lights;
	unsigned int		lights_count;
	struct s_p_object	*objects;
	unsigned int		objects_count;
};

int			validate_vector_float(float *vec, float min_val, float max_val);
int			validate_value_float(float val, float min_val, float max_val);
int			validate_direction(float *direction);

int			validate_plane(struct s_p_plane *plane);
int			validate_sphere(struct s_p_sphere *sphere);
int			validate_cone(struct s_p_cone *cone);
int			validate_cylinder(struct s_p_cylinder *cylinder);
int			validate_rectangle(struct s_p_rectangle *rectangle);
int			validate_disk(struct s_p_disk *disk);
int			validate_torus(struct s_p_torus *torus);
int			validate_cuboid(struct s_p_cuboid *cuboid);
int			validate_paraboloid(struct s_p_paraboloid *paraboloid);
int			validate_obj_material(struct s_p_material *material);
int			validate_obj_ads(struct s_p_material *material);
int			validate_obj_type(struct s_p_object *object);
int			validate_obj_type_num(struct s_p_object *object);
int			validate_objects(struct s_p_object *objects,
				unsigned int objects_count);

int			validate_light_spot(struct s_p_spotlight *spotlight);
int			validate_light_directional(struct s_p_directional *directional);
int			validate_light_point(struct s_p_point *point);
int			validate_light_ads(struct s_p_light *light);
int			validate_light_type_num(struct s_p_light *light);
int			validate_lights(struct s_p_light *lights,
			unsigned int lights_count);

int			validate_camera(struct s_p_camera *camera);

int			validate_parsed_values(struct s_p_scene *p_scene);

t_basis		angles_to_basis(float *angles);
t_vect3d	vect3d_from_float(float *data);

void		init_camera(struct s_p_scene *p_scene, t_scene *scene);
int			create_objects(struct s_p_scene *p_scene, t_scene *scene);
int			create_lights(struct s_p_scene *p_scene, t_scene *scene);

/*
** Errors
*/
enum	e_parsing_errors
{
	TOO_MANY_TYPES = 1,
	TOO_FEW_TYPES,
	VALUE_BIG,
	VALUE_LOW,
	INNER_RADIUS_BIGGER_THEN_OUTER,
	DIRECTION_CANNOT_BE_NULL_VECTOR
};

void		parser_put_error_mapping(char *name);
void		parser_put_error_sequence(unsigned int entry_num);
void		parser_put_error_code(unsigned int entry_num);

#endif
