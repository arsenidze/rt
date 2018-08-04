/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:30:56 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/04 16:26:45 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

# define FUNC(n) n##_intersection,n##_get_normal,n##_get_tex_coord,n##_delete
# define PRIMITIVE(n, ...) (void *[]){n##_new(__VA_ARGS__), FUNC(n)}

#endif
