/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 23:10:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 22:14:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define NTHREADS	4
# define STEREOSCOPY_OFFSET	10

typedef struct s_scene		t_scene;
typedef struct s_canvas		t_canvas;
typedef struct s_options	t_options;

void	render_on_canvas_single(const t_scene *scene, t_canvas *canvas,
		const t_options *optns);
void	render_on_canvas_parallel(const t_scene *scene, t_canvas *canvas,
		const t_options *optns);
void	render_on_canvas(const t_scene *scene, t_canvas *canvas,
		const t_options *optns);
void	render_on_canvas_with_stereoscopy(const t_scene *scene,
		t_canvas *canvas, const t_options *optns);

#endif
