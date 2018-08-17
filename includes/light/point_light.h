/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:38:14 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 19:16:28 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_LIGHT_H
# define POINT_LIGHT_H

# include "vect3d.h"

typedef struct s_light			t_light;
typedef struct s_intersection	t_intersection;

typedef struct	s_point_light
{
	t_vect3d	pos;
	float		constant;
	float		linear;
	float		quadratic;
	float		ambient;
	float		diffuse;
	float		specular;
}				t_point_light;

double			point_light_get_impact(const t_light *light,
				const t_intersection *isect);

#endif
