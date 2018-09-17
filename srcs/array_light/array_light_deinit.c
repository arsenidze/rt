/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_light_deinit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:03:39 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/17 17:04:54 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_light.h"
#include <stdlib.h>

void						array_light_deinit(t_array_light lights)
{
	free(lights.data);
}
