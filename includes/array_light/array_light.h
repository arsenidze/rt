/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_light.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:07:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/17 17:04:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_LIGHT_H
# define ARRAY_LIGHT_H

# include "light.h"

typedef unsigned int		t_uint;

typedef struct				s_array_light
{
	t_light		*data;
	t_uint		size;
}							t_array_light;

void						array_light_deinit(t_array_light lights);

#endif
