/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:05:35 by amelihov          #+#    #+#             */
/*   basis.zdated: 2018/07/18 15:30:40 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vect3d.h"

void	camera_rotate_ox(t_camera *camera, double angel)
{
	camera->basis.y = vect3d_rotate_around_axis(camera->basis.y,
		camera->basis.x, angel);
	camera->basis.z = vect3d_rotate_around_axis(camera->basis.z,
		camera->basis.x, angel);
}

void	camera_rotate_oy(t_camera *camera, double angel)
{
	camera->basis.x = vect3d_rotate_around_axis(camera->basis.x,
		camera->basis.y, angel);
	camera->basis.z = vect3d_rotate_around_axis(camera->basis.z,
		camera->basis.y, angel);
}

void	camera_rotate_oz(t_camera *camera, double angel)
{
	camera->basis.x = vect3d_rotate_around_axis(camera->basis.x,
		camera->basis.z, angel);
	camera->basis.y = vect3d_rotate_around_axis(camera->basis.y,
		camera->basis.z, angel);
}
