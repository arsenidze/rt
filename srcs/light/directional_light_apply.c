/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional_light_apply.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:40:29 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 20:45:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "directional_light.h"
#include "scene.h"
#include "intersection.h"

t_vect3d				directional_light_apply(const t_directional_light *light,
						const t_scene *scene, const t_intersection *isect)
{
	(void)light;
	(void)scene;
	(void)isect;
	return (vect3d(0, 0, 0));
}
