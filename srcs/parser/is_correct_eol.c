/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct_eol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:39:21 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 16:40:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

short	is_correct_eol(char *line)
{
	int	i;

	i = 0;
	while (line[i] && IS_WHITESPACE(line[i]))
		i++;
	return (line[i] == EOL);
}
