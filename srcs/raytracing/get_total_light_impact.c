/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total_light_impact.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:21:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 19:14:07 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "scene.h"
#include "intersection.h"
#include "raytracing.h"
#include "mmath.h"
#include <math.h>

#define SPECULAR_POW	200

static double get_shade(t_light light,
				t_intersection *intersection, t_ray ray_to_light,
				double sq_dist)
{
	double	cos_between_light_and_normal;

	(void)sq_dist;
	(void)light;
	cos_between_light_and_normal = vect3d_cos_normed(ray_to_light.d,
			intersection->normal);
	if (cos_between_light_and_normal > 0.0)
	{
		return (cos_between_light_and_normal);
	}
	return (0.0);
}

static double get_glare(t_light light,
				t_intersection *intersection, t_ray ray_to_light,
				double sq_dist)
{
	t_vect3d	bisector;
	double		cos_between_bisector_and_normal;

	bisector = ray_to_light.d + (-intersection->ray.d);
	bisector = vect3d_norm(bisector);
	(void)sq_dist;
	(void)light;
	cos_between_bisector_and_normal = vect3d_cos_normed(bisector,
			intersection->normal);
	if (cos_between_bisector_and_normal > 0.0)
	{
		return (pow(cos_between_bisector_and_normal, SPECULAR_POW));
	}
	return (0.0);
}

#define AMBIENT		0.2
#define DIFFUSE		0.6
#define SPECULAR	0.2

double		get_total_light_impact(const t_scene *scene, t_intersection *isect)
{
	double			impact;
	int				i;
	t_ray			ray_to_light;
	double			sq_dist;
	t_intersection	tmp;
	double			shade;
	double			glare;

	impact = AMBIENT;
	i = -1;
	while (++i < (int)scene->lights.size)
	{
		ray_to_light.o = isect->dest;
		ray_to_light.d = scene->lights.data[i].pos - isect->dest;
		sq_dist = vect3d_sq_len(ray_to_light.d);
		ray_to_light.d = vect3d_div_on_scalar(ray_to_light.d, sqrt(sq_dist));
		if (find_closest_intersection(scene, ray_to_light, &tmp))
			if (vect3d_sq_len((scene->lights.data[i].pos - tmp.ray.o))
				> vect3d_sq_len((tmp.dest - tmp.ray.o)))
			{
				double t;
				t = get_shade(scene->lights.data[i], isect, ray_to_light,
					sq_dist) * DIFFUSE;
				impact += t * tmp.hit_object->material.transparency;
				continue ;
			}
		shade = get_shade(scene->lights.data[i], isect, ray_to_light,
			sq_dist);
		impact += shade * DIFFUSE;
		glare = get_glare(scene->lights.data[i], isect, ray_to_light,
			sq_dist); 
		impact += glare * SPECULAR;
	}
	impact = clampd(impact, 0, 1);
	return (impact);
}

//double		get_total_light_impact(const t_scene *scene,
//				t_intersection *isect)
//{
//	double	impact;
//	int		i;
//
//	impact = 0;
//	i = -1;
//	while (++i < (int)scene->lights.size)
//	{
//		impact += light_get_light_source_impact(scene->lights.data[i], isect);
//	}
//	impact = clampd(impact, 0, 1);
//	return (impact);
//}
