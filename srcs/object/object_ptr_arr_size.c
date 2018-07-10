/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ptr_arr_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:32:01 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 17:33:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_ptr_arr.h"

int		object_ptr_arr_size(t_object **objects)
{
	int		i;

	if (!objects)
		return (-1);
	i = 0;
	while (objects[i])
		i++;
	return (i);
}
