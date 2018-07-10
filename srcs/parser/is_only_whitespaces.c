/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_whitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:41:15 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 16:43:46 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

short	is_only_whitespaces(char *line, char terminate_char)
{
	int	i;

	i = 0;
	while (line[i] && IS_WHITESPACE(line[i]))
		i++;
	return (line[i] == terminate_char);
}
