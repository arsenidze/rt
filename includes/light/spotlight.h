/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:56:04 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 19:16:04 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOTLIGHT_H
# define SPOTLIGHT_H

# include "vect3d.h"

typedef struct s_light	t_light;
typedef struct s_intersection	t_intersection;

typedef struct	s_spotlight
{
	t_vect3d	pos;
	t_vect3d	dir;
	float		cut_off;
	float		ambient;
	float		diffuse;
	float		specular;
}				t_spotlight;

double			spotlight_get_impact(const t_light *light,
				const t_intersection *isect);

#endif
