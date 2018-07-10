/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_loop.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:49:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:14:27 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLER_LOOP_H
# define EVENT_HANDLER_LOOP_H

# include "drawer.h"
# include "scene.h"

void	event_handler_loop(t_drawer *drawer, t_scene **scenes);

#endif
