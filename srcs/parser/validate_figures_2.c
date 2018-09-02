/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_figures_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 20:08:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/02 16:55:36 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "parser_values_limits.h"

int			validate_disk(struct s_p_disk *disk)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(disk->radius,
		PARS_DISK_RADIUS_MIN, PARS_DISK_RADIUS_MAX)))
		parser_put_error_mapping("radius");
	return (error_code);
}

int			validate_torus(struct s_p_torus *torus)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(torus->inner_radius,
		PARS_TORUS_INNER_RADIUS_MIN, PARS_TORUS_INNER_RADIUS_MAX)))
		parser_put_error_mapping("inner radius");
	else if ((error_code = validate_value_float(torus->outer_radius,
		PARS_TORUS_OUTER_RADIUS_MIN, PARS_TORUS_OUTER_RADIUS_MAX)))
		parser_put_error_mapping("outer radius");
	else if (torus->inner_radius > torus->outer_radius)
		error_code = INNER_RADIUS_BIGGER_THEN_OUTER;
	return (error_code);
}

int			validate_cuboid(struct s_p_cuboid *cuboid)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(cuboid->width,
		PARS_CUBOID_WIDTH_MIN, PARS_CUBOID_WIDTH_MAX)))
		parser_put_error_mapping("width");
	else if ((error_code = validate_value_float(cuboid->height,
		PARS_CUBOID_HEIGHT_MIN, PARS_CUBOID_HEIGHT_MAX)))
		parser_put_error_mapping("height");
	else if ((error_code = validate_value_float(cuboid->depth,
		PARS_CUBOID_DEPTH_MIN, PARS_CUBOID_DEPTH_MAX)))
		parser_put_error_mapping("depth");
	return (error_code);
}

int			validate_paraboloid(struct s_p_paraboloid *paraboloid)
{
	unsigned int	error_code;

	error_code = 0;
	if ((error_code = validate_value_float(paraboloid->coefficient,
		PARS_PARABOLOID_COEFF_MIN, PARS_PARABOLOID_COEFF_MAX)))
		parser_put_error_mapping("coefficient");
	else if ((error_code = validate_value_float(paraboloid->height,
		PARS_PARABOLOID_HEIGHT_MIN, PARS_PARABOLOID_HEIGHT_MAX)))
		parser_put_error_mapping("height");
	return (error_code);
}
