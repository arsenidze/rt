/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:32:47 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/13 11:57:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "userinput.h"

void	init_userinput(t_userinput *userinput, int nobjects, int nscenes)
{
	*userinput = (t_userinput){
		.quit = 0,
		.scene_index = 0,
		.object_index = 0,
		.step_in_pixels = 1,
		.nscenes = nscenes,
		.nobjects = nobjects,
		.is_antialiasing = 0
	};
}
