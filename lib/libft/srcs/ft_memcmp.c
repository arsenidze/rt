/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:49:14 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/31 17:16:55 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(t_byte *)(s1 + i) != *(t_byte *)(s2 + i))
			return (*(t_byte *)(s1 + i) - *(t_byte *)(s2 + i));
		i++;
	}
	return (0);
}
