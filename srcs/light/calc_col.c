/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:09:53 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 13:17:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_private.h"
#include "vect3d.h"
#include "intersection.h"
#include <math.h>

static inline double	calc_specular_impact(t_vect3d dir_to_light,
						const t_intersection *isect)
{
	t_vect3d	bisector;
	double		spec;

	bisector = dir_to_light + -isect->ray.d;
	bisector = vect3d_norm(bisector);
	spec = vect3d_dot(bisector, isect->normal);
	if (spec > 0)
		return (pow(spec, isect->hit_object->material.shininess));
	return (0);
}

t_vect3d				calc_col(t_vect3d l_components[3],
						t_vect3d dir_to_light, const t_intersection *isect)
{
	double		diff;
	double		spec;
	t_vect3d	output;

	output = l_components[0] * isect->hit_object->material.ambient;
	diff = vect3d_dot(dir_to_light, isect->normal);
	if (diff > 0)
		output += l_components[1]
			* vect3d_mult_on_scalar(isect->hit_object->material.diffuse, diff);
	spec = calc_specular_impact(dir_to_light, isect);
	if (spec > 0)
		output += l_components[2]
			* vect3d_mult_on_scalar(isect->hit_object->material.specular, spec);
	return (output);
}
