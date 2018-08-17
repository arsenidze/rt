/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:23:36 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 22:09:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "scene.h"
# include "canvas.h"
# include "options.h"
# include "ray.h"
# include "intersection.h"

#define BACKGROUND_COLOR vect3d(0, 0, 0)
#define MAX_RAY_DEPTH	4
#define NSAMPLES 		4

t_vect3d	raytracing_trace_with_antialiasing(const t_scene *scene,
			int i, int j, const t_canvas *canvas);
t_vect3d	raytracing_trace(const t_scene *scene,
			int i, int j, const t_canvas *canvas);
int			raytracing_get_obj_idx_on_coord(const t_scene *scene, int i, int j,
			const t_canvas *canvas);


#endif
