/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:44:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/20 20:50:36 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct	s_material
{
	t_vect3d	ambient;
	t_vect3d	diffuse;
	t_vect3d	specular;
	double		shininess;
	double		reflection;
	double		transparency;
	double		ior;
}				t_material;

#endif
