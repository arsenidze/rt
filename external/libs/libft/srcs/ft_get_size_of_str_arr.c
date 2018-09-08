/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_of_str_arr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 22:06:24 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 21:00:56 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size_of_str_arr(char **lines)
{
	int		i;

	if (!lines)
		return (-1);
	i = 0;
	while (lines[i])
		i++;
	return (i);
}
