/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 23:15:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/08 17:14:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_LIGHT_H
# define APPLY_LIGHT_H

# include "scene.h"
# include "intersection.h"

double apply_light(const t_scene *scene, t_intersection *intersection);

#endif
