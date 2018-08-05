/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:45:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/05 20:05:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct	s_sphere
{
	double		radius;
	double		h;
}				t_sphere;

void			primitive_sphere_init(t_object *object, t_sphere sphere)
{
	object->primitive.sphere = sphere;
	object->intersection = sphere_intersection;
	object->get_normal = sphere_get_normal;
	object->get_tex_coord = sphere_get_tex_coord;
}

typedef struct	s_object
{
	t_vect3d	pos;
	t_basis		basis;
	t_primitive	primitive;
	t_material	material;
	t_texture	tex;
	short		(*intersection)(t_object *object, t_ray ray,
				t_vect3d *intersect_point);
	t_vect3d	(*get_normal)(t_object *object, t_vect3d point);
	void		(*get_tex_coord)(t_object *object, t_vect3d point,
				float coord[2]);
}				t_object;

#endif
