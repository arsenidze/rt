/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:57:35 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/29 19:35:40 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	len;
	char	*p;

	len = 0;
	while (*(src + len) != '\0')
		len++;
	if (!(copy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	p = copy;
	while ((*p++ = *src++) != '\0')
		;
	return (copy);
}
