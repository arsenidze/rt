/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene_parallel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:23:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/14 17:26:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parallelism.h"
#include "scene.h"
#include "drawer.h"
#include "userinput.h"
#include "raytracing.h"
#include <pthread.h>

static void	*render_scene_wrap(void *v_arg)
{
	t_thread_arg *arg;

	arg = (t_thread_arg *)v_arg;
	render_scene(arg->scene, arg->canvas, arg->userinput);
	return (NULL);
}
#include <stdio.h>
void		render_scene_parallel(const t_scene *scene, t_canvas canvas,
			const t_userinput *userinput)
{
	pthread_t		threads_id[NTHREADS];
	unsigned int	i;

	t_thread_arg	arg[NTHREADS];	

	i = 0;
	while (i < NTHREADS)
	{
		int tmp = (i * canvas.h / NTHREADS) * canvas.w;
		arg[i] = 
		(t_thread_arg){
			scene,
			(t_canvas){
				//&GET_PIXEL(canvas, 0, i * canvas.h / NTHREADS),
				&canvas.pixels[tmp],
				.w = canvas.w,
				.h = (i + 1) * canvas.h / NTHREADS
					- i * canvas.h / NTHREADS,
				.pos_x = 0,
				.pos_y = (i * canvas.h / NTHREADS)},
			userinput};
//		printf("can_w: %u can_h: %u offset: %d\n", arg[i].canvas.w,
//				arg[i].canvas.h, tmp);
		pthread_create(&threads_id[i], NULL, render_scene_wrap, &arg[i]);
		i++;
	}
	i = 0;
	while (i < NTHREADS)
	{
		pthread_join(threads_id[i], NULL);
		i++;
	}
}
