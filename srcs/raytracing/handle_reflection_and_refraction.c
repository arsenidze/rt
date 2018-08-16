/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_reflection_and_refraction.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 19:03:33 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/14 20:50:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "intersection.h"
#include "ray.h"
#include "vect3d.h"

t_vect3d	handle_reflection_and_refraction(const t_scene *scene,
			const t_intersection *isect, int depth)
{
	double		kr;	
	t_ray		reflect_ray;
	t_ray		refract_ray;
	t_vect3d	reflect_col;
	t_vect3d	refract_col;
	t_vect3d	point_col;

	kr = fresnel(isect->ray.d, isect->normal, isect->hit_object->material.ior,
		isect->inside);
	reflect_ray.o = isect->dest;
	reflect_ray.d = vect3d_reflect(isect->ray.d, isect->normal);
	reflect_col = trace_ray(scene, reflect_ray, depth + 1);
	if (isect->hit_object->material.transparency > 0.0 && kr < 1.0)
	{
		refract_ray.o = isect->dest
			- vect3d_mult_on_scalar(isect->normal, REFRACT_OFFSET);
		refract_ray.d = get_refraction_ray(isect->ray.d, isect->normal,
			isect->inside, isect->hit_object->material.ior);
		refract_col = trace_ray(scene, refract_ray, depth + 1);
	}
	else
		refract_col = vect3d(0, 0, 0);
	point_col = vect3d_mult_on_scalar(reflect_col,
			isect->hit_object->material.reflection * kr)
			+ vect3d_mult_on_scalar(refract_col,
			isect->hit_object->material.transparency * (1 - kr));
	return (point_col);
}
