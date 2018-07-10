/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 19:09:18 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 19:11:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMATH_H
# define MMATH_H

double	clampd(double x, double a, double b);
int		clampi(int x, int a, int b);
double	get_positive_root(double c[3]);
double	square(double x);

#endif
