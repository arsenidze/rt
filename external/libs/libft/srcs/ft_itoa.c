/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:20:47 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/31 17:25:13 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*number;
	size_t	i;
	long	tmp;
	size_t	sign;

	sign = n < 0 ? 1 : 0;
	tmp = n;
	tmp = tmp < 0 ? -tmp : tmp;
	i = 1;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	if (!(number = (char *)malloc(sizeof(char) * (sign + i + 1))))
		return (NULL);
	number[i + sign] = '\0';
	while (i > 0)
	{
		number[i - 1 + sign] = tmp % 10 + '0';
		tmp /= 10;
		i--;
	}
	number[0] = sign ? '-' : number[0];
	return (number);
}
