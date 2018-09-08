/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:16:48 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/10 17:09:53 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_base_range(char c, int base)
{
	if (base < 2 || base > 16 || !(IS_ALPHA(c) || IS_DIGIT(c)))
		return (0);
	if (IS_ALPHA(c) && base <= 10)
		return (0);
	if (IS_DIGIT(c))
		return (1);
	if ((10 + ft_toupper(c) - 'A') > base - 1)
		return (0);
	return (1);
}

static int	skip_prefix(char **s, int base)
{
	if (base == 2)
	{
		if (!(ft_strncmp(*s, "0b", 2) == 0 || ft_strncmp(*s, "0B", 2) == 0))
			return (-1);
		*s = *s + 2;
	}
	else if (base == 8)
	{
		if (!(ft_strncmp(*s, "0", 1) == 0))
			return (-1);
		*s = *s + 1;
	}
	else if (base == 16)
	{
		if (!(ft_strncmp(*s, "0x", 2) == 0 || ft_strncmp(*s, "0X", 2) == 0))
			return (-1);
		*s = *s + 2;
	}
	return (1);
}

int			atoi_base(char *str, int base)
{
	int					sign;
	unsigned long int	n;

	n = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\f' ||
			*str == '\v' || *str == '\n')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (skip_prefix(&str, base) == -1)
		return (0);
	while (in_base_range(*str, base))
	{
		if (IS_ALPHA(*str))
			n = base * n + (10 + ft_toupper(*str) - 'A');
		else
			n = base * n + (*str - '0');
		str++;
	}
	return ((int)(sign * (int)n));
}
