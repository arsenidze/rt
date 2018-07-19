/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:05:35 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/18 15:30:40 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vect3d.h"
#include <math.h>

void	camera_rotate_ox(t_camera *camera, double angel)
{
	camera->right = vect3d_rotate_around_axis(camera->right, camera->dir, angel);
	camera->up = vect3d_rotate_around_axis(camera->up, camera->dir, angel);
}

void	camera_rotate_oy(t_camera *camera, double angel)
{
	camera->dir = vect3d_rotate_around_axis(camera->dir, camera->right, angel);
	camera->up = vect3d_rotate_around_axis(camera->up, camera->right, angel);
}

void	camera_rotate_oz(t_camera *camera, double angel)
{
	camera->dir = vect3d_rotate_around_axis(camera->dir, camera->up, angel);
	camera->right = vect3d_rotate_around_axis(camera->right, camera->up, angel);
}
