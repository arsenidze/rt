/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_strs_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:12:08 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/08 18:20:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*list_strs_del(t_list **beg)
{
	t_list	*tmp;

	if (!beg || !*beg)
		return (NULL);
	tmp = *beg;
	while (tmp)
	{
		tmp = (*beg)->next;
		free_strs((char **)((*beg)->content), 0);
		free(*beg);
		*beg = tmp;
	}
	return (NULL);
}
