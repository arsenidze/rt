/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallelism.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:54:37 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/10 14:31:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARALLELISM_H
# define PARALLELISM_H

# include "canvas.h"

#define NTHREADS	4

typedef struct s_scene		t_scene;
//typedef struct s_canvas		t_canvas;
typedef struct s_options	t_options;

void						render_scene_parallel(const t_scene *scene,
							t_canvas canvas, const t_options *options);

typedef struct				s_thread_arg
{
	const t_scene		*scene;
	t_canvas			canvas;
	const t_options		*options;
}							t_thread_arg;

#endif
