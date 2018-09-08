/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:17:51 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/10 16:53:40 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_strs(char **strs, size_t size)
{
	size_t	j;

	j = 0;
	if (j == 0)
	{
		while (strs[j])
			free(strs[j++]);
	}
	else
	{
		while (j < size)
			free(strs[j++]);
	}
	free(strs);
	return (NULL);
}
