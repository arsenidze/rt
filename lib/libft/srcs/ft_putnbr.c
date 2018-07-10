/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:46:58 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/31 16:43:22 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_recur_putnbr(size_t n)
{
	if (n / 10)
		ft_recur_putnbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}

void			ft_putnbr(int n)
{
	long int	t;

	if (n < 0)
	{
		write(1, "-", 1);
		t = n;
		t = -t;
		ft_recur_putnbr((size_t)t);
	}
	else
		ft_recur_putnbr((size_t)n);
}
