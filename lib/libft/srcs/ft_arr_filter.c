/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:05:37 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/01 21:50:32 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_arr_filter(int *arr, size_t n, int (*f)(int))
{
	int		i;
	size_t	j;
	size_t	good;
	int		*new;

	if (!arr || !f)
		return (NULL);
	good = 0;
	i = -1;
	while (++i < (int)n)
		if ((*f)(arr[i]) == 1)
			good++;
	if (!(new = malloc(sizeof(int) * good)))
		return (NULL);
	j = 0;
	i = -1;
	while (++i < (int)n)
		if ((*f)(arr[i]) == 1)
			new[j++] = arr[i];
	return (new);
}
