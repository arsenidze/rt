/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_object_deinit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:59:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/17 17:07:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_object.h" 
#include <stdlib.h>

void					array_object_deinit(t_array_object objects)
{
	t_uint i;

	i = 0;
	while (i < objects.size)
	{
		object_deinit(&objects.data[i]);
		i++;
	}
	free(objects.data);
}
