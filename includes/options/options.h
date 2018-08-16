/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:39:41 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 19:39:18 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

typedef unsigned char	t_byte;

typedef struct			s_options
{
	t_byte	quit;
	t_byte	is_antialiasing;
	t_byte	is_stereoscopy;
	t_byte	is_sepia;
	t_byte	is_black_and_white;
	int		pixels_step_w;
	int		pixels_step_h;
	int		object_index;
}						t_options;

void					options_init(t_options *optns);
short					options_is_filters_on(const t_options *optns);

#endif
