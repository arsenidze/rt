/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:11:34 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 21:46:31 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT3D_H
# define VECT3D_H

typedef double	t_vect3d __attribute__((vector_size(sizeof(double)*3)));

# define X 0
# define Y 1
# define Z 2

# define VECT3D_3(v1, v2, v3) (t_vect3d[3]){v1, v2, v3}

t_vect3d	vect3d(double x, double y, double z);
t_vect3d	vect3d_mult_on_scalar(t_vect3d v, double a);
t_vect3d	vect3d_div_on_scalar(t_vect3d v, double a);
double		vect3d_len(t_vect3d v);
t_vect3d	vect3d_norm(t_vect3d v);
double		vect3d_sq_len(t_vect3d v);
double		vect3d_dot(t_vect3d v1, t_vect3d v2);
t_vect3d	vect3d_cross(t_vect3d v1, t_vect3d v2);
double		vect3d_cos(t_vect3d v1, t_vect3d v2);
double		vect3d_cos_normed(t_vect3d v1, t_vect3d v2);
t_vect3d	vect3d_clamp(t_vect3d v, double a, double b);
short		vect3d_is_in_range(t_vect3d v, double a, double b);
short		vect3d_is_in_range_abs(t_vect3d v, double a, double b);
t_vect3d	vect3d_mult_on_matrix(t_vect3d v, t_vect3d m[3]);
void		vect3d_fill_rotate_ox_matrix(t_vect3d m[3], double angel);
void		vect3d_fill_rotate_oy_matrix(t_vect3d m[3], double angel);
void		vect3d_fill_rotate_oz_matrix(t_vect3d m[3], double angel);

#endif
