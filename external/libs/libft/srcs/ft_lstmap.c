/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:54:19 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/01 19:15:03 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del(void *content, size_t size)
{
	ft_bzero(content, size);
	free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*beg;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new = (*f)(lst)))
		return (NULL);
	beg = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = (*f)(lst)))
		{
			ft_lstdel(&beg, del);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (beg);
}
