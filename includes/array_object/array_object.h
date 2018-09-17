/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_object.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:07:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/17 17:03:56 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_OBJECT_H
# define ARRAY_OBJECT_H

# include "object.h"

typedef unsigned int	t_uint;

typedef struct			s_array_object
{
	t_object	*data;
	t_uint		size;
}						t_array_object;

void					array_object_deinit(t_array_object objects);

#endif
