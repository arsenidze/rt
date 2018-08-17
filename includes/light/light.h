/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:49:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 21:00:42 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "point_light.h"
# include "directional_light.h"
# include "spotlight.h"

typedef struct s_intersection	t_intersection;

typedef enum	e_light_type
{
	point,
	directional,
	spotlight
}				t_light_type;

typedef union	u_light_data
{
	t_point_light		point;
	t_directional_light	directional;
	t_spotlight			spotlight;
}				t_light_data;
# define L_AMBIENT		0
# define L_DIFFUSE		1
# define L_SPECULAR		2


typedef struct	s_light
{
	t_vect3d		pos;	//TMP
	t_vect3d		color;	//TMP
	t_vect3d	components[3];

	t_light_type	type;
	t_light_data	data;
}				t_light;

double			light_get_impact(const t_light *light,
				const t_intersection *isect);


#endif
