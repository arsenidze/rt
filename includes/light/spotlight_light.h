/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight_light.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:56:04 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 21:34:40 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOTLIGHT_LIGHT_H
# define SPOTLIGHT_LIGHT_H

# include "vect3d.h"

typedef struct s_scene	t_scene;
typedef struct s_intersection	t_intersection;

typedef struct	s_spotlight_light
{
	t_vect3d	pos;
	t_vect3d	dir;
	float		cut_off;
	t_vect3d	ambient;
	t_vect3d	diffuse;
	t_vect3d	specular;
}				t_spotlight_light;

t_vect3d		spotlight_light_apply(const t_spotlight_light *light,
				const t_scene *scene, const t_intersection *isect);

#endif
