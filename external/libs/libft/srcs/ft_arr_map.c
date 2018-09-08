/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:45:25 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/01 21:46:10 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_arr_map(int *arr, size_t n, int (*f)(int))
{
	size_t	i;
	int		*mapped;

	if (!arr || !f)
		return (NULL);
	if (!(mapped = malloc(sizeof(int) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		mapped[i] = (*f)(arr[i]);
		i++;
	}
	return (mapped);
}
