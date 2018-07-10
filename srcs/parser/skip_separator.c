/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_separator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:36:39 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 16:49:25 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

short	skip_separator(char *line, int *line_index)
{
	int	i;

	i = *line_index;
	while (line[i] && IS_WHITESPACE(line[i]))
		i++;
	*line_index = i;
	if (line[i] != SEPARATOR)
		return (0);
	*line_index += 1;
	return (1);
}
