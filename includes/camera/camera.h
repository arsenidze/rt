/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 09:44:22 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 19:55:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vect3d.h"
# include "basis.h"

typedef struct	s_camera
{
	t_vect3d	pos;
	t_basis		basis;
}				t_camera;

void			camera_rotate_ox(t_camera *camera, double angel);
void			camera_rotate_oy(t_camera *camera, double angel);
void			camera_rotate_oz(t_camera *camera, double angel);
void			camera_move(t_camera *camera, double step);

#endif
