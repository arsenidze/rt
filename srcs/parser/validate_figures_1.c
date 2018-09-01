/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_figures_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 20:08:17 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 20:08:25 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int			validate_plane(struct s_p_plane *plane)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(plane->texture_scale,
		PARS_PLANE_TEX_SCALE_MIN, PARS_PLANE_TEX_SCALE_MAX)))
			parser_put_error_mapping("texture scale");
	return (error_code);
}

int			validate_sphere(struct s_p_sphere *sphere)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(sphere->radius,
		PARS_SPHERE_RADIUS_MIN, PARS_SPHERE_RADIUS_MAX)))
			parser_put_error_mapping("radius");
	return (error_code);
}

int			validate_cone(struct s_p_cone *cone)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(cone->angle,
		PARS_CONE_ANGLE_MIN, PARS_CONE_ANGLE_MAX)))
			parser_put_error_mapping("angle");
	else if ((error_code = validate_value_float(cone->height,
		PARS_CONE_HEIGHT_MIN, PARS_CONE_HEIGHT_MAX)))
			parser_put_error_mapping("height");
	return (error_code);
}

int			validate_cylinder(struct s_p_cylinder *cylinder)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(cylinder->radius,
		PARS_CYLINDER_RADIUS_MIN, PARS_CYLINDER_RADIUS_MAX)))
			parser_put_error_mapping("radius");
	else if ((error_code = validate_value_float(cylinder->height,
		PARS_CONE_HEIGHT_MIN, PARS_CYLINDER_HEIGHT_MAX)))
			parser_put_error_mapping("height");
	return (error_code);
}

int			validate_rectangle(struct s_p_rectangle *rectangle)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(rectangle->width,
		PARS_RECTANGLE_WIDTH_MIN, PARS_RECTANGLE_WIDTH_MAX)))
			parser_put_error_mapping("width");
	else if ((error_code = validate_value_float(rectangle->height,
		PARS_RECTANGLE_HEIGHT_MIN, PARS_RECTANGLE_HEIGHT_MAX)))
			parser_put_error_mapping("height");
	return (error_code);
}
