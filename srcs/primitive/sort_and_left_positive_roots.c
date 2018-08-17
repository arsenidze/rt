/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_left_positive_roots.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:44:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 14:17:24 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primitive_private.h"
#include "libft.h"

static void	slow_sortd(double *a, int n)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < n - 1)
	{
		if (a[i] > a[i + 1])
		{
			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void	left_only_positive(double *roots, int n, double *storage,
			int *num_pos_roots)
{
	int	i;
	int	j;
	int	m;

	m = n;
	j = 0;
	i = 0;
	while (i < n)
	{
		if (roots[i] > 0.0)
			storage[j++] = roots[i];
		else
			m--;
		i++;
	}
	*num_pos_roots = m;
}

int			sort_and_left_positive_roots(double *roots, int n)
{
	double	storage[n];
	int		num_pos_roots;

	left_only_positive(roots, n, storage, &num_pos_roots);
	slow_sortd(storage, num_pos_roots);
	ft_memcpy(roots, storage, sizeof(double) * num_pos_roots);
	return (num_pos_roots);
}
