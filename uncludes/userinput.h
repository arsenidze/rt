/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:12:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/12 21:02:39 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINPUT_H
# define USERINPUT_H

typedef unsigned char	t_byte;

typedef struct			s_userinput
{
	t_byte	quit;
	t_byte	is_antialiasing;
	int		scene_index;
	int		object_index;
	int		step_in_pixels;
	int		nscenes;
	int		nobjects;
}						t_userinput;

void					init_userinput(t_userinput *userinput,
						int nobjects, int nscenes);

#endif
