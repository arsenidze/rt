/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene_parallel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:23:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/13 15:05:08 by amelihov         ###   ########.fr       */
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
void		render_scene_parallel(t_scene *scene, t_canvas canvas,
			const t_userinput *userinput)
{
	pthread_t		threads_id[NTHREADS];
	unsigned int	i;

	i = 0;
	while (i < NTHREADS)
	{
		int tmp = (i * canvas.h / NTHREADS) * canvas.w;
		t_thread_arg *arg = 
		&(t_thread_arg){
			scene,
			(t_canvas){
				//&GET_PIXEL(canvas, 0, i * canvas.h / NTHREADS),
				&canvas.pixels[tmp],
				.w = canvas.w,
				.h = (i + 1) * canvas.h / NTHREADS
					- i * canvas.h / NTHREADS},
			userinput};
		printf("can_w: %u can_h: %u pixel: %ld\n", arg->canvas.w, arg->canvas.h,
			arg->canvas.pixels - canvas.pixels);
		printf("%p %p\n", canvas.pixels, arg->canvas.pixels);
		printf("tmp: %d\n", tmp);
		pthread_create(&threads_id[i], NULL, render_scene_wrap, arg);
		i++;
	}
	i = 0;
	while (i < NTHREADS)
	{
		pthread_join(threads_id[i], NULL);
		i++;
	}
}
