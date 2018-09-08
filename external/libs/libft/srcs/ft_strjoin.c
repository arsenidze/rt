/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:32:20 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/01 15:19:53 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*beg;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
											ft_strlen(s2) + 1))))
		return (NULL);
	beg = res;
	while (*s1)
	{
		*res = *(char *)s1;
		res++;
		s1++;
	}
	while (*s2)
	{
		*res = *(char *)s2;
		res++;
		s2++;
	}
	*res = '\0';
	return (beg);
}
