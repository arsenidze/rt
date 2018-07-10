/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_ptr_arr_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:27:15 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 14:28:20 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_ptr_arr.h"

int		scene_ptr_arr_size(t_scene **scenes)
{
	int		i;

	if (!scenes)
		return (-1);
	i = 0;
	while (scenes[i])
		i++;
	return (i);
}
