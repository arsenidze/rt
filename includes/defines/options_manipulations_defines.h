/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_manipulations_defines.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 20:00:12 by amelihov          #+#    #+#             */
/*   Updated: 2018/09/23 17:00:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_MANIPULATIONS_DEFINES_H
# define OPTIONS_MANIPULATIONS_DEFINES_H

# include "math.h"

# define MAX_PIXELS 10

# define REFLECTION_STEP	0.1
# define REFLECTION_MIN		0
# define REFLECTION_MAX		1
# define TRANSPARENCY_STEP	0.1
# define TRANSPARENCY_MIN	0
# define TRANSPARENCY_MAX	1
# define IOR_STEP			0.1
# define IOR_MIN			1
# define IOR_MAX			5

# define OBJECT_ROT_ANGLE 	(M_PI / 180.0) * 10.0
# define OBJECT_MOVE_STEP 	10

# define CAMERA_ROT_ANGLE 	(M_PI / 180.0) * 10.0
# define CAMERA_MOVE_STEP 	10

# define TEXTURE_OFFSET_STEP	10

# define TEXTURE_SCALE_STEP	0.1
# define TEXTURE_SCALE_MIN	0.1
# define TEXTURE_SCALE_MAX	1.0

#endif
