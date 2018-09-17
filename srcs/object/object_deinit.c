/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_deinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:07:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/17 17:11:08 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "texture.h"
#include <stdlib.h>

void			object_deinit(t_object *obj)
{
	texture_deinit(&obj->texture);
}
