/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:39:45 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 12:53:17 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

typedef struct s_drawer	t_drawer;
typedef struct s_scene	t_scene;

void	event_handler_loop(t_drawer *drawer, t_scene *scene);

#endif
