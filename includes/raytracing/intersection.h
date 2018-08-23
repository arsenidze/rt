/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:07:09 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/23 14:40:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "vect3d.h"
# include "object.h"
# include "ray.h"

typedef struct	s_intersection
{
	int				inside;
	t_ray			ray;
	t_vect3d		dest;
	t_vect3d		normal;
	const t_object	*hit_object;
}				t_intersection;

#endif
