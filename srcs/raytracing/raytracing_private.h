/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:32:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 19:12:38 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_PRIVATE_H
# define RAYTRACING_PRIVATE_H

# define TAN30	0.57735026919
# define REFRACT_OFFSET	1e-2

typedef struct s_scene			t_scene;
typedef struct s_camera			t_camera;
typedef struct s_canvas			t_canvas;
typedef struct s_intersection	t_intersection;
typedef struct s_ray			t_ray;
typedef double	t_vect3d __attribute__((vector_size(sizeof(double)*3)));

t_vect3d	trace_ray(const t_scene *scene, t_ray ray, int depth);
t_vect3d	get_ray_dir(t_camera camera, double i, double j,
			const t_canvas *canvas);
short		find_closest_intersection(const t_scene *scene, t_ray ray,
			t_intersection *intersection);
t_vect3d	handle_reflection_and_refraction(const t_scene *scene,
			const t_intersection *isect, int depth);
t_vect3d	get_refraction_ray(t_vect3d ray_dir, t_vect3d normal, int inside,
			float obj_ior);
double		fresnel(t_vect3d i, t_vect3d normal, float ior, int inside);
double		get_total_light_impact(const t_scene *scene, t_intersection *isect);

#endif
