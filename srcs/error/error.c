/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:27:42 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 22:17:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <unistd.h>
#include <stddef.h>

static char	**get_err_addr(void)
{
	static char	*err;

	return (&err);
}

char		*get_err(void)
{
	return (*get_err_addr());
}

void		set_err(char *err)
{
	char **tmp;

	tmp = get_err_addr();
	*tmp = err;
}

void		try_set_err(char *err)
{
	char **tmp;

	tmp = get_err_addr();
	if (*tmp == NULL)
		*tmp = err;
}

int			err_print(char *prefix)
{
	char	*err;
	int		i;

	if (prefix)
	{
		i = 0;
		while (prefix[i])
			i++;
		write(2, prefix, i);
	}
	err = get_err();
	if (err)
	{
		i = 0;
		while (err[i])
			i++;
		write(2, err, i);
	}
	write(2, "\n", 1);
	return (1);
}
