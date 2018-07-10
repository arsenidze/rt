/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:06:08 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/01 17:18:25 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	nw;
	char	is_word;

	nw = 0;
	is_word = 0;
	while (*s)
	{
		if (*s == c && is_word)
			is_word = 0;
		else if (*s != c && !is_word)
		{
			is_word = 1;
			nw++;
		}
		s++;
	}
	return (nw);
}

static void		*clear_arr(char ***words)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (*words)[i];
	while (tmp)
	{
		tmp = (*words)[i + 1];
		free((*words)[i]);
		(*words)[i] = NULL;
		(*words)[i] = tmp;
		i++;
	}
	free(*words);
	*words = NULL;
	return (NULL);
}

static void		modified_strncpy(char *s1, const char *s2, size_t n)
{
	ft_strncpy(s1, s2, n);
	s1[n] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	nw;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	nw = count_words(s, c);
	if (!(words = (char **)malloc(sizeof(char *) * (nw + 1))))
		return (NULL);
	i = 0;
	while (i < nw)
	{
		while (*s == c && *s != '\0')
			s++;
		len = 0;
		while (s[len] != c && s[len] != '\0')
			len++;
		if (!(words[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (clear_arr(&words));
		modified_strncpy(words[i++], s, len);
		s += len;
	}
	words[i] = NULL;
	return (words);
}
