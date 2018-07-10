/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:05:35 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 21:28:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vect3d.h"

void	camera_rotate_ox(t_camera *camera, double angel)
{
	t_vect3d	matrix_ox[3];

	vect3d_fill_rotate_ox_matrix(matrix_ox, angel);
	camera->dir = vect3d_mult_on_matrix(camera->dir, matrix_ox);
	camera->up = vect3d_mult_on_matrix(camera->up, matrix_ox);
	camera->left = vect3d_mult_on_matrix(camera->left, matrix_ox);
}

void	camera_rotate_oy(t_camera *camera, double angel)
{
	t_vect3d	matrix_oy[3];

	vect3d_fill_rotate_oy_matrix(matrix_oy, angel);
	camera->dir = vect3d_mult_on_matrix(camera->dir, matrix_oy);
	camera->up = vect3d_mult_on_matrix(camera->up, matrix_oy);
	camera->left = vect3d_mult_on_matrix(camera->left, matrix_oy);
}

void	camera_rotate_oz(t_camera *camera, double angel)
{
	t_vect3d	matrix_oz[3];

	vect3d_fill_rotate_oz_matrix(matrix_oz, angel);
	camera->dir = vect3d_mult_on_matrix(camera->dir, matrix_oz);
	camera->up = vect3d_mult_on_matrix(camera->up, matrix_oz);
	camera->left = vect3d_mult_on_matrix(camera->left, matrix_oz);
}
