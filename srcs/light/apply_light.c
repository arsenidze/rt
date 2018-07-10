/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:21:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 22:41:00 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "scene.h"
#include "intersection.h"
#include "raytracing.h"
#include "mmath.h"
#include <math.h>

#define SPECULAR_POW	200

static t_vect3d	get_diffuse(t_light *light,
				t_intersection *intersection, t_vect3d ray_to_light,
				double sq_dist)
{
	double	cos_between_light_and_normal;

	(void)sq_dist;
	cos_between_light_and_normal = vect3d_cos_normed(ray_to_light,
			intersection->normal);
	if (cos_between_light_and_normal > 0)
	{
		return (vect3d_mult_on_scalar(intersection->hit_object->k[K_DIFFUSE]
				* light->components[L_DIFFUSE],
					cos_between_light_and_normal));
	}
	return (vect3d(0, 0, 0));
}

static t_vect3d	get_specular(t_light *light,
				t_intersection *intersection, t_vect3d ray_to_light,
				double sq_dist)
{
	t_vect3d	bisector;
	double		cos_between_bisector_and_normal;

	bisector = ray_to_light + (-intersection->ray_dir);
	bisector = vect3d_norm(bisector);
	(void)sq_dist;
	cos_between_bisector_and_normal = vect3d_cos_normed(bisector,
			intersection->normal);
	if (cos_between_bisector_and_normal > 0)
	{
		return (vect3d_mult_on_scalar(intersection->hit_object->k[K_SPECULAR]
				* light->components[L_SPECULAR],
					pow(cos_between_bisector_and_normal, SPECULAR_POW)));
	}
	return (vect3d(0, 0, 0));
}

t_color			apply_light(t_scene *scene, t_intersection *inter)
{
	t_vect3d		total;
	int				i;
	t_vect3d		ray_to_light;
	double			sq_dist;
	t_intersection	tmp;

	total = vect3d(0, 0, 0);
	i = -1;
	while (scene->lights[++i])
	{
		total += scene->lights[i]->components[L_AMBIENT]
						* inter->hit_object->k[K_AMBIENT];
		ray_to_light = scene->lights[i]->pos - inter->dest;
		sq_dist = vect3d_sq_len(ray_to_light);
		ray_to_light = vect3d_div_on_scalar(ray_to_light, sqrt(sq_dist));
		if (find_closest_intersection(scene, inter->dest, ray_to_light, &tmp))
			if (vect3d_sq_len((scene->lights[i]->pos - tmp.orig))
			> vect3d_sq_len((tmp.dest - tmp.orig)))
				continue ;
		inter->normal = GET_NORMAL(inter->hit_object, inter->dest);
		total += get_diffuse(scene->lights[i], inter, ray_to_light, sq_dist);
		total += get_specular(scene->lights[i], inter, ray_to_light, sq_dist);
	}
	total = vect3d_clamp(total, 0., 1.);
	return (COLOR_RGBA(255 * total[0], 255 * total[1], 255 * total[2], 0));
}
