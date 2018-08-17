/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parsed_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:49:06 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/17 20:47:59 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

static int	validate_color_values(unsigned int *color)
{
	unsigned int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] > 255)
		{
			parser_put_error_sequence(i);
			return (COLOR_VALUE_BIG);
		}	
		i++;
	}
	return (0);
}

static int	validate_light_values(struct s_p_light *light)
{
	unsigned int	error_code;
	
	error_code = 0;
	if ((error_code = validate_color_values(light->color)))
	{
		parser_put_error_mapping("color");
		return (error_code);
	}
	return (0);
}

static int	validate_lights_values(struct s_p_light *lights,
		unsigned int lights_count)
{
	unsigned int	error_code;
	unsigned int	i;

	error_code = 0;
	i = 0;
	while (i < lights_count)
	{
		if ((error_code = validate_light_values(&lights[i])))
		{
			parser_put_error_sequence(i);
			return (error_code);
		}
		i++;
	}
	return (0);
}

int		validate_parsed_values(struct s_p_scene *p_scene)
{
	unsigned int	error_code;
	//if (validate_camera_values(p_scene->camera))
	//	return (1);
	//
	error_code = 0;
	if ((error_code = validate_lights_values(p_scene->lights, p_scene->lights_count)))
	{
		parser_put_error_mapping("lights");
		parser_put_error_code(error_code);
		return (1);
	}
	//if (validate_objects_values(p_scene->objects, p_scene->objects_count))
	//{
	//	ft_putendl_fd("ERROR:\tin mapping field: objects", 2);
	//	return (1);
	//}
	return (0);
}
