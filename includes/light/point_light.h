/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:38:14 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 21:00:30 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_LIGHT_H
# define POINT_LIGHT_H

# include "vect3d.h"

typedef struct s_scene			t_scene;
typedef struct s_intersection	t_intersection;

typedef struct	s_point_light
{
	t_vect3d	pos;
	t_vect3d	ambient;
	t_vect3d	diffuse;
	t_vect3d	specular;
	float		constant;
	float		linear;
	float		quadratic;
}				t_point_light;

t_vect3d		point_light_apply(const t_point_light *light,
				const t_scene *scene, const t_intersection *isect);

#endif
