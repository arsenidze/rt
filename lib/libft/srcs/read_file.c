/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:42:09 by amelihov          #+#    #+#             */
/*   Updated: 2018/01/08 18:15:19 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

#define NLINES 64

static t_list	*create_elem(char **lines)
{
	t_list	*new_elem;

	if ((new_elem = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new_elem->content = lines;
	new_elem->content_size = sizeof(lines);
	new_elem->next = NULL;
	return (new_elem);
}

static void		list_push_back(t_list **begin_list, char **lines)
{
	t_list	*p;

	if (!*begin_list)
		(*begin_list) = create_elem(lines);
	else
	{
		p = *begin_list;
		while (p->next)
			p = p->next;
		p->next = create_elem(lines);
	}
}

static int		fill_lines(int fd, char **lines)
{
	int		i;
	int		ret;

	i = 0;
	while (i < NLINES && (ret = get_next_line(fd, &lines[i])) > 0)
		i++;
	if (ret < 0)
		return (-1);
	lines[ret == 0 ? i + 1 : i] = NULL;
	return (i);
}

static void		copy_lines(t_list **beg, char **lines)
{
	t_list	*t;
	int		i;
	int		j;

	j = 0;
	t = *beg;
	while (t)
	{
		i = 0;
		while (((char **)(t->content))[i])
		{
			lines[j++] = ((char **)(t->content))[i];
			i++;
		}
		free(((char **)(t->content)));
		t = t->next;
		free(*beg);
		*beg = t;
	}
	lines[j] = NULL;
}

char			**read_file(const char *file_name)
{
	char			**lines;
	int				fd;
	int				ret;
	int				total;
	t_list			*beg;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	if (!(lines = malloc(sizeof(char *) * (NLINES + 1))))
		return (NULL);
	beg = NULL;
	list_push_back(&beg, lines);
	total = 0;
	while ((total += (ret = fill_lines(fd, lines))) && (ret == NLINES))
	{
		if (!(lines = malloc(sizeof(char *) * (NLINES + 1))) || ret < 0)
			return (list_strs_del(&beg));
		list_push_back(&beg, lines);
	}
	close(fd);
	if (!(lines = malloc(sizeof(char *) * (total + 1))) || ret < 0)
		return (list_strs_del(&beg));
	copy_lines(&beg, lines);
	return (lines);
}
