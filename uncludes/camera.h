/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:44:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/05 21:20:41 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vect3d.h"

typedef struct	s_camera
{
	t_vect3d	pos;
	t_basis		basis;
	t_uint		w_canvas;
	t_uint		h_canvas;
}				t_camera;

t_camera		*camera_new(t_vect3d pos, t_vect3d dir, t_vect3d up);
void			camera_delete(t_camera *camera);
void			camera_rotate_ox(t_camera *camera, double angel);
void			camera_rotate_oy(t_camera *camera, double angel);
void			camera_rotate_oz(t_camera *camera, double angel);
void			camera_move(t_camera *camera, double step);

#endif
