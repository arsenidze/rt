/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_on_canvas_parallel.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:12:12 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 14:45:18 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "render_private.h"
#include "canvas.h"
#include <pthread.h>

static void	*render_on_canvas_single_wrap(void *v_arg)
{
	t_thread_arg *arg;

	arg = (t_thread_arg *)v_arg;
	render_on_canvas_single(arg->scene, arg->canvas, arg->options);
	return (NULL);
}

void		render_on_canvas_parallel(const t_scene *scene, t_canvas *canvas,
			const t_options *optns)
{
	pthread_t		threads_id[NTHREADS];
	t_thread_arg	args[NTHREADS];
	t_canvas		canvases[NTHREADS];
	int				i;

	i = 0;
	while (i < NTHREADS)
	{
		canvases[i] = (t_canvas){
				&CANVAS_GET_PIXEL((*canvas), 0, i * canvas->h / NTHREADS),
				.w = canvas->w,
				.h = (i + 1) * canvas->h / NTHREADS
					- i * canvas->h / NTHREADS,
				.pos_x = 0,
				.pos_y = (i * canvas->h / NTHREADS),
				.win_w = canvas->win_w,
				.win_h = canvas->win_h};
		args[i] = (t_thread_arg){scene, &canvases[i], optns};
		pthread_create(&threads_id[i], NULL, render_on_canvas_single_wrap,
			&args[i]);
		i++;
	}
	i = -1;
	while (++i < NTHREADS)
		pthread_join(threads_id[i], NULL);
}
