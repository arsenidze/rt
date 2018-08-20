/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional_light.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:52:43 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 21:30:58 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTIONAL_LIGHT_H
# define DIRECTIONAL_LIGHT_H

# include "vect3d.h"

typedef struct s_scene	t_scene;
typedef struct s_intersection	t_intersection;

typedef struct	s_directional_light
{
	t_vect3d	direction;
	t_vect3d	ambient;
	t_vect3d	diffuse;
	t_vect3d	specular;
}				t_directional_light;

t_vect3d		directional_light_apply(const t_directional_light *light,
				const t_scene *scene, const t_intersection *isect);

#endif
