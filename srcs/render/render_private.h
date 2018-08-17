/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:39:11 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 14:37:52 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_PRIVATE_H
# define RENDER_PRIVATE_H

typedef struct s_scene		t_scene;
typedef struct s_canvas		t_canvas;
typedef struct s_options	t_options;

typedef struct	s_thread_arg
{
	const t_scene		*scene;
	t_canvas			*canvas;
	const t_options		*options;
}				t_thread_arg;

#endif
