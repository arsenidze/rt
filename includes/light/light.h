/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:49:59 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 19:11:52 by amelihov         ###   ########.fr       */
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

typedef struct	s_light
{
	t_vect3d		pos;	//TMP
	t_light_type	type;
	t_light_data	data;
}				t_light;

double			light_get_impact(const t_light *light,
				const t_intersection *isect);


#endif
