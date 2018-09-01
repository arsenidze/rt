/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_put_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 19:23:00 by snikitin          #+#    #+#             */
/*   Updated: 2018/09/01 17:35:26 by snikitin         ###   ########.fr       */
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
	//if (error_code == COLOR_VALUE_BIG)
	//	ft_putstr_fd("ERROR:\t Invalid value. "
	//			"Color value should be no greater than 255.", 2);
	ft_putnbr(error_code);
	ft_putchar('\n');
}
