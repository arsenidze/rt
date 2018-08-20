/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:23:36 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 20:58:50 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

typedef struct s_scene	t_scene;
typedef struct s_canvas	t_canvas;
typedef struct s_object	t_object;

typedef double	t_vect3d __attribute__((vector_size(sizeof(double)*3)));

#define BACKGROUND_COLOR vect3d(0, 0, 0)
#define MAX_RAY_DEPTH	4
#define NSAMPLES 		4

t_vect3d	raytracing_trace_with_antialiasing(const t_scene *scene,
			int i, int j, const t_canvas *canvas);
t_vect3d	raytracing_trace(const t_scene *scene,
			int i, int j, const t_canvas *canvas);
int			raytracing_get_obj_idx_on_coord(const t_scene *scene, int i, int j,
			const t_canvas *canvas);
t_object	*raytracing_get_obj_on_dir(t_vect3d point1, t_vect3d point2,
			t_vect3d dir, const t_scene *scene);

#endif
