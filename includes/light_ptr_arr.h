/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ptr_arr.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 20:56:42 by amelihov          #+#    #+#             */
/*   Updated: 2018/06/15 21:13:26 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_PTR_ARR_H
# define LIGHT_PTR_ARR_H

typedef struct s_light	t_light;

typedef t_light**		t_light_ptr_arr;

void					light_ptr_arr_delete(t_light **lights);
#endif
