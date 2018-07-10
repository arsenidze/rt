/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:52:22 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/01 16:29:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (n > 0)
	{
		if (*s1 != *s2 || *s1 == '\0')
		{
			if (*s1 == '\0')
				return (1);
			else
				return (0);
		}
		n--;
		s1++;
		s2++;
	}
	return (1);
}
