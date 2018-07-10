/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:44:15 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/30 16:15:48 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 32
# define NFDS 1

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl_data
{
	char	buff[BUFF_SIZE + 1];
	int		fd;
}				t_gnl_data;

#endif
