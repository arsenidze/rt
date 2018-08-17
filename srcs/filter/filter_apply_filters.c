/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_apply_filters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:28:49 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 16:30:04 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"
#include "vect3d.h"
#include "options.h"

t_vect3d	filter_apply_filters(t_vect3d color, const t_options *optns)
{
	if (optns->is_sepia)
		color = filter_apply_sepia(color);
	if (optns->is_black_and_white)
		color = filter_apply_black_and_white(color);
	return (color);
}
