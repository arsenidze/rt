/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 19:09:18 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/26 14:27:32 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMATH_H
# define MMATH_H

#include <float.h>

#define INF DBL_MAX

typedef double	t_vect3d __attribute__((vector_size(sizeof(double)*3)));

double		clampd(double x, double a, double b);
int			clampi(int x, int a, int b);
double		get_positive_root(double c[3]);
double		square(double x);
double		get_rand(void);

void		solve3(double c[4], double roots[3]);
double		cube(double x);
int			sign(double x);

void		solve4(double c[5], double roots[4]);
void		solve2(double c[3], double roots[2]);
t_vect3d	random_in_unit_sphere(void);

#endif
