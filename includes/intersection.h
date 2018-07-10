/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:07:09 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/06 14:14:46 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "vect3d.h"
# include "object.h"

typedef struct	s_intersection
{
	t_vect3d	orig;
	t_vect3d	dest;
	t_vect3d	ray_dir;
	t_vect3d	normal;
	t_object	*hit_object;
}				t_intersection;

#endif
