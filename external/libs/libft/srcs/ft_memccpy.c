/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:12:41 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/26 11:40:05 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(t_byte *)(dst + i) = *(t_byte *)(src + i);
		if (*(t_byte *)(src + i) == (t_byte)c)
			return ((t_byte *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
