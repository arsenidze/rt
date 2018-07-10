/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:30:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:16:00 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

# define EXPAND_FUNC(n) n##_intersection, n##_get_normal, n##_delete
# define PRIMITIVE(n, ...) (void *[]){n##_new(__VA_ARGS__), EXPAND_FUNC(n)}

#endif
