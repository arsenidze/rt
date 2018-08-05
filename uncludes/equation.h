/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:07:46 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/31 17:36:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_H
# define EQUATION_H

typedef struct	s_equation
{
	int		degree;
	double	*coeffs;
	double	*roots;
	int		pos_root_index;
}				t_equation;

double	equation_get_pos_root(t_equation eq);
void	equation_set_pos_root(t_equation *eq);
short	equation_step_to_next_pos_root(t_equation *eq);

#endif
