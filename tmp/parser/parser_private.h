/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:57:00 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/17 19:59:31 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include "scene.h"
# include "light.h"
# include "camera.h"
# include "object.h"
# include "cone.h"
# include "cuboid.h"
# include "cylinder.h"
# include "disk.h"
# include "paraboloid.h"
# include "plane.h"
# include "primitive.h"
# include "rect.h"
# include "sphere.h"
# include "torus.h"
# include "basis.h"

enum e_parsing_errors
{
	COLOR_VALUE_BIG = 1,
};

void	parser_put_error_mapping(char *name);
void	parser_put_error_sequence(unsigned int entry_num);
void	parser_put_error_code(unsigned int entry_num);

struct	s_p_camera
{
	float			*position;
	unsigned int	position_count;
	float			*rotation;
	unsigned int	rotation_count;
};

struct	s_p_light
{
	float			*position;
	unsigned int	position_count;
	unsigned int	*color;
	unsigned int	color_count;
};

struct	s_p_sphere
{
	float	radius;
};

struct	s_p_plane
{
	float	texture_scale;
};

struct	s_p_cylinder
{
	float	radius;
	float	height;
};

struct	s_p_cone
{
	float	angle;
	float	height;
};

struct	s_p_cuboid
{
	float	width;
	float	height;
	float	depth;
};

struct	s_p_rectangle
{
	float	width;
	float	height;
};

struct	s_p_disk
{
	float	radius;
};

struct	s_p_torus
{
	float	inner_radius;
	float	outer_radius;
};

struct	s_p_paraboloid
{
	float	coefficient;
	float	height;
};

struct	s_p_material
{
	float	transparency;
	float	reflection;
	float	refraction;
	float	ambient;
	float	diffuse;
	float	specular;
	char	*texture_path;
};

struct	s_p_object
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

struct	s_p_scene
{
	float				ambient;//
	struct s_p_camera	*camera;
	struct s_p_light	*lights;
	unsigned int		lights_count;
	struct s_p_object	*objects;
	unsigned int		objects_count;
};

t_basis	angles_to_basis(float *angles);

int		validate_parsed_values(struct s_p_scene *p_scene);
int		init_camera(struct s_p_scene *p_scene, t_scene *scene);
int		create_objects(struct s_p_scene *p_scene, t_scene *scene);
int		create_lights(struct s_p_scene *p_scene, t_scene *scene);

#endif
