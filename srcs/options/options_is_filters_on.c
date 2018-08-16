/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_is_filters_on.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:38:02 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 16:40:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

short					options_is_filters_on(const t_options *optns)
{
	return (optns->is_sepia || optns->is_black_and_white);
}
