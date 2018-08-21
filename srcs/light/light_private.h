/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:07:38 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/21 13:34:02 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_PRIVATE_H
# define LIGHT_PRIVATE_H

# define LIGHT_GET_COMPONENTS(l) (t_vect3d[3]){l.ambient, l.diffuse, l.specular}

typedef double	t_vect3d __attribute__((vector_size(sizeof(double)*3)));
typedef struct s_intersection	t_intersection;

t_vect3d	calc_col(t_vect3d l_components[3], t_vect3d dir_to_light,
			const t_intersection *isect);

#endif
