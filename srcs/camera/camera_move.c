/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:15:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/06 17:25:55 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vect3d.h"

void	camera_move(t_camera *camera, double step)
{
	camera->pos += vect3d_mult_on_scalar(camera->basis.x, step);
}
