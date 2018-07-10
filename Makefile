# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 13:43:11 by amelihov          #+#    #+#              #
#    Updated: 2018/07/06 18:57:41 by amelihov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

CC     = gcc
LD     = $(CC)

SRC_DIR = ./srcs
OBJ_DIR = ./obj
INC_DIR = ./includes
LIB_DIR = ./lib

SRC = \
	camera.c\
	camera_move.c\
	camera_rotate.c\
	get_default_scenes.c\
	get_scene1.c\
	get_scene2.c\
	drawer.c\
	drawer_render.c\
	errors.c\
	event_handler_loop.c\
	apply_light.c\
	light.c\
	light_ptr_arr_delete.c\
	main.c\
	clampd.c\
	clampi.c\
	get_positive_root.c\
	square.c\
	object.c\
	object_ptr_arr_delete.c\
	object_ptr_arr_size.c\
	get_value_of_attr_with_name.c\
	is_correct_eol.c\
	is_only_whitespaces.c\
	parse_attr_of_type_double.c\
	parse_attr_of_type_vect3d.c\
	parse_camera.c\
	parse_cone.c\
	parse_cylinder.c\
	parse_double.c\
	parse_integer.c\
	parse_light.c\
	parse_lights.c\
	parse_object.c\
	parse_objects.c\
	parse_plane.c\
	parse_sphere.c\
	parse_vect3d.c\
	parser_parse_scene.c\
	skip_separator.c\
	str_with_digits_to_int.c\
	cone.c\
	cylinder.c\
	plane.c\
	sphere.c\
	find_closest_intersection.c\
	render_scene.c\
	trace_ray.c\
	get_scenes_from_file.c\
	scene.c\
	scene_ptr_arr_delete.c\
	scene_ptr_arr_size.c\
	vect3d.c\
	vect3d_clamp.c\
	vect3d_cos.c\
	vect3d_cos_normed.c\
	vect3d_cross.c\
	vect3d_div_on_scalar.c\
	vect3d_dot.c\
	vect3d_fill_rotate_matrix.c\
	vect3d_is_in_range.c\
	vect3d_is_in_range_abs.c\
	vect3d_len.c\
	vect3d_mult_on_matrix.c\
	vect3d_mult_on_scalar.c\
	vect3d_norm.c\
	vect3d_sq_len.c\

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
	
INC = \
	apply_light.h\
	camera.h\
	color.h\
	cone.h\
	cylinder.h\
	default_scenes.h\
	drawer.h\
	errors.h\
	errors_defines.h\
	event_handler_loop.h\
	intersection.h\
	light.h\
	light_ptr_arr.h\
	mmath.h\
	object.h\
	object_ptr_arr.h\
	parser.h\
	plane.h\
	primitive.h\
	raytracing.h\
	rtv1_defines.h\
	scene.h\
	scene_ptr_arr.h\
	sphere.h\
	userinput.h\
	vect3d.h\
	parser_private.h\

LIBFT = $(LIB_DIR)/libft/libft.a
LIBFT_INC = $(LIB_DIR)/libft/includes/
LIBFT_FLAGS = -lft -L $(LIB_DIR)/libft/

SDL_INC 	= ./lib/Frameworks/SDL2.framework/Headers/
SDL_FLAGS	= -F ./lib/Frameworks -framework SDL2 -rpath ./lib/Frameworks

CFLAGS = -Wall -Wextra -Werror -O3
HFLAGS = -I $(INC_DIR) -I $(LIBFT_INC) -I $(SDL_INC) 
LFLAGS = $(LIBFT_FLAGS) $(SDL_FLAGS) 

all:
	make -C $(LIB_DIR)/libft/
	make $(NAME)

$(NAME): $(OBJ) $(LIBFT) Makefile
	$(LD) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIB_DIR)/libft/

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf $(OBJ_DIR)
	make fclean -C $(LIB_DIR)/libft/

re: fclean all

vpath %.c $(SRC_DIR)
vpath %.c $(SRC_DIR)/camera
vpath %.c $(SRC_DIR)/default_scenes
vpath %.c $(SRC_DIR)/drawer
vpath %.c $(SRC_DIR)/events
vpath %.c $(SRC_DIR)/light
vpath %.c $(SRC_DIR)/mmath
vpath %.c $(SRC_DIR)/object
vpath %.c $(SRC_DIR)/parser
vpath %.c $(SRC_DIR)/primitives
vpath %.c $(SRC_DIR)/raytracing
vpath %.c $(SRC_DIR)/scene
vpath %.c $(SRC_DIR)/vect3d
vpath %.h $(INC_DIR)
vpath %.h $(SRC_DIR)/parser

.PHONY: all clean fclean re
