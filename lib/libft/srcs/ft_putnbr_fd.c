/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:46:58 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/29 19:46:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_recur_putnbr_fd(size_t n, int fd)
{
	if (n / 10)
		ft_recur_putnbr_fd(n / 10, fd);
	n = n % 10 + '0';
	write(fd, &n, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	long int	t;

	if (n < 0)
	{
		write(fd, "-", 1);
		t = n;
		t = -t;
		ft_recur_putnbr_fd((size_t)t, fd);
	}
	else
		ft_recur_putnbr_fd((size_t)n, fd);
}
