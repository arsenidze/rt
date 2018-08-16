/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:42:00 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/15 16:28:06 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTER_H
# define FILTER_H

typedef double	t_vect3d __attribute__((vector_size(sizeof(double)*3)));
typedef struct s_options	t_options;

t_vect3d	filter_apply_sepia(t_vect3d color);
t_vect3d	filter_apply_black_and_white(t_vect3d color);
t_vect3d	filter_apply_filters(t_vect3d color, const t_options *optns);

#endif
