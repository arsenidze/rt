/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 19:09:18 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 19:53:21 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMATH_H
# define MMATH_H

# include <float.h>

# define INF DBL_MAX

typedef double	t_vect3d __attribute__((vector_size(sizeof(double)*3)));

double		clampd(double x, double a, double b);
int			clampi(int x, int a, int b);
double		get_positive_root(double c[3]);
double		square(double x);

double		cb(double x);
int			sign(double x);

int			solve4(double c[5], double roots[4]);
int			solve3(double c[4], double roots[3]);
int			solve2(double c[3], double roots[2]);

#endif
