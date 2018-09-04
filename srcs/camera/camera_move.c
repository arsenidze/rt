/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:15:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/04 18:32:15 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vect3d.h"

void	camera_move_forward_backward(t_camera *camera, double step)
{
	camera->pos += vect3d_mult_on_scalar(camera->basis.x, step);
}

void	camera_move_left_right(t_camera *camera, double step)
{
	camera->pos += vect3d_mult_on_scalar(camera->basis.y, step);
}

void	camera_move_up_down(t_camera *camera, double step)
{
	camera->pos += vect3d_mult_on_scalar(camera->basis.z, step);
}
