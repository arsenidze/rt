/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_apply_light_by_type.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:32:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 19:30:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "scene.h"
#include "intersection.h"

t_vect3d		light_apply_light_by_type(const t_light *light,
				const t_scene *scene, const t_intersection *isect)
{
	if (light->type == point)
		return (point_light_apply(&light->data.point, scene, isect));
	else if (light->type == directional)
		return (directional_light_apply(&light->data.directional, scene,
			isect));
	else if (light->type == spotlight)
		return (spotlight_light_apply(&light->data.spotlight, scene, isect));
	return (vect3d(0, 0, 0));
}
