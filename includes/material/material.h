/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:44:30 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/17 21:01:47 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct	s_material
{
	double	reflection;
	double	transparency;
	double	ior;
	double	ambient;
	double	diffuse;
	double	specular;

}				t_material;

#endif
