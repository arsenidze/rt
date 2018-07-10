/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:17:27 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/29 20:38:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_byte	*odst;
	t_byte	*osrc;

	if (dst > src)
	{
		odst = dst + len - 1;
		osrc = (t_byte *)src + len - 1;
		while (len > 0)
		{
			*odst-- = *osrc--;
			len--;
		}
		return (++odst);
	}
	else
	{
		odst = (t_byte *)dst;
		osrc = (t_byte *)src;
		while (len > 0)
		{
			*odst++ = *osrc++;
			len--;
		}
		return (dst);
	}
}
