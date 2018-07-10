/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ptr_arr_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 21:42:44 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 23:12:52 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "light_ptr_arr.h"
#include <stdlib.h>

void	light_ptr_arr_delete(t_light **lights)
{
	int		i;

	if (!lights)
		return ;
	i = 0;
	while (lights[i])
	{
		light_delete(lights[i]);
		i++;
	}
	free(lights);
}
