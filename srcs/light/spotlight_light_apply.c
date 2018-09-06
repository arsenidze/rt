/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight_light_apply.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:40:29 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/06 19:37:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spotlight_light.h"
#include "light_private.h"
#include "raytracing.h"
#include "intersection.h"
#include "vect3d.h"
#include "mmath.h"

static inline double	calc_intensity(const t_spotlight_light *light,
						double cos_theta)
{
	double	epsilon;
	double	intensity;

	epsilon = light->cos_of_cut_off * 0.5;
	intensity = clampd((cos_theta - light->cos_of_cut_off) / epsilon, 0, 1);
	return (intensity);
}

static inline t_vect3d	shadow_with_transparency(t_vect3d intensity,
						const t_object *shadow_reason, t_vect3d col_in_point)
{
	return (intensity
		* vect3d_from_scalar(shadow_reason->material.transparency)
		* col_in_point);
}

t_vect3d				spotlight_light_apply(const t_spotlight_light *light,
						const t_scene *scene, const t_intersection *isect)
{
	t_vect3d		dir_to_light;
	const t_object	*shadow_reason;
	double			cos_theta;
	t_vect3d		inten;

	dir_to_light = light->pos - isect->dest;
	dir_to_light = vect3d_norm(dir_to_light);
	cos_theta = vect3d_dot(-dir_to_light, light->dir);
	inten = vect3d_from_scalar(calc_intensity(light, cos_theta));
	if (cos_theta < light->cos_of_cut_off)
		return (inten * light->ambient * isect->hit_object->material.ambient);
	if ((shadow_reason = raytracing_get_obj_on_dir(isect->dest, light->pos,
		dir_to_light, scene)))
	{
		if (shadow_reason->material.transparency > 0)
			return (shadow_with_transparency(inten, shadow_reason,
				calc_col(LIGHT_GET_COMPONENTS((*light)), dir_to_light, isect)));
			return (inten * light->ambient
				* isect->hit_object->material.ambient);
	}
	return (inten * calc_col(LIGHT_GET_COMPONENTS((*light)), dir_to_light,
		isect));
}
