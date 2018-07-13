/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:15:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/11 20:24:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_LIGHT_H
# define APPLY_LIGHT_H

# include "scene.h"
# include "vect3d.h"
# include "intersection.h"

t_vect3d	apply_light(t_scene *scene, t_intersection *intersection);

#endif
