/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:27:42 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:12:32 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "errors.h"
# include "errors_defines.h"

/*
**	set_err:
**	setter to error variable
*/
void	set_err(char *err);

/*
**	get_err:
**	getter for error variable
*/
char	*get_err(void);

/*
**	try_set_err:
**	check if error variable is NULL then set it to input char *err
*/
void	try_set_err(char *err);

/*
**	print_err:
**	printf value of error variable, if prefix is not NULL add it at begin
*/
int		err_print(char *prefix);

#endif
