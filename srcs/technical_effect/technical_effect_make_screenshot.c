/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   technical_effect_make_screenshot.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelihov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:35:23 by amelihov          #+#    #+#             */
/*   Updated: 2018/08/16 22:47:42 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "technical_effect.h"
#include "canvas.h"
#include "SDL.h"
#include "SDL_image.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "libft.h"

static int	try_make_dir(char *dirname)
{
	int	status;

	status = mkdir(dirname, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	if (status == 0)
		return (0);
	if (errno == EEXIST)
		return (0);
	else
		return (1);
}

static char	*get_screenshot_name(unsigned long int screenshot_num)
{
	char	*tmp;
	char	*screenshot_name;

	if (!(tmp = ft_itoa(screenshot_num)))
		return (NULL);
	if (!(screenshot_name = ft_strjoin(SCREENSHOT_DIR"/screenshot", tmp)))
		return (NULL);
	free(tmp);
	if (!(tmp = ft_strjoin(screenshot_name, ".png")))
		return (NULL);
	free(screenshot_name);
	screenshot_name = tmp;
	return (screenshot_name);
}

#define PIXEL_DEPTH	32

#define RMASK	0x00FF0000
#define GMASK	0x0000FF00
#define BMASK	0x000000FF
#define AMASK	0x00000000

short		technical_effect_make_screenshot(const t_canvas *canvas)
{
	SDL_Surface				*surface;
	int						pitch;
	static unsigned long	counter;
	char					*screenshot_name;

	if (try_make_dir(SCREENSHOT_DIR) != 0)
		return (TECHNICAL_EFFECT_FAILURE);
	pitch = canvas->w * 4;
	surface = SDL_CreateRGBSurfaceFrom((void *)canvas->pixels,
				canvas->w, canvas->h, PIXEL_DEPTH, pitch,
				RMASK, GMASK, BMASK, 0);
	if (!surface)
		return (TECHNICAL_EFFECT_FAILURE);
	counter++;
	if (!(screenshot_name = get_screenshot_name(counter)))
	{
		SDL_FreeSurface(surface);
		return (TECHNICAL_EFFECT_FAILURE);
	}
	if (IMG_SavePNG(surface, screenshot_name) != 0)
		return (TECHNICAL_EFFECT_FAILURE);
	free(screenshot_name);
	SDL_FreeSurface(surface);
	return (TECHNICAL_EFFECT_SUCCESS);
}
