/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ptr_arr.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 21:11:01 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/05 17:42:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_PTR_ARR_H
# define OBJECT_PTR_ARR_H

typedef struct s_object	t_object;

void						object_ptr_arr_delete(t_object **objects);
int							object_ptr_arr_size(t_object **objects);

#endif
