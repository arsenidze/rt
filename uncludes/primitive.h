/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:30:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/05 20:48:03 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

//# define EXPAND_FUNC(n) n##_intersection, n##_get_normal, n##_delete
//# define PRIMITIVE(n, ...) (void *[]){n##_new(__VA_ARGS__), EXPAND_FUNC(n)}
# define PRIMITIVE(obj, n, ...) primitive_##n##_init(obj, n##_init(__VA_ARGS__))

# include "object.h"
# include "sphere.h"
# include "cylinder.h"
# include "cone.h"
# include "plane.h"
# include "torus.h"
# include "rect.h"
# include "disk.h"

typedef union	u_primitive
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_sphere	sphere;
	t_sphere	sphere;
	t_sphere	sphere;
	t_sphere	sphere;
	t_sphere	sphere;
}				t_primitive;

void	primitive_sphere_init(t_object *object, t_sphere sphere);
void	primitive_cylinder_init(t_object *object, t_cylinder cylinder);
void	primitive_cone_init(t_object *object, t_cone cone);
void	primitive_plane_init(t_object *object, t_plane plane);
void	primitive_torus_init(t_object *object, t_torus torus);
void	primitive_rect_init(t_object *object, t_rect rect);
void	primitive_disk_init(t_object *object, t_disk disk);

#endif
