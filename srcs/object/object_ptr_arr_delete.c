/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ptr_arr_delete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 21:45:06 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 23:13:06 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "object_ptr_arr.h"
#include <stdlib.h>

void	object_ptr_arr_delete(t_object **objects)
{
	int		i;

	if (!objects)
		return ;
	i = 0;
	while (objects[i])
	{
		object_delete(objects[i]);
		i++;
	}
	free(objects);
}
