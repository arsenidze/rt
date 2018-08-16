/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:40:36 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/12 18:16:47 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

# include "sphere.h"
# include "cylinder.h"
# include "cone.h"
# include "plane.h"
# include "torus.h"
# include "paraboloid.h"
# include "rect.h"
# include "disk.h"
# include "cuboid.h"

# define PRIMITIVE(n, ...) (t_primitive){.n = n##_create(__VA_ARGS__)}
# define PRIMITIVE_AS(n, p) (t_primitive){.n = p}

typedef union	u_primitive
{
	t_sphere		sphere;
	t_cylinder		cylinder;
	t_cone			cone;
	t_plane			plane;
	t_torus			torus;
	t_paraboloid	paraboloid;
	t_rect			rect;
	t_disk			disk;
	t_cuboid		cuboid;
}				t_primitive;

#endif
