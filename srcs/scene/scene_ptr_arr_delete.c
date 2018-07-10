/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_ptr_arr_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 21:41:14 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 23:15:18 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "scene_ptr_arr.h"
#include <stdlib.h>

void	scene_ptr_arr_delete(t_scene **scenes)
{
	int		i;

	if (!scenes)
		return ;
	i = 0;
	while (scenes[i])
	{
		scene_delete(scenes[i]);
		i++;
	}
	free(scenes);
}
