/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:33:51 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/29 19:13:11 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *pattern, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len && s[i])
	{
		j = 0;
		while (s[i + j] == pattern[j] && pattern[j] != '\0' && i + j < len)
			j++;
		if (pattern[j] == '\0')
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
