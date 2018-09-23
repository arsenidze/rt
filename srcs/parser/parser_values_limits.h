/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_values_limits.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:46:37 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/23 17:20:44 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_VALUES_LIMITS_H
# define PARSER_VALUES_LIMITS_H

# define FLT_MAX 30000

/*
** Object(Material)
*/
# define PARS_TRANSPARENCY_MIN 0
# define PARS_TRANSPARENCY_MAX 1
# define PARS_REFLECTION_MIN 0
# define PARS_REFLECTION_MAX 1
# define PARS_REFRACTION_MIN 1
# define PARS_REFRACTION_MAX 5
# define PARS_SHININESS_MIN 0
# define PARS_SHININESS_MAX FLT_MAX

/*
** Spotlight light
*/
# define PARS_CUTOFF_MIN 0
# define PARS_CUTOFF_MAX 180

/*
** Point light
*/
# define PARS_CONSTANT_MIN 0
# define PARS_CONSTANT_MAX 180
# define PARS_LINEAR_MIN 0
# define PARS_LINEAR_MAX 180
# define PARS_QUADRATIC_MIN 0
# define PARS_QUADRATIC_MAX 180

/*
** Figures
*/
# define PARS_PLANE_TEX_SCALE_MIN 0
# define PARS_PLANE_TEX_SCALE_MAX FLT_MAX

# define PARS_SPHERE_RADIUS_MIN 0
# define PARS_SPHERE_RADIUS_MAX FLT_MAX

# define PARS_CYLINDER_HEIGHT_MIN 0
# define PARS_CYLINDER_HEIGHT_MAX FLT_MAX
# define PARS_CYLINDER_RADIUS_MIN 0
# define PARS_CYLINDER_RADIUS_MAX FLT_MAX

# define PARS_CONE_HEIGHT_MIN 0
# define PARS_CONE_HEIGHT_MAX FLT_MAX
# define PARS_CONE_ANGLE_MIN 0.1
# define PARS_CONE_ANGLE_MAX FLT_MAX

# define PARS_CUBOID_HEIGHT_MIN 0
# define PARS_CUBOID_HEIGHT_MAX FLT_MAX
# define PARS_CUBOID_WIDTH_MIN 0
# define PARS_CUBOID_WIDTH_MAX FLT_MAX
# define PARS_CUBOID_DEPTH_MIN 0
# define PARS_CUBOID_DEPTH_MAX FLT_MAX

# define PARS_DISK_RADIUS_MIN 0
# define PARS_DISK_RADIUS_MAX FLT_MAX

# define PARS_PARABOLOID_COEFF_MIN 0
# define PARS_PARABOLOID_COEFF_MAX FLT_MAX
# define PARS_PARABOLOID_HEIGHT_MIN 0
# define PARS_PARABOLOID_HEIGHT_MAX FLT_MAX

# define PARS_RECTANGLE_HEIGHT_MIN 0
# define PARS_RECTANGLE_HEIGHT_MAX FLT_MAX
# define PARS_RECTANGLE_WIDTH_MIN 0
# define PARS_RECTANGLE_WIDTH_MAX FLT_MAX

# define PARS_TORUS_INNER_RADIUS_MIN 0
# define PARS_TORUS_INNER_RADIUS_MAX FLT_MAX
# define PARS_TORUS_OUTER_RADIUS_MIN 0
# define PARS_TORUS_OUTER_RADIUS_MAX FLT_MAX

/*
** Position
*/
# define PARS_POSITION_MIN -FLT_MAX
# define PARS_POSITION_MAX FLT_MAX

/*
** Default texture scale value
*/
# define PARS_TEX_SCALE_DEFAULT 1

#endif
