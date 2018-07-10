/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:18:37 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/01 19:08:19 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *pattern)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] == pattern[j] && pattern[j] != '\0')
			j++;
		if (pattern[j] == '\0')
			return ((char *)(s + i));
		i++;
	}
	if (s[0] == '\0' && pattern[0] == '\0')
		return ((char *)s);
	return (NULL);
}
