/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:58:22 by amelihov          #+#    #+#             */
/*   Updated: 2017/10/28 23:05:35 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;
	void	*data;

	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if ((void *)content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(data = malloc(sizeof(content_size))))
		{
			free(elem);
			return (NULL);
		}
		ft_memcpy(data, content, content_size);
		elem->content = data;
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
