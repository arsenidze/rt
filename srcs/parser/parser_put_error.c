/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_put_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 19:23:00 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/02 16:43:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"
#include "libft.h"

void	parser_put_error_mapping(char *name)
{
	ft_putstr_fd("ERROR:\tin mapping field: ", 2);
	ft_putendl_fd(name, 2);
}

void	parser_put_error_sequence(unsigned int entry_num)
{
	ft_putstr_fd("ERROR:\tin sequence entry: ", 2);
	ft_putnbr_fd(entry_num + 1, 2);
	ft_putchar_fd('\n', 2);
}

void	parser_put_error_code(unsigned int error_code)
{
	static const char	*parsing_errors[] = {
		"Invalid number of types. Only one type should be specified.",
		"Invalid number of types. At least one type should be specified.",
		"Invalid value. Value too big.",
		"Invalid value. Value too low.",
		"Invalid values. Outer radius should be bigger than inner radius."
		"Invalid values. Direction vector cannot be null vector."};

	ft_putstr_fd("ERROR:\t", 2);
	ft_putendl_fd(parsing_errors[error_code - 1], 2);
	ft_putchar('\n');
}
