/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:06:43 by amelihov          #+#    #+#             */
/*   Updated: 2017/11/01 20:32:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	i = ft_strlen(s) - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	if (i == 0)
		return (ft_strnew(0));
	if (!(new = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	ft_strncpy(new, s, i + 1);
	new[i + 1] = '\0';
	return (new);
}
