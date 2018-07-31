/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:52:52 by amelihov          #+#    #+#             */
/*   Updated: 2018/07/27 22:13:32 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "composed.h"
#include <stdlib.h>

#define IS_INTERSECT_OBJ(s, r, o, i) o->intersection(o->primitive,s,r,i)

short		composed_intersection(void *v_composed, t_vect3d start,
			t_vect3d ray_dir, t_vect3d *intersect_point)
{
	t_composed	*composed;
	int			i;
	t_vect3d	tmp_isect_pnt;
	t_vect3d	closest_isect_pnt;
	short		is_intersect;

	is_intersect = 0;
	composed = (t_composed *)v_composed;
	i = 0;
	while (i < composed->n)
	{
		if (IS_INTERSECT_OBJ(start, ray_dir, composed->parts[i], &tmp_isect_pnt))
		{
			if (!is_intersect
				|| vect3d_sq_len(closest_isect_pnt - start)
					> vect3d_sq_len(tmp_isect_pnt - start))
			{
				closest_isect_pnt = tmp_isect_pnt;
				composed->closest_part_index = i;
			}
			is_intersect = 1;	
		}
		i++;
	}
	if (!is_intersect)
		return (0);
	if (intersect_point)
		*intersect_point = closest_isect_pnt;
	return (1);
}

void		composed_delete(void *v_composed)
{
	t_composed	*composed;
	int			i;
	
	composed = (t_composed *)v_composed;
	i = 0;
	while (i < composed->n)
	{
		object_delete(composed->parts[i]);
		i++;
	}
	free(composed);
}

t_vect3d	composed_get_normal(void *v_composed, t_vect3d point)
{
	t_composed	*composed;
	int			closest_index;
	t_vect3d	normal;

	composed = (t_composed *)v_composed;
	closest_index = composed->closest_part_index;
	if (closest_index == -1)
		return (vect3d(1, 0, 0));
	normal = GET_NORMAL(composed->parts[closest_index], point);
	return (normal);
}

t_composed				*composed_new(t_vect3d pos, t_object **parts, int n)
{
	t_composed	*composed;
	int			i;

	if (!(composed = malloc(sizeof(t_composed))))
		return (NULL);
	composed->pos = pos;
	composed->parts = parts;
	composed->n = n;
	composed->closest_part_index = -1;
	i = 0;
	while (i < n)
	{
		*(t_vect3d *)composed->parts[i]->primitive += pos;
		i++;
	}
	return (composed);
}
