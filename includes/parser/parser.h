/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 18:57:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/08/17 21:30:29 by amelihov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#define PARSER_SUCCESS 0
#define PARSER_FAIL 1

typedef struct s_scene	t_scene;

int		scene_init_from_file(char *file_path, t_scene *scene);

#endif
