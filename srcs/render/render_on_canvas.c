/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_on_canvas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 23:14:07 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 14:18:27 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_on_canvas(const t_scene *scene, t_canvas *canvas,
		const t_options *optns)
{
	render_on_canvas_parallel(scene, canvas, optns);
}
