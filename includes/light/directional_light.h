/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional_light.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:52:43 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 19:15:11 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTIONAL_LIGHT_H
# define DIRECTIONAL_LIGHT_H

# include "vect3d.h"

typedef struct s_light	t_light;
typedef struct s_intersection	intersection;

typedef struct	s_directional_light
{
	t_vect3d	direction;
	float		ambient;
	float		diffuse;
	float		specular;
}				t_directional_light;

double			directional_light_get_impact(const t_light *light,
				const t_intersection *isect);

#endif
