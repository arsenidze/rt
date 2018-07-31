/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:24:28 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 20:01:34 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "equation.h"

double	equation_get_pos_root(t_equation eq)
{
	return (eq.roots[eq.pos_root_index]);
}

void	equation_set_pos_root(t_equation *eq)
{
	int		i;

	i = 0;
	while (i < eq->degree)
	{
		if (eq->roots[i] >= 0.0)
		{
			eq->pos_root_index = i;
			return ;
		}
		i++;
	}
	eq->pos_root_index = i - 1;
}

short	equation_step_to_next_pos_root(t_equation *eq)
{
	if (eq->pos_root_index < eq->degree - 1)
	{
		if (eq->roots[eq->pos_root_index + 1] > 0.0)
		{
			eq->pos_root_index++;
			return (1);
		}
		return (0);
	}
	return (0);
}
