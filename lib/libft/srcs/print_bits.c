/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:03:30 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/21 21:31:01 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_bits(t_uint b, t_byte nbits)
{
	t_uint	index;

	if (nbits == 0)
		return ;
	index = 1 << (nbits - 1);
	while (index != 0)
	{
		if (b & index)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		index >>= 1;
	}
}
