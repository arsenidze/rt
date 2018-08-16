/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refraction_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:37:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/14 18:57:57 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing_private.h"
#include "vect3d.h"
#include <math.h>

t_vect3d	get_refraction_ray(t_vect3d ray_dir, t_vect3d normal, int inside,
			float obj_ior)
{
	float		ior;
	float		eta;
	float		cosi;
	float		k;

	ior = obj_ior;
	if (inside)
		eta = ior;
	else
		eta = 1.0f / ior;
	cosi = -vect3d_dot(normal, ray_dir);
	k = 1 - eta * eta * (1 - cosi * cosi);
	return (vect3d_mult_on_scalar(ray_dir, eta)
			+ vect3d_mult_on_scalar(normal, eta * cosi - sqrt(k)));
}
