/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   technical_effect.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:32:42 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 18:34:44 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TECHNICAL_EFFECT_H
# define TECHNICAL_EFFECT_H

# define TECHNICAL_EFFECT_SUCCESS	0
# define TECHNICAL_EFFECT_FAILURE	1

# define SCREENSHOT_DIR		"screenshots"

typedef struct s_canvas	t_canvas;

short	technical_effect_make_screenshot(const t_canvas *canvas);

#endif
