/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_left_positive_roots.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:44:16 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/12 15:08:37 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sort_and_left_positive_roots(double *roots, int n)
{
	int		i;
	double	storage[n];
	int		num_pos_roots;
	int		j;
	double	tmp;

	num_pos_roots = n;
	j = 0;
	i = -1;
	while (++i < n)
	{
		if (roots[i] > 0.0)
			storage[j++] = roots[i];
		else
			num_pos_roots--;
	}
	i = 0;
	while (i < num_pos_roots - 1)
	{
		if (storage[i] > storage[i + 1])
		{
			tmp = storage[i];
			storage[i] = storage[i + 1];
			storage[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	i = -1;
	while (++i < num_pos_roots)
		roots[i] = storage[i];
	return (num_pos_roots);
}
