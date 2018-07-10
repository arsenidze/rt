/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:52:17 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 22:31:41 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "libft.h"
#include <stdlib.h>

void	light_delete(t_light *light)
{
	free(light);
}

t_light	*light_new(t_vect3d pos, t_vect3d components[3])
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		return (NULL);
	light->pos = pos;
	ft_memcpy(light->components, components, sizeof(t_vect3d) * 3);
	return (light);
}
