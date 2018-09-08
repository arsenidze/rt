/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:00:40 by amelihov          #+#    #+#             */
/*   Updated: 2018/03/30 16:15:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		modified_strdel(char **str)
{
	ft_strdel(str);
	return (0);
}

static int		pop_line(char *buff, char **line)
{
	int		i;
	char	*s;
	int		res;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	res = buff[i];
	buff[i] = '\0';
	if (!(s = ft_strjoin(*line ? *line : "", buff)))
		return (-1);
	if (*line)
		free(*line);
	*line = s;
	if (i == BUFF_SIZE)
		buff[0] = '\0';
	else
	{
		ft_memmove(buff, buff + i + 1, BUFF_SIZE - (i + 1));
		buff[BUFF_SIZE - (i + 1)] = '\0';
	}
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	int					ret;
	int					res;
	static t_gnl_data	data[NFDS];
	int					i;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || NFDS <= 0 || (*line = NULL))
		return (-1);
	i = 0;
	while (i < NFDS && data[i].fd != 0 && data[i].fd != fd + 1)
		i++;
	if (i == NFDS)
		return (-1);
	data[i].fd = fd + 1;
	while ((res = pop_line(data[i].buff, line)) == '\0')
	{
		if ((ret = read(data[i].fd - 1, data[i].buff, BUFF_SIZE)) < 0)
			return (-1);
		data[i].buff[ret] = '\0';
		if (ret == 0)
			return (**line != '\0' ? 1 : modified_strdel(line));
	}
	return (res == -1 ? -1 : 1);
}
