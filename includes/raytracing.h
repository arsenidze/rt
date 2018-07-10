/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:23:36 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:21:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "drawer.h"
# include "scene.h"
# include "userinput.h"
# include "vect3d.h"
# include "intersection.h"

typedef struct	s_square
{
	int	top;
	int	left;
	int	size;
}				t_square;

void			render_scene(t_pixel *pixels, t_scene *scene,
				t_userinput *userinput);
short			find_closest_intersection(t_scene *scene, t_vect3d start,
				t_vect3d ray_dir, t_intersection *intersection);
t_color			trace_ray(t_scene *scene, t_vect3d ray_dir);

#endif
