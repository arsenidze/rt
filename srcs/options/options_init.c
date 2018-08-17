/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:38:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 20:00:15 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

void					options_init(t_options *optns)
{
	optns->quit = 0;
	optns->is_antialiasing = 0;
	optns->is_stereoscopy = 0;
	optns->is_sepia = 0;
	optns->is_black_and_white = 0;
	optns->pixels_step_w = 1;
	optns->pixels_step_h = 1;
	optns->object_index = 0;
}
