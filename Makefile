# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 13:43:11 by amelihov          #+#    #+#              #
#    Updated: 2018/09/08 22:32:00 by amelihov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE_NAME = Makefile

NAME = RT

CC     = gcc
LD     = $(CC)
DEPEND = makedepend

SRC_DIR = ./srcs
OBJ_DIR = ./obj
INC_DIR = ./includes
LIB_DIR = ./external/libs
FRM_DIR = ./external/Frameworks
LINK_DIR = ./external/link

SRC_FULL_PATH =\
	srcs/basis/basis_get_coord_in_basis.c\
	srcs/basis/basis_rotate.c\
	srcs/camera/camera_move.c\
	srcs/camera/camera_rotate.c\
	srcs/canvas/canvas_fill_rect.c\
	srcs/canvas/canvas_strip_if_not_fit.c\
	srcs/drawer/drawer.c\
	srcs/drawer/drawer_render_on_window.c\
	srcs/err/err.c\
	srcs/event/event_handler_loop.c\
	srcs/event/handle_cameara_actions.c\
	srcs/event/handle_key_down.c\
	srcs/event/handle_mouse_down.c\
	srcs/event/handle_object_actions.c\
	srcs/event/handle_render_options.c\
	srcs/event/handle_technical_effects.c\
	srcs/filter/filter_apply_black_and_white.c\
	srcs/filter/filter_apply_filters.c\
	srcs/filter/filter_apply_sepia.c\
	srcs/light/calc_col.c\
	srcs/light/directional_light_apply.c\
	srcs/light/light_apply_light_by_type.c\
	srcs/light/point_light_apply.c\
	srcs/light/spotlight_light_apply.c\
	srcs/main.c\
	srcs/mmath/cb.c\
	srcs/mmath/clampd.c\
	srcs/mmath/clampi.c\
	srcs/mmath/get_positive_root.c\
	srcs/mmath/sign.c\
	srcs/mmath/solve2.c\
	srcs/mmath/solve3.c\
	srcs/mmath/solve4.c\
	srcs/mmath/square.c\
	srcs/object/object.c\
	srcs/object/object_get_color_from_texture.c\
	srcs/object/object_update_material_according_to_tex.c\
	srcs/options/options_init.c\
	srcs/options/options_is_filters_on.c\
	srcs/parser/angles_to_basis.c\
	srcs/parser/create_lights.c\
	srcs/parser/create_objects.c\
	srcs/parser/init_camera.c\
	srcs/parser/parser.c\
	srcs/parser/parser_put_error.c\
	srcs/parser/parser_put_error_mapping.c\
	srcs/parser/validate_ads.c\
	srcs/parser/validate_direction.c\
	srcs/parser/validate_figures_1.c\
	srcs/parser/validate_figures_2.c\
	srcs/parser/validate_light_type.c\
	srcs/parser/validate_light_type_num.c\
	srcs/parser/validate_lights.c\
	srcs/parser/validate_obj_material.c\
	srcs/parser/validate_obj_type.c\
	srcs/parser/validate_obj_type_num.c\
	srcs/parser/validate_objects.c\
	srcs/parser/validate_parsed_values.c\
	srcs/parser/validate_value_float.c\
	srcs/parser/vect3d_from_float.c\
	srcs/primitive/cone.c\
	srcs/primitive/cone_create.c\
	srcs/primitive/cuboid.c\
	srcs/primitive/cuboid_create.c\
	srcs/primitive/cylinder.c\
	srcs/primitive/disk.c\
	srcs/primitive/paraboloid.c\
	srcs/primitive/paraboloid_create.c\
	srcs/primitive/plane.c\
	srcs/primitive/rect.c\
	srcs/primitive/sort_and_left_positive_roots.c\
	srcs/primitive/sphere.c\
	srcs/primitive/torus.c\
	srcs/raytracing/apply_light.c\
	srcs/raytracing/find_closest_intersection.c\
	srcs/raytracing/fresnel.c\
	srcs/raytracing/get_ray_dir.c\
	srcs/raytracing/get_refraction_ray.c\
	srcs/raytracing/handle_reflection_and_refraction.c\
	srcs/raytracing/raytracing_get_obj_idx_on_coord.c\
	srcs/raytracing/raytracing_get_obj_on_dir.c\
	srcs/raytracing/raytracing_trace.c\
	srcs/raytracing/raytracing_trace_with_antialiasing.c\
	srcs/raytracing/trace_ray.c\
	srcs/render/render_on_canvas.c\
	srcs/render/render_on_canvas_parallel.c\
	srcs/render/render_on_canvas_single.c\
	srcs/render/render_on_canvas_with_stereoscopy.c\
	srcs/scene/scene.c\
	srcs/technical_effect/technical_effect_make_screenshot.c\
	srcs/texture/texture_load.c\
	srcs/vect3d/vect3d.c\
	srcs/vect3d/vect3d_clamp.c\
	srcs/vect3d/vect3d_cos.c\
	srcs/vect3d/vect3d_cos_normed.c\
	srcs/vect3d/vect3d_cross.c\
	srcs/vect3d/vect3d_div_on_scalar.c\
	srcs/vect3d/vect3d_dot.c\
	srcs/vect3d/vect3d_fill_rotate_matrix.c\
	srcs/vect3d/vect3d_from_scalar.c\
	srcs/vect3d/vect3d_fst_closer_snd_to.c\
	srcs/vect3d/vect3d_inf.c\
	srcs/vect3d/vect3d_is_equal.c\
	srcs/vect3d/vect3d_is_in_range.c\
	srcs/vect3d/vect3d_is_in_range_abs.c\
	srcs/vect3d/vect3d_len.c\
	srcs/vect3d/vect3d_mult_on_matrix.c\
	srcs/vect3d/vect3d_mult_on_scalar.c\
	srcs/vect3d/vect3d_norm.c\
	srcs/vect3d/vect3d_reflect.c\
	srcs/vect3d/vect3d_rotate_around_axis.c\
	srcs/vect3d/vect3d_sq_len.c

SRC =\
	basis_get_coord_in_basis.c\
	basis_rotate.c\
	camera_move.c\
	camera_rotate.c\
	canvas_fill_rect.c\
	canvas_strip_if_not_fit.c\
	drawer.c\
	drawer_render_on_window.c\
	err.c\
	event_handler_loop.c\
	handle_cameara_actions.c\
	handle_key_down.c\
	handle_mouse_down.c\
	handle_object_actions.c\
	handle_render_options.c\
	handle_technical_effects.c\
	filter_apply_black_and_white.c\
	filter_apply_filters.c\
	filter_apply_sepia.c\
	calc_col.c\
	directional_light_apply.c\
	light_apply_light_by_type.c\
	point_light_apply.c\
	spotlight_light_apply.c\
	main.c\
	cb.c\
	clampd.c\
	clampi.c\
	get_positive_root.c\
	sign.c\
	solve2.c\
	solve3.c\
	solve4.c\
	square.c\
	object.c\
	object_get_color_from_texture.c\
	object_update_material_according_to_tex.c\
	options_init.c\
	options_is_filters_on.c\
	angles_to_basis.c\
	create_lights.c\
	create_objects.c\
	init_camera.c\
	parser.c\
	parser_put_error.c\
	parser_put_error_mapping.c\
	validate_ads.c\
	validate_direction.c\
	validate_figures_1.c\
	validate_figures_2.c\
	validate_light_type.c\
	validate_light_type_num.c\
	validate_lights.c\
	validate_obj_material.c\
	validate_obj_type.c\
	validate_obj_type_num.c\
	validate_objects.c\
	validate_parsed_values.c\
	validate_value_float.c\
	vect3d_from_float.c\
	cone.c\
	cone_create.c\
	cuboid.c\
	cuboid_create.c\
	cylinder.c\
	disk.c\
	paraboloid.c\
	paraboloid_create.c\
	plane.c\
	rect.c\
	sort_and_left_positive_roots.c\
	sphere.c\
	torus.c\
	apply_light.c\
	find_closest_intersection.c\
	fresnel.c\
	get_ray_dir.c\
	get_refraction_ray.c\
	handle_reflection_and_refraction.c\
	raytracing_get_obj_idx_on_coord.c\
	raytracing_get_obj_on_dir.c\
	raytracing_trace.c\
	raytracing_trace_with_antialiasing.c\
	trace_ray.c\
	render_on_canvas.c\
	render_on_canvas_parallel.c\
	render_on_canvas_single.c\
	render_on_canvas_with_stereoscopy.c\
	scene.c\
	technical_effect_make_screenshot.c\
	texture_load.c\
	vect3d.c\
	vect3d_clamp.c\
	vect3d_cos.c\
	vect3d_cos_normed.c\
	vect3d_cross.c\
	vect3d_div_on_scalar.c\
	vect3d_dot.c\
	vect3d_fill_rotate_matrix.c\
	vect3d_from_scalar.c\
	vect3d_fst_closer_snd_to.c\
	vect3d_inf.c\
	vect3d_is_equal.c\
	vect3d_is_in_range.c\
	vect3d_is_in_range_abs.c\
	vect3d_len.c\
	vect3d_mult_on_matrix.c\
	vect3d_mult_on_scalar.c\
	vect3d_norm.c\
	vect3d_reflect.c\
	vect3d_rotate_around_axis.c\
	vect3d_sq_len.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC_DIRS =\
	-Iincludes/array_light\
	-Iincludes/array_object\
	-Iincludes/basis\
	-Iincludes/camera\
	-Iincludes/canvas\
	-Iincludes/color\
	-Iincludes/defines\
	-Iincludes/drawer\
	-Iincludes/err\
	-Iincludes/event\
	-Iincludes/filter\
	-Iincludes/light\
	-Iincludes/material\
	-Iincludes/mmath\
	-Iincludes/object\
	-Iincludes/options\
	-Iincludes/parser\
	-Iincludes/primitive\
	-Iincludes/raytracing\
	-Iincludes/render\
	-Iincludes/scene\
	-Iincludes/shape\
	-Iincludes/technical_effect\
	-Iincludes/texture\
	-Iincludes/vect3d\
	-Isrcs/event\
	-Isrcs/light\
	-Isrcs/parser\
	-Isrcs/primitive\
	-Isrcs/raytracing\
	-Isrcs/render

LIBFT 			= $(LINK_DIR)/libft/libft_exec
LIBFT_INC 		= $(LINK_DIR)/libft/libft_includes
LIBFT_FLAGS 	= $(LINK_DIR)/libft/libft_exec
LIBFT_MK 		= Makefile
LIBFT_MK_DIR	= $(LIB_DIR)/libft

LIBCYAML 		= $(LINK_DIR)/libcyaml/libcyaml_exec
LIBCYAML_INC	= $(LINK_DIR)/libcyaml/libcyaml_includes
LIBCYAML_FLAGS	= $(LINK_DIR)/libcyaml/libcyaml_exec\
			  	 $(LINK_DIR)/libcyaml/libyaml_exec
LIBCYAML_MK 	= make_with_yaml_lib.mk
LIBCYAML_MK_DIR = $(LIB_DIR)/libcyaml

SDL2_INC 	= $(LINK_DIR)/sdl2/sdl2_includes
SDL2_FLAGS	= -F $(FRM_DIR) -framework SDL2 -rpath $(FRM_DIR)

SDL2_IMG_INC 	= $(LINK_DIR)/sdl2_image/sdl2_image_includes\
				  $(LINK_DIR)/sdl2_image
SDL2_IMG_FLAGS	= -F $(FRM_DIR) -framework SDL2_image -rpath $(FRM_DIR)

CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = $(INC_DIRS) -I $(LIBFT_INC) -I $(LIBCYAML_INC) -I $(SDL2_INC)\
		$(foreach inc, $(SDL2_IMG_INC), $(addprefix -I, $(inc)))
LFLAGS = $(LIBFT_FLAGS) $(LIBCYAML_FLAGS) $(SDL2_FLAGS) $(SDL2_IMG_FLAGS)

all:
	@echo "*** compiling libs ***"
	@make -f $(LIBFT_MK) -C $(LIBFT_MK_DIR)
	@make -f $(LIBCYAML_MK) -C $(LIBCYAML_MK_DIR)
	@echo "*** start making the main target: "$(NAME)" ***"
	@make $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBCYAML)
	@echo "*** linking main target: "$(NAME)" ***"
	@$(LD) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@echo "compiling object: "$@""
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@echo "*** removing objects ***"
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@echo "*** removing main target: "$(NAME)" ***"
	@$(RM) -r $(OBJ_DIR)
	@echo "*** cleaning libs ***"
	@make clean -f $(LIBFT_MK) -C $(LIBFT_MK_DIR)
	@make clean -f $(LIBCYAML_MK) -C $(LIBCYAML_MK_DIR)

re: fclean all

depend:
	@touch __tmp_makedepend_out__
	@$(DEPEND) -f __tmp_makedepend_out__ -- $(IFLAGS) -- $(SRC_FULL_PATH)
	@sed -i '' 's!\(.*\/\)*\(.*:\)!$(OBJ_DIR)/\2!g' __tmp_makedepend_out__
	@sed '/^# DO NOT DELETE/q' $(MAKE_NAME) > __tmp_makefile__
	@cat __tmp_makefile__ > $(MAKE_NAME)
	@rm __tmp_makefile__
	@cat __tmp_makedepend_out__ >> $(MAKE_NAME)
	@rm __tmp_makedepend_out__
	@rm __tmp_makedepend_out__.bak
	@echo "*** make depend ***"

vpath %.c $(SRC_DIR)
vpath %.c $(SRC_DIR)/basis
vpath %.c $(SRC_DIR)/camera
vpath %.c $(SRC_DIR)/canvas
vpath %.c $(SRC_DIR)/drawer
vpath %.c $(SRC_DIR)/err
vpath %.c $(SRC_DIR)/event
vpath %.c $(SRC_DIR)/filter
vpath %.c $(SRC_DIR)/light
vpath %.c $(SRC_DIR)/mmath
vpath %.c $(SRC_DIR)/object
vpath %.c $(SRC_DIR)/options
vpath %.c $(SRC_DIR)/parser
vpath %.c $(SRC_DIR)/primitive
vpath %.c $(SRC_DIR)/raytracing
vpath %.c $(SRC_DIR)/render
vpath %.c $(SRC_DIR)/scene
vpath %.c $(SRC_DIR)/technical_effect
vpath %.c $(SRC_DIR)/texture
vpath %.c $(SRC_DIR)/vect3d

.PHONY: all clean fclean re
# DO NOT DELETE
# DO NOT DELETE

./obj/basis_get_coord_in_basis.o: includes/basis/basis.h
./obj/basis_get_coord_in_basis.o: includes/vect3d/vect3d.h
./obj/basis_rotate.o: includes/basis/basis.h includes/vect3d/vect3d.h
./obj/camera_move.o: includes/camera/camera.h includes/vect3d/vect3d.h
./obj/camera_move.o: includes/basis/basis.h
./obj/camera_rotate.o: includes/camera/camera.h
./obj/camera_rotate.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/canvas_fill_rect.o: includes/canvas/canvas.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/canvas_fill_rect.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/canvas_strip_if_not_fit.o: includes/canvas/canvas.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/canvas_strip_if_not_fit.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/drawer.o: includes/drawer/drawer.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/drawer.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/drawer.o: includes/canvas/canvas.h includes/err/err.h
./obj/drawer.o: includes/defines/err_defines.h
./obj/drawer.o: ./external/link/libft/libft_includes/libft.h
./obj/drawer.o: ./external/link/libft/libft_includes/get_next_line.h
./obj/drawer_render_on_window.o: includes/drawer/drawer.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/drawer_render_on_window.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/drawer_render_on_window.o: includes/canvas/canvas.h
./obj/err.o: includes/err/err.h includes/defines/err_defines.h
./obj/event_handler_loop.o: srcs/event/event_private.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/event_handler_loop.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/event_handler_loop.o: includes/drawer/drawer.h
./obj/event_handler_loop.o: includes/canvas/canvas.h
./obj/event_handler_loop.o: includes/scene/scene.h
./obj/event_handler_loop.o: includes/camera/camera.h
./obj/event_handler_loop.o: includes/vect3d/vect3d.h
./obj/event_handler_loop.o: includes/basis/basis.h
./obj/event_handler_loop.o: includes/array_object/array_object.h
./obj/event_handler_loop.o: includes/object/object.h
./obj/event_handler_loop.o: includes/shape/shape.h
./obj/event_handler_loop.o: includes/primitive/primitive.h
./obj/event_handler_loop.o: includes/primitive/sphere.h
./obj/event_handler_loop.o: includes/raytracing/ray.h
./obj/event_handler_loop.o: includes/primitive/cylinder.h
./obj/event_handler_loop.o: includes/primitive/cone.h
./obj/event_handler_loop.o: includes/primitive/plane.h
./obj/event_handler_loop.o: includes/primitive/torus.h
./obj/event_handler_loop.o: includes/primitive/paraboloid.h
./obj/event_handler_loop.o: includes/primitive/rect.h
./obj/event_handler_loop.o: includes/primitive/disk.h
./obj/event_handler_loop.o: includes/primitive/cuboid.h
./obj/event_handler_loop.o: includes/material/material.h
./obj/event_handler_loop.o: includes/texture/texture.h
./obj/event_handler_loop.o: includes/array_light/array_light.h
./obj/event_handler_loop.o: includes/light/light.h
./obj/event_handler_loop.o: includes/light/point_light.h
./obj/event_handler_loop.o: includes/light/directional_light.h
./obj/event_handler_loop.o: includes/light/spotlight_light.h
./obj/event_handler_loop.o: includes/options/options.h
./obj/event_handler_loop.o: includes/render/render.h
./obj/handle_cameara_actions.o: srcs/event/event_private.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/handle_cameara_actions.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/handle_cameara_actions.o: includes/defines/key_defines.h
./obj/handle_cameara_actions.o: includes/defines/options_manipulations_defines.h
./obj/handle_cameara_actions.o: includes/scene/scene.h
./obj/handle_cameara_actions.o: includes/camera/camera.h
./obj/handle_cameara_actions.o: includes/vect3d/vect3d.h
./obj/handle_cameara_actions.o: includes/basis/basis.h
./obj/handle_cameara_actions.o: includes/array_object/array_object.h
./obj/handle_cameara_actions.o: includes/object/object.h
./obj/handle_cameara_actions.o: includes/shape/shape.h
./obj/handle_cameara_actions.o: includes/primitive/primitive.h
./obj/handle_cameara_actions.o: includes/primitive/sphere.h
./obj/handle_cameara_actions.o: includes/raytracing/ray.h
./obj/handle_cameara_actions.o: includes/primitive/cylinder.h
./obj/handle_cameara_actions.o: includes/primitive/cone.h
./obj/handle_cameara_actions.o: includes/primitive/plane.h
./obj/handle_cameara_actions.o: includes/primitive/torus.h
./obj/handle_cameara_actions.o: includes/primitive/paraboloid.h
./obj/handle_cameara_actions.o: includes/primitive/rect.h
./obj/handle_cameara_actions.o: includes/primitive/disk.h
./obj/handle_cameara_actions.o: includes/primitive/cuboid.h
./obj/handle_cameara_actions.o: includes/material/material.h
./obj/handle_cameara_actions.o: includes/texture/texture.h
./obj/handle_cameara_actions.o: includes/array_light/array_light.h
./obj/handle_cameara_actions.o: includes/light/light.h
./obj/handle_cameara_actions.o: includes/light/point_light.h
./obj/handle_cameara_actions.o: includes/light/directional_light.h
./obj/handle_cameara_actions.o: includes/light/spotlight_light.h
./obj/handle_cameara_actions.o: includes/options/options.h
./obj/handle_key_down.o: includes/event/event.h
./obj/handle_key_down.o: srcs/event/event_private.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/handle_key_down.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/handle_key_down.o: includes/defines/key_defines.h
./obj/handle_key_down.o: includes/scene/scene.h includes/camera/camera.h
./obj/handle_key_down.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/handle_key_down.o: includes/array_object/array_object.h
./obj/handle_key_down.o: includes/object/object.h includes/shape/shape.h
./obj/handle_key_down.o: includes/primitive/primitive.h
./obj/handle_key_down.o: includes/primitive/sphere.h
./obj/handle_key_down.o: includes/raytracing/ray.h
./obj/handle_key_down.o: includes/primitive/cylinder.h
./obj/handle_key_down.o: includes/primitive/cone.h
./obj/handle_key_down.o: includes/primitive/plane.h
./obj/handle_key_down.o: includes/primitive/torus.h
./obj/handle_key_down.o: includes/primitive/paraboloid.h
./obj/handle_key_down.o: includes/primitive/rect.h
./obj/handle_key_down.o: includes/primitive/disk.h
./obj/handle_key_down.o: includes/primitive/cuboid.h
./obj/handle_key_down.o: includes/material/material.h
./obj/handle_key_down.o: includes/texture/texture.h
./obj/handle_key_down.o: includes/array_light/array_light.h
./obj/handle_key_down.o: includes/light/light.h
./obj/handle_key_down.o: includes/light/point_light.h
./obj/handle_key_down.o: includes/light/directional_light.h
./obj/handle_key_down.o: includes/light/spotlight_light.h
./obj/handle_key_down.o: includes/options/options.h
./obj/handle_mouse_down.o: srcs/event/event_private.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/handle_mouse_down.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/handle_mouse_down.o: includes/options/options.h
./obj/handle_mouse_down.o: includes/scene/scene.h
./obj/handle_mouse_down.o: includes/camera/camera.h
./obj/handle_mouse_down.o: includes/vect3d/vect3d.h
./obj/handle_mouse_down.o: includes/basis/basis.h
./obj/handle_mouse_down.o: includes/array_object/array_object.h
./obj/handle_mouse_down.o: includes/object/object.h
./obj/handle_mouse_down.o: includes/shape/shape.h
./obj/handle_mouse_down.o: includes/primitive/primitive.h
./obj/handle_mouse_down.o: includes/primitive/sphere.h
./obj/handle_mouse_down.o: includes/raytracing/ray.h
./obj/handle_mouse_down.o: includes/primitive/cylinder.h
./obj/handle_mouse_down.o: includes/primitive/cone.h
./obj/handle_mouse_down.o: includes/primitive/plane.h
./obj/handle_mouse_down.o: includes/primitive/torus.h
./obj/handle_mouse_down.o: includes/primitive/paraboloid.h
./obj/handle_mouse_down.o: includes/primitive/rect.h
./obj/handle_mouse_down.o: includes/primitive/disk.h
./obj/handle_mouse_down.o: includes/primitive/cuboid.h
./obj/handle_mouse_down.o: includes/material/material.h
./obj/handle_mouse_down.o: includes/texture/texture.h
./obj/handle_mouse_down.o: includes/array_light/array_light.h
./obj/handle_mouse_down.o: includes/light/light.h
./obj/handle_mouse_down.o: includes/light/point_light.h
./obj/handle_mouse_down.o: includes/light/directional_light.h
./obj/handle_mouse_down.o: includes/light/spotlight_light.h
./obj/handle_mouse_down.o: includes/canvas/canvas.h
./obj/handle_mouse_down.o: includes/raytracing/raytracing.h
./obj/handle_object_actions.o: srcs/event/event_private.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/handle_object_actions.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/handle_object_actions.o: includes/defines/key_defines.h
./obj/handle_object_actions.o: includes/defines/options_manipulations_defines.h
./obj/handle_object_actions.o: includes/scene/scene.h
./obj/handle_object_actions.o: includes/camera/camera.h
./obj/handle_object_actions.o: includes/vect3d/vect3d.h
./obj/handle_object_actions.o: includes/basis/basis.h
./obj/handle_object_actions.o: includes/array_object/array_object.h
./obj/handle_object_actions.o: includes/object/object.h
./obj/handle_object_actions.o: includes/shape/shape.h
./obj/handle_object_actions.o: includes/primitive/primitive.h
./obj/handle_object_actions.o: includes/primitive/sphere.h
./obj/handle_object_actions.o: includes/raytracing/ray.h
./obj/handle_object_actions.o: includes/primitive/cylinder.h
./obj/handle_object_actions.o: includes/primitive/cone.h
./obj/handle_object_actions.o: includes/primitive/plane.h
./obj/handle_object_actions.o: includes/primitive/torus.h
./obj/handle_object_actions.o: includes/primitive/paraboloid.h
./obj/handle_object_actions.o: includes/primitive/rect.h
./obj/handle_object_actions.o: includes/primitive/disk.h
./obj/handle_object_actions.o: includes/primitive/cuboid.h
./obj/handle_object_actions.o: includes/material/material.h
./obj/handle_object_actions.o: includes/texture/texture.h
./obj/handle_object_actions.o: includes/array_light/array_light.h
./obj/handle_object_actions.o: includes/light/light.h
./obj/handle_object_actions.o: includes/light/point_light.h
./obj/handle_object_actions.o: includes/light/directional_light.h
./obj/handle_object_actions.o: includes/light/spotlight_light.h
./obj/handle_object_actions.o: includes/options/options.h
./obj/handle_object_actions.o: includes/mmath/mmath.h
./obj/handle_render_options.o: srcs/event/event_private.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/handle_render_options.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/handle_render_options.o: includes/defines/key_defines.h
./obj/handle_render_options.o: includes/defines/options_manipulations_defines.h
./obj/handle_render_options.o: includes/scene/scene.h
./obj/handle_render_options.o: includes/camera/camera.h
./obj/handle_render_options.o: includes/vect3d/vect3d.h
./obj/handle_render_options.o: includes/basis/basis.h
./obj/handle_render_options.o: includes/array_object/array_object.h
./obj/handle_render_options.o: includes/object/object.h
./obj/handle_render_options.o: includes/shape/shape.h
./obj/handle_render_options.o: includes/primitive/primitive.h
./obj/handle_render_options.o: includes/primitive/sphere.h
./obj/handle_render_options.o: includes/raytracing/ray.h
./obj/handle_render_options.o: includes/primitive/cylinder.h
./obj/handle_render_options.o: includes/primitive/cone.h
./obj/handle_render_options.o: includes/primitive/plane.h
./obj/handle_render_options.o: includes/primitive/torus.h
./obj/handle_render_options.o: includes/primitive/paraboloid.h
./obj/handle_render_options.o: includes/primitive/rect.h
./obj/handle_render_options.o: includes/primitive/disk.h
./obj/handle_render_options.o: includes/primitive/cuboid.h
./obj/handle_render_options.o: includes/material/material.h
./obj/handle_render_options.o: includes/texture/texture.h
./obj/handle_render_options.o: includes/array_light/array_light.h
./obj/handle_render_options.o: includes/light/light.h
./obj/handle_render_options.o: includes/light/point_light.h
./obj/handle_render_options.o: includes/light/directional_light.h
./obj/handle_render_options.o: includes/light/spotlight_light.h
./obj/handle_render_options.o: includes/options/options.h
./obj/handle_render_options.o: includes/mmath/mmath.h
./obj/handle_technical_effects.o: srcs/event/event_private.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/handle_technical_effects.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/handle_technical_effects.o: includes/defines/key_defines.h
./obj/handle_technical_effects.o: includes/options/options.h
./obj/handle_technical_effects.o: includes/scene/scene.h
./obj/handle_technical_effects.o: includes/camera/camera.h
./obj/handle_technical_effects.o: includes/vect3d/vect3d.h
./obj/handle_technical_effects.o: includes/basis/basis.h
./obj/handle_technical_effects.o: includes/array_object/array_object.h
./obj/handle_technical_effects.o: includes/object/object.h
./obj/handle_technical_effects.o: includes/shape/shape.h
./obj/handle_technical_effects.o: includes/primitive/primitive.h
./obj/handle_technical_effects.o: includes/primitive/sphere.h
./obj/handle_technical_effects.o: includes/raytracing/ray.h
./obj/handle_technical_effects.o: includes/primitive/cylinder.h
./obj/handle_technical_effects.o: includes/primitive/cone.h
./obj/handle_technical_effects.o: includes/primitive/plane.h
./obj/handle_technical_effects.o: includes/primitive/torus.h
./obj/handle_technical_effects.o: includes/primitive/paraboloid.h
./obj/handle_technical_effects.o: includes/primitive/rect.h
./obj/handle_technical_effects.o: includes/primitive/disk.h
./obj/handle_technical_effects.o: includes/primitive/cuboid.h
./obj/handle_technical_effects.o: includes/material/material.h
./obj/handle_technical_effects.o: includes/texture/texture.h
./obj/handle_technical_effects.o: includes/array_light/array_light.h
./obj/handle_technical_effects.o: includes/light/light.h
./obj/handle_technical_effects.o: includes/light/point_light.h
./obj/handle_technical_effects.o: includes/light/directional_light.h
./obj/handle_technical_effects.o: includes/light/spotlight_light.h
./obj/handle_technical_effects.o: includes/canvas/canvas.h
./obj/handle_technical_effects.o: includes/technical_effect/technical_effect.h
./obj/filter_apply_black_and_white.o: includes/filter/filter.h
./obj/filter_apply_black_and_white.o: includes/vect3d/vect3d.h
./obj/filter_apply_filters.o: includes/filter/filter.h
./obj/filter_apply_filters.o: includes/vect3d/vect3d.h
./obj/filter_apply_filters.o: includes/options/options.h
./obj/filter_apply_sepia.o: includes/filter/filter.h
./obj/filter_apply_sepia.o: includes/vect3d/vect3d.h
./obj/calc_col.o: srcs/light/light_private.h includes/vect3d/vect3d.h
./obj/calc_col.o: includes/raytracing/intersection.h
./obj/calc_col.o: includes/object/object.h includes/basis/basis.h
./obj/calc_col.o: includes/shape/shape.h includes/primitive/primitive.h
./obj/calc_col.o: includes/primitive/sphere.h includes/raytracing/ray.h
./obj/calc_col.o: includes/primitive/cylinder.h
./obj/calc_col.o: includes/primitive/cone.h includes/primitive/plane.h
./obj/calc_col.o: includes/primitive/torus.h
./obj/calc_col.o: includes/primitive/paraboloid.h
./obj/calc_col.o: includes/primitive/rect.h includes/primitive/disk.h
./obj/calc_col.o: includes/primitive/cuboid.h
./obj/calc_col.o: includes/material/material.h
./obj/calc_col.o: includes/texture/texture.h
./obj/directional_light_apply.o: includes/light/directional_light.h
./obj/directional_light_apply.o: includes/vect3d/vect3d.h
./obj/directional_light_apply.o: srcs/light/light_private.h
./obj/directional_light_apply.o: includes/raytracing/raytracing.h
./obj/directional_light_apply.o: includes/raytracing/intersection.h
./obj/directional_light_apply.o: includes/object/object.h
./obj/directional_light_apply.o: includes/basis/basis.h
./obj/directional_light_apply.o: includes/shape/shape.h
./obj/directional_light_apply.o: includes/primitive/primitive.h
./obj/directional_light_apply.o: includes/primitive/sphere.h
./obj/directional_light_apply.o: includes/raytracing/ray.h
./obj/directional_light_apply.o: includes/primitive/cylinder.h
./obj/directional_light_apply.o: includes/primitive/cone.h
./obj/directional_light_apply.o: includes/primitive/plane.h
./obj/directional_light_apply.o: includes/primitive/torus.h
./obj/directional_light_apply.o: includes/primitive/paraboloid.h
./obj/directional_light_apply.o: includes/primitive/rect.h
./obj/directional_light_apply.o: includes/primitive/disk.h
./obj/directional_light_apply.o: includes/primitive/cuboid.h
./obj/directional_light_apply.o: includes/material/material.h
./obj/directional_light_apply.o: includes/texture/texture.h
./obj/light_apply_light_by_type.o: includes/light/light.h
./obj/light_apply_light_by_type.o: includes/light/point_light.h
./obj/light_apply_light_by_type.o: includes/vect3d/vect3d.h
./obj/light_apply_light_by_type.o: includes/light/directional_light.h
./obj/light_apply_light_by_type.o: includes/light/spotlight_light.h
./obj/light_apply_light_by_type.o: includes/scene/scene.h
./obj/light_apply_light_by_type.o: includes/camera/camera.h
./obj/light_apply_light_by_type.o: includes/basis/basis.h
./obj/light_apply_light_by_type.o: includes/array_object/array_object.h
./obj/light_apply_light_by_type.o: includes/object/object.h
./obj/light_apply_light_by_type.o: includes/shape/shape.h
./obj/light_apply_light_by_type.o: includes/primitive/primitive.h
./obj/light_apply_light_by_type.o: includes/primitive/sphere.h
./obj/light_apply_light_by_type.o: includes/raytracing/ray.h
./obj/light_apply_light_by_type.o: includes/primitive/cylinder.h
./obj/light_apply_light_by_type.o: includes/primitive/cone.h
./obj/light_apply_light_by_type.o: includes/primitive/plane.h
./obj/light_apply_light_by_type.o: includes/primitive/torus.h
./obj/light_apply_light_by_type.o: includes/primitive/paraboloid.h
./obj/light_apply_light_by_type.o: includes/primitive/rect.h
./obj/light_apply_light_by_type.o: includes/primitive/disk.h
./obj/light_apply_light_by_type.o: includes/primitive/cuboid.h
./obj/light_apply_light_by_type.o: includes/material/material.h
./obj/light_apply_light_by_type.o: includes/texture/texture.h
./obj/light_apply_light_by_type.o: includes/array_light/array_light.h
./obj/light_apply_light_by_type.o: includes/raytracing/intersection.h
./obj/point_light_apply.o: includes/light/point_light.h
./obj/point_light_apply.o: includes/vect3d/vect3d.h
./obj/point_light_apply.o: srcs/light/light_private.h
./obj/point_light_apply.o: includes/raytracing/raytracing.h
./obj/point_light_apply.o: includes/raytracing/intersection.h
./obj/point_light_apply.o: includes/object/object.h
./obj/point_light_apply.o: includes/basis/basis.h includes/shape/shape.h
./obj/point_light_apply.o: includes/primitive/primitive.h
./obj/point_light_apply.o: includes/primitive/sphere.h
./obj/point_light_apply.o: includes/raytracing/ray.h
./obj/point_light_apply.o: includes/primitive/cylinder.h
./obj/point_light_apply.o: includes/primitive/cone.h
./obj/point_light_apply.o: includes/primitive/plane.h
./obj/point_light_apply.o: includes/primitive/torus.h
./obj/point_light_apply.o: includes/primitive/paraboloid.h
./obj/point_light_apply.o: includes/primitive/rect.h
./obj/point_light_apply.o: includes/primitive/disk.h
./obj/point_light_apply.o: includes/primitive/cuboid.h
./obj/point_light_apply.o: includes/material/material.h
./obj/point_light_apply.o: includes/texture/texture.h
./obj/spotlight_light_apply.o: includes/light/spotlight_light.h
./obj/spotlight_light_apply.o: includes/vect3d/vect3d.h
./obj/spotlight_light_apply.o: srcs/light/light_private.h
./obj/spotlight_light_apply.o: includes/raytracing/raytracing.h
./obj/spotlight_light_apply.o: includes/raytracing/intersection.h
./obj/spotlight_light_apply.o: includes/object/object.h
./obj/spotlight_light_apply.o: includes/basis/basis.h
./obj/spotlight_light_apply.o: includes/shape/shape.h
./obj/spotlight_light_apply.o: includes/primitive/primitive.h
./obj/spotlight_light_apply.o: includes/primitive/sphere.h
./obj/spotlight_light_apply.o: includes/raytracing/ray.h
./obj/spotlight_light_apply.o: includes/primitive/cylinder.h
./obj/spotlight_light_apply.o: includes/primitive/cone.h
./obj/spotlight_light_apply.o: includes/primitive/plane.h
./obj/spotlight_light_apply.o: includes/primitive/torus.h
./obj/spotlight_light_apply.o: includes/primitive/paraboloid.h
./obj/spotlight_light_apply.o: includes/primitive/rect.h
./obj/spotlight_light_apply.o: includes/primitive/disk.h
./obj/spotlight_light_apply.o: includes/primitive/cuboid.h
./obj/spotlight_light_apply.o: includes/material/material.h
./obj/spotlight_light_apply.o: includes/texture/texture.h
./obj/spotlight_light_apply.o: includes/mmath/mmath.h
./obj/main.o: includes/drawer/drawer.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/main.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/main.o: includes/canvas/canvas.h includes/scene/scene.h
./obj/main.o: includes/camera/camera.h includes/vect3d/vect3d.h
./obj/main.o: includes/basis/basis.h includes/array_object/array_object.h
./obj/main.o: includes/object/object.h includes/shape/shape.h
./obj/main.o: includes/primitive/primitive.h includes/primitive/sphere.h
./obj/main.o: includes/raytracing/ray.h includes/primitive/cylinder.h
./obj/main.o: includes/primitive/cone.h includes/primitive/plane.h
./obj/main.o: includes/primitive/torus.h includes/primitive/paraboloid.h
./obj/main.o: includes/primitive/rect.h includes/primitive/disk.h
./obj/main.o: includes/primitive/cuboid.h includes/material/material.h
./obj/main.o: includes/texture/texture.h includes/array_light/array_light.h
./obj/main.o: includes/light/light.h includes/light/point_light.h
./obj/main.o: includes/light/directional_light.h
./obj/main.o: includes/light/spotlight_light.h includes/event/event.h
./obj/main.o: includes/err/err.h includes/defines/err_defines.h
./obj/main.o: ./external/link/libft/libft_includes/libft.h
./obj/main.o: ./external/link/libft/libft_includes/get_next_line.h
./obj/main.o: includes/parser/parser.h includes/defines/rt_defines.h
./obj/cb.o: includes/mmath/mmath.h
./obj/sign.o: includes/mmath/mmath.h
./obj/solve2.o: includes/mmath/mmath.h
./obj/solve3.o: includes/mmath/mmath.h
./obj/solve4.o: includes/mmath/mmath.h
./obj/object.o: includes/object/object.h includes/vect3d/vect3d.h
./obj/object.o: includes/basis/basis.h includes/shape/shape.h
./obj/object.o: includes/primitive/primitive.h
./obj/object.o: includes/primitive/sphere.h includes/raytracing/ray.h
./obj/object.o: includes/primitive/cylinder.h includes/primitive/cone.h
./obj/object.o: includes/primitive/plane.h includes/primitive/torus.h
./obj/object.o: includes/primitive/paraboloid.h
./obj/object.o: includes/primitive/rect.h includes/primitive/disk.h
./obj/object.o: includes/primitive/cuboid.h
./obj/object.o: includes/material/material.h includes/texture/texture.h
./obj/object_get_color_from_texture.o: includes/object/object.h
./obj/object_get_color_from_texture.o: includes/vect3d/vect3d.h
./obj/object_get_color_from_texture.o: includes/basis/basis.h
./obj/object_get_color_from_texture.o: includes/shape/shape.h
./obj/object_get_color_from_texture.o: includes/primitive/primitive.h
./obj/object_get_color_from_texture.o: includes/primitive/sphere.h
./obj/object_get_color_from_texture.o: includes/raytracing/ray.h
./obj/object_get_color_from_texture.o: includes/primitive/cylinder.h
./obj/object_get_color_from_texture.o: includes/primitive/cone.h
./obj/object_get_color_from_texture.o: includes/primitive/plane.h
./obj/object_get_color_from_texture.o: includes/primitive/torus.h
./obj/object_get_color_from_texture.o: includes/primitive/paraboloid.h
./obj/object_get_color_from_texture.o: includes/primitive/rect.h
./obj/object_get_color_from_texture.o: includes/primitive/disk.h
./obj/object_get_color_from_texture.o: includes/primitive/cuboid.h
./obj/object_get_color_from_texture.o: includes/material/material.h
./obj/object_get_color_from_texture.o: includes/texture/texture.h
./obj/object_get_color_from_texture.o: includes/color/color.h
./obj/object_update_material_according_to_tex.o: includes/object/object.h
./obj/object_update_material_according_to_tex.o: includes/vect3d/vect3d.h
./obj/object_update_material_according_to_tex.o: includes/basis/basis.h
./obj/object_update_material_according_to_tex.o: includes/shape/shape.h
./obj/object_update_material_according_to_tex.o: includes/primitive/primitive.h
./obj/object_update_material_according_to_tex.o: includes/primitive/sphere.h
./obj/object_update_material_according_to_tex.o: includes/raytracing/ray.h
./obj/object_update_material_according_to_tex.o: includes/primitive/cylinder.h
./obj/object_update_material_according_to_tex.o: includes/primitive/cone.h
./obj/object_update_material_according_to_tex.o: includes/primitive/plane.h
./obj/object_update_material_according_to_tex.o: includes/primitive/torus.h
./obj/object_update_material_according_to_tex.o: includes/primitive/paraboloid.h
./obj/object_update_material_according_to_tex.o: includes/primitive/rect.h
./obj/object_update_material_according_to_tex.o: includes/primitive/disk.h
./obj/object_update_material_according_to_tex.o: includes/primitive/cuboid.h
./obj/object_update_material_according_to_tex.o: includes/material/material.h
./obj/object_update_material_according_to_tex.o: includes/texture/texture.h
./obj/options_init.o: includes/options/options.h
./obj/options_is_filters_on.o: includes/options/options.h
./obj/angles_to_basis.o: includes/vect3d/vect3d.h
./obj/angles_to_basis.o: includes/basis/basis.h
./obj/angles_to_basis.o: includes/defines/options_manipulations_defines.h
./obj/angles_to_basis.o: srcs/parser/parser_private.h
./obj/angles_to_basis.o: includes/light/light.h
./obj/angles_to_basis.o: includes/light/point_light.h
./obj/angles_to_basis.o: includes/light/directional_light.h
./obj/angles_to_basis.o: includes/light/spotlight_light.h
./obj/angles_to_basis.o: includes/scene/scene.h
./obj/angles_to_basis.o: includes/camera/camera.h
./obj/angles_to_basis.o: includes/array_object/array_object.h
./obj/angles_to_basis.o: includes/object/object.h
./obj/angles_to_basis.o: includes/shape/shape.h
./obj/angles_to_basis.o: includes/primitive/primitive.h
./obj/angles_to_basis.o: includes/primitive/sphere.h
./obj/angles_to_basis.o: includes/raytracing/ray.h
./obj/angles_to_basis.o: includes/primitive/cylinder.h
./obj/angles_to_basis.o: includes/primitive/cone.h
./obj/angles_to_basis.o: includes/primitive/plane.h
./obj/angles_to_basis.o: includes/primitive/torus.h
./obj/angles_to_basis.o: includes/primitive/paraboloid.h
./obj/angles_to_basis.o: includes/primitive/rect.h
./obj/angles_to_basis.o: includes/primitive/disk.h
./obj/angles_to_basis.o: includes/primitive/cuboid.h
./obj/angles_to_basis.o: includes/material/material.h
./obj/angles_to_basis.o: includes/texture/texture.h
./obj/angles_to_basis.o: includes/array_light/array_light.h
./obj/create_lights.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/create_lights.o: includes/scene/scene.h includes/camera/camera.h
./obj/create_lights.o: includes/array_object/array_object.h
./obj/create_lights.o: includes/object/object.h includes/shape/shape.h
./obj/create_lights.o: includes/primitive/primitive.h
./obj/create_lights.o: includes/primitive/sphere.h
./obj/create_lights.o: includes/raytracing/ray.h
./obj/create_lights.o: includes/primitive/cylinder.h
./obj/create_lights.o: includes/primitive/cone.h
./obj/create_lights.o: includes/primitive/plane.h
./obj/create_lights.o: includes/primitive/torus.h
./obj/create_lights.o: includes/primitive/paraboloid.h
./obj/create_lights.o: includes/primitive/rect.h
./obj/create_lights.o: includes/primitive/disk.h
./obj/create_lights.o: includes/primitive/cuboid.h
./obj/create_lights.o: includes/material/material.h
./obj/create_lights.o: includes/texture/texture.h
./obj/create_lights.o: includes/array_light/array_light.h
./obj/create_lights.o: includes/light/light.h
./obj/create_lights.o: includes/light/point_light.h
./obj/create_lights.o: includes/light/directional_light.h
./obj/create_lights.o: includes/light/spotlight_light.h
./obj/create_lights.o: srcs/parser/parser_private.h
./obj/create_objects.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/create_objects.o: includes/scene/scene.h includes/camera/camera.h
./obj/create_objects.o: includes/array_object/array_object.h
./obj/create_objects.o: includes/object/object.h includes/shape/shape.h
./obj/create_objects.o: includes/primitive/primitive.h
./obj/create_objects.o: includes/primitive/sphere.h
./obj/create_objects.o: includes/raytracing/ray.h
./obj/create_objects.o: includes/primitive/cylinder.h
./obj/create_objects.o: includes/primitive/cone.h
./obj/create_objects.o: includes/primitive/plane.h
./obj/create_objects.o: includes/primitive/torus.h
./obj/create_objects.o: includes/primitive/paraboloid.h
./obj/create_objects.o: includes/primitive/rect.h
./obj/create_objects.o: includes/primitive/disk.h
./obj/create_objects.o: includes/primitive/cuboid.h
./obj/create_objects.o: includes/material/material.h
./obj/create_objects.o: includes/texture/texture.h
./obj/create_objects.o: includes/array_light/array_light.h
./obj/create_objects.o: includes/light/light.h
./obj/create_objects.o: includes/light/point_light.h
./obj/create_objects.o: includes/light/directional_light.h
./obj/create_objects.o: includes/light/spotlight_light.h
./obj/create_objects.o: srcs/parser/parser_private.h
./obj/create_objects.o: ./external/link/libft/libft_includes/libft.h
./obj/create_objects.o: ./external/link/libft/libft_includes/get_next_line.h
./obj/init_camera.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/init_camera.o: includes/scene/scene.h includes/camera/camera.h
./obj/init_camera.o: includes/array_object/array_object.h
./obj/init_camera.o: includes/object/object.h includes/shape/shape.h
./obj/init_camera.o: includes/primitive/primitive.h
./obj/init_camera.o: includes/primitive/sphere.h
./obj/init_camera.o: includes/raytracing/ray.h
./obj/init_camera.o: includes/primitive/cylinder.h
./obj/init_camera.o: includes/primitive/cone.h
./obj/init_camera.o: includes/primitive/plane.h
./obj/init_camera.o: includes/primitive/torus.h
./obj/init_camera.o: includes/primitive/paraboloid.h
./obj/init_camera.o: includes/primitive/rect.h
./obj/init_camera.o: includes/primitive/disk.h
./obj/init_camera.o: includes/primitive/cuboid.h
./obj/init_camera.o: includes/material/material.h
./obj/init_camera.o: includes/texture/texture.h
./obj/init_camera.o: includes/array_light/array_light.h
./obj/init_camera.o: includes/light/light.h
./obj/init_camera.o: includes/light/point_light.h
./obj/init_camera.o: includes/light/directional_light.h
./obj/init_camera.o: includes/light/spotlight_light.h
./obj/init_camera.o: srcs/parser/parser_private.h
./obj/parser.o: ./external/link/libft/libft_includes/libft.h
./obj/parser.o: ./external/link/libft/libft_includes/get_next_line.h
./obj/parser.o: srcs/parser/parser_private.h includes/light/light.h
./obj/parser.o: includes/light/point_light.h includes/vect3d/vect3d.h
./obj/parser.o: includes/light/directional_light.h
./obj/parser.o: includes/light/spotlight_light.h includes/scene/scene.h
./obj/parser.o: includes/camera/camera.h includes/basis/basis.h
./obj/parser.o: includes/array_object/array_object.h
./obj/parser.o: includes/object/object.h includes/shape/shape.h
./obj/parser.o: includes/primitive/primitive.h
./obj/parser.o: includes/primitive/sphere.h includes/raytracing/ray.h
./obj/parser.o: includes/primitive/cylinder.h includes/primitive/cone.h
./obj/parser.o: includes/primitive/plane.h includes/primitive/torus.h
./obj/parser.o: includes/primitive/paraboloid.h
./obj/parser.o: includes/primitive/rect.h includes/primitive/disk.h
./obj/parser.o: includes/primitive/cuboid.h
./obj/parser.o: includes/material/material.h includes/texture/texture.h
./obj/parser.o: includes/array_light/array_light.h
./obj/parser.o: includes/parser/parser.h
./obj/parser_put_error.o: srcs/parser/parser_private.h
./obj/parser_put_error.o: includes/light/light.h
./obj/parser_put_error.o: includes/light/point_light.h
./obj/parser_put_error.o: includes/vect3d/vect3d.h
./obj/parser_put_error.o: includes/light/directional_light.h
./obj/parser_put_error.o: includes/light/spotlight_light.h
./obj/parser_put_error.o: includes/scene/scene.h
./obj/parser_put_error.o: includes/camera/camera.h
./obj/parser_put_error.o: includes/basis/basis.h
./obj/parser_put_error.o: includes/array_object/array_object.h
./obj/parser_put_error.o: includes/object/object.h
./obj/parser_put_error.o: includes/shape/shape.h
./obj/parser_put_error.o: includes/primitive/primitive.h
./obj/parser_put_error.o: includes/primitive/sphere.h
./obj/parser_put_error.o: includes/raytracing/ray.h
./obj/parser_put_error.o: includes/primitive/cylinder.h
./obj/parser_put_error.o: includes/primitive/cone.h
./obj/parser_put_error.o: includes/primitive/plane.h
./obj/parser_put_error.o: includes/primitive/torus.h
./obj/parser_put_error.o: includes/primitive/paraboloid.h
./obj/parser_put_error.o: includes/primitive/rect.h
./obj/parser_put_error.o: includes/primitive/disk.h
./obj/parser_put_error.o: includes/primitive/cuboid.h
./obj/parser_put_error.o: includes/material/material.h
./obj/parser_put_error.o: includes/texture/texture.h
./obj/parser_put_error.o: includes/array_light/array_light.h
./obj/parser_put_error.o: ./external/link/libft/libft_includes/libft.h
./obj/parser_put_error.o: ./external/link/libft/libft_includes/get_next_line.h
./obj/parser_put_error_mapping.o: srcs/parser/parser_private.h
./obj/parser_put_error_mapping.o: includes/light/light.h
./obj/parser_put_error_mapping.o: includes/light/point_light.h
./obj/parser_put_error_mapping.o: includes/vect3d/vect3d.h
./obj/parser_put_error_mapping.o: includes/light/directional_light.h
./obj/parser_put_error_mapping.o: includes/light/spotlight_light.h
./obj/parser_put_error_mapping.o: includes/scene/scene.h
./obj/parser_put_error_mapping.o: includes/camera/camera.h
./obj/parser_put_error_mapping.o: includes/basis/basis.h
./obj/parser_put_error_mapping.o: includes/array_object/array_object.h
./obj/parser_put_error_mapping.o: includes/object/object.h
./obj/parser_put_error_mapping.o: includes/shape/shape.h
./obj/parser_put_error_mapping.o: includes/primitive/primitive.h
./obj/parser_put_error_mapping.o: includes/primitive/sphere.h
./obj/parser_put_error_mapping.o: includes/raytracing/ray.h
./obj/parser_put_error_mapping.o: includes/primitive/cylinder.h
./obj/parser_put_error_mapping.o: includes/primitive/cone.h
./obj/parser_put_error_mapping.o: includes/primitive/plane.h
./obj/parser_put_error_mapping.o: includes/primitive/torus.h
./obj/parser_put_error_mapping.o: includes/primitive/paraboloid.h
./obj/parser_put_error_mapping.o: includes/primitive/rect.h
./obj/parser_put_error_mapping.o: includes/primitive/disk.h
./obj/parser_put_error_mapping.o: includes/primitive/cuboid.h
./obj/parser_put_error_mapping.o: includes/material/material.h
./obj/parser_put_error_mapping.o: includes/texture/texture.h
./obj/parser_put_error_mapping.o: includes/array_light/array_light.h
./obj/validate_ads.o: srcs/parser/parser_private.h
./obj/validate_ads.o: includes/light/light.h
./obj/validate_ads.o: includes/light/point_light.h
./obj/validate_ads.o: includes/vect3d/vect3d.h
./obj/validate_ads.o: includes/light/directional_light.h
./obj/validate_ads.o: includes/light/spotlight_light.h
./obj/validate_ads.o: includes/scene/scene.h includes/camera/camera.h
./obj/validate_ads.o: includes/basis/basis.h
./obj/validate_ads.o: includes/array_object/array_object.h
./obj/validate_ads.o: includes/object/object.h includes/shape/shape.h
./obj/validate_ads.o: includes/primitive/primitive.h
./obj/validate_ads.o: includes/primitive/sphere.h
./obj/validate_ads.o: includes/raytracing/ray.h
./obj/validate_ads.o: includes/primitive/cylinder.h
./obj/validate_ads.o: includes/primitive/cone.h
./obj/validate_ads.o: includes/primitive/plane.h
./obj/validate_ads.o: includes/primitive/torus.h
./obj/validate_ads.o: includes/primitive/paraboloid.h
./obj/validate_ads.o: includes/primitive/rect.h
./obj/validate_ads.o: includes/primitive/disk.h
./obj/validate_ads.o: includes/primitive/cuboid.h
./obj/validate_ads.o: includes/material/material.h
./obj/validate_ads.o: includes/texture/texture.h
./obj/validate_ads.o: includes/array_light/array_light.h
./obj/validate_direction.o: srcs/parser/parser_private.h
./obj/validate_direction.o: includes/light/light.h
./obj/validate_direction.o: includes/light/point_light.h
./obj/validate_direction.o: includes/vect3d/vect3d.h
./obj/validate_direction.o: includes/light/directional_light.h
./obj/validate_direction.o: includes/light/spotlight_light.h
./obj/validate_direction.o: includes/scene/scene.h
./obj/validate_direction.o: includes/camera/camera.h
./obj/validate_direction.o: includes/basis/basis.h
./obj/validate_direction.o: includes/array_object/array_object.h
./obj/validate_direction.o: includes/object/object.h
./obj/validate_direction.o: includes/shape/shape.h
./obj/validate_direction.o: includes/primitive/primitive.h
./obj/validate_direction.o: includes/primitive/sphere.h
./obj/validate_direction.o: includes/raytracing/ray.h
./obj/validate_direction.o: includes/primitive/cylinder.h
./obj/validate_direction.o: includes/primitive/cone.h
./obj/validate_direction.o: includes/primitive/plane.h
./obj/validate_direction.o: includes/primitive/torus.h
./obj/validate_direction.o: includes/primitive/paraboloid.h
./obj/validate_direction.o: includes/primitive/rect.h
./obj/validate_direction.o: includes/primitive/disk.h
./obj/validate_direction.o: includes/primitive/cuboid.h
./obj/validate_direction.o: includes/material/material.h
./obj/validate_direction.o: includes/texture/texture.h
./obj/validate_direction.o: includes/array_light/array_light.h
./obj/validate_figures_1.o: srcs/parser/parser_private.h
./obj/validate_figures_1.o: includes/light/light.h
./obj/validate_figures_1.o: includes/light/point_light.h
./obj/validate_figures_1.o: includes/vect3d/vect3d.h
./obj/validate_figures_1.o: includes/light/directional_light.h
./obj/validate_figures_1.o: includes/light/spotlight_light.h
./obj/validate_figures_1.o: includes/scene/scene.h
./obj/validate_figures_1.o: includes/camera/camera.h
./obj/validate_figures_1.o: includes/basis/basis.h
./obj/validate_figures_1.o: includes/array_object/array_object.h
./obj/validate_figures_1.o: includes/object/object.h
./obj/validate_figures_1.o: includes/shape/shape.h
./obj/validate_figures_1.o: includes/primitive/primitive.h
./obj/validate_figures_1.o: includes/primitive/sphere.h
./obj/validate_figures_1.o: includes/raytracing/ray.h
./obj/validate_figures_1.o: includes/primitive/cylinder.h
./obj/validate_figures_1.o: includes/primitive/cone.h
./obj/validate_figures_1.o: includes/primitive/plane.h
./obj/validate_figures_1.o: includes/primitive/torus.h
./obj/validate_figures_1.o: includes/primitive/paraboloid.h
./obj/validate_figures_1.o: includes/primitive/rect.h
./obj/validate_figures_1.o: includes/primitive/disk.h
./obj/validate_figures_1.o: includes/primitive/cuboid.h
./obj/validate_figures_1.o: includes/material/material.h
./obj/validate_figures_1.o: includes/texture/texture.h
./obj/validate_figures_1.o: includes/array_light/array_light.h
./obj/validate_figures_1.o: srcs/parser/parser_values_limits.h
./obj/validate_figures_2.o: srcs/parser/parser_private.h
./obj/validate_figures_2.o: includes/light/light.h
./obj/validate_figures_2.o: includes/light/point_light.h
./obj/validate_figures_2.o: includes/vect3d/vect3d.h
./obj/validate_figures_2.o: includes/light/directional_light.h
./obj/validate_figures_2.o: includes/light/spotlight_light.h
./obj/validate_figures_2.o: includes/scene/scene.h
./obj/validate_figures_2.o: includes/camera/camera.h
./obj/validate_figures_2.o: includes/basis/basis.h
./obj/validate_figures_2.o: includes/array_object/array_object.h
./obj/validate_figures_2.o: includes/object/object.h
./obj/validate_figures_2.o: includes/shape/shape.h
./obj/validate_figures_2.o: includes/primitive/primitive.h
./obj/validate_figures_2.o: includes/primitive/sphere.h
./obj/validate_figures_2.o: includes/raytracing/ray.h
./obj/validate_figures_2.o: includes/primitive/cylinder.h
./obj/validate_figures_2.o: includes/primitive/cone.h
./obj/validate_figures_2.o: includes/primitive/plane.h
./obj/validate_figures_2.o: includes/primitive/torus.h
./obj/validate_figures_2.o: includes/primitive/paraboloid.h
./obj/validate_figures_2.o: includes/primitive/rect.h
./obj/validate_figures_2.o: includes/primitive/disk.h
./obj/validate_figures_2.o: includes/primitive/cuboid.h
./obj/validate_figures_2.o: includes/material/material.h
./obj/validate_figures_2.o: includes/texture/texture.h
./obj/validate_figures_2.o: includes/array_light/array_light.h
./obj/validate_figures_2.o: srcs/parser/parser_values_limits.h
./obj/validate_light_type.o: srcs/parser/parser_private.h
./obj/validate_light_type.o: includes/light/light.h
./obj/validate_light_type.o: includes/light/point_light.h
./obj/validate_light_type.o: includes/vect3d/vect3d.h
./obj/validate_light_type.o: includes/light/directional_light.h
./obj/validate_light_type.o: includes/light/spotlight_light.h
./obj/validate_light_type.o: includes/scene/scene.h
./obj/validate_light_type.o: includes/camera/camera.h
./obj/validate_light_type.o: includes/basis/basis.h
./obj/validate_light_type.o: includes/array_object/array_object.h
./obj/validate_light_type.o: includes/object/object.h
./obj/validate_light_type.o: includes/shape/shape.h
./obj/validate_light_type.o: includes/primitive/primitive.h
./obj/validate_light_type.o: includes/primitive/sphere.h
./obj/validate_light_type.o: includes/raytracing/ray.h
./obj/validate_light_type.o: includes/primitive/cylinder.h
./obj/validate_light_type.o: includes/primitive/cone.h
./obj/validate_light_type.o: includes/primitive/plane.h
./obj/validate_light_type.o: includes/primitive/torus.h
./obj/validate_light_type.o: includes/primitive/paraboloid.h
./obj/validate_light_type.o: includes/primitive/rect.h
./obj/validate_light_type.o: includes/primitive/disk.h
./obj/validate_light_type.o: includes/primitive/cuboid.h
./obj/validate_light_type.o: includes/material/material.h
./obj/validate_light_type.o: includes/texture/texture.h
./obj/validate_light_type.o: includes/array_light/array_light.h
./obj/validate_light_type.o: srcs/parser/parser_values_limits.h
./obj/validate_light_type_num.o: srcs/parser/parser_private.h
./obj/validate_light_type_num.o: includes/light/light.h
./obj/validate_light_type_num.o: includes/light/point_light.h
./obj/validate_light_type_num.o: includes/vect3d/vect3d.h
./obj/validate_light_type_num.o: includes/light/directional_light.h
./obj/validate_light_type_num.o: includes/light/spotlight_light.h
./obj/validate_light_type_num.o: includes/scene/scene.h
./obj/validate_light_type_num.o: includes/camera/camera.h
./obj/validate_light_type_num.o: includes/basis/basis.h
./obj/validate_light_type_num.o: includes/array_object/array_object.h
./obj/validate_light_type_num.o: includes/object/object.h
./obj/validate_light_type_num.o: includes/shape/shape.h
./obj/validate_light_type_num.o: includes/primitive/primitive.h
./obj/validate_light_type_num.o: includes/primitive/sphere.h
./obj/validate_light_type_num.o: includes/raytracing/ray.h
./obj/validate_light_type_num.o: includes/primitive/cylinder.h
./obj/validate_light_type_num.o: includes/primitive/cone.h
./obj/validate_light_type_num.o: includes/primitive/plane.h
./obj/validate_light_type_num.o: includes/primitive/torus.h
./obj/validate_light_type_num.o: includes/primitive/paraboloid.h
./obj/validate_light_type_num.o: includes/primitive/rect.h
./obj/validate_light_type_num.o: includes/primitive/disk.h
./obj/validate_light_type_num.o: includes/primitive/cuboid.h
./obj/validate_light_type_num.o: includes/material/material.h
./obj/validate_light_type_num.o: includes/texture/texture.h
./obj/validate_light_type_num.o: includes/array_light/array_light.h
./obj/validate_lights.o: srcs/parser/parser_private.h
./obj/validate_lights.o: includes/light/light.h
./obj/validate_lights.o: includes/light/point_light.h
./obj/validate_lights.o: includes/vect3d/vect3d.h
./obj/validate_lights.o: includes/light/directional_light.h
./obj/validate_lights.o: includes/light/spotlight_light.h
./obj/validate_lights.o: includes/scene/scene.h
./obj/validate_lights.o: includes/camera/camera.h
./obj/validate_lights.o: includes/basis/basis.h
./obj/validate_lights.o: includes/array_object/array_object.h
./obj/validate_lights.o: includes/object/object.h
./obj/validate_lights.o: includes/shape/shape.h
./obj/validate_lights.o: includes/primitive/primitive.h
./obj/validate_lights.o: includes/primitive/sphere.h
./obj/validate_lights.o: includes/raytracing/ray.h
./obj/validate_lights.o: includes/primitive/cylinder.h
./obj/validate_lights.o: includes/primitive/cone.h
./obj/validate_lights.o: includes/primitive/plane.h
./obj/validate_lights.o: includes/primitive/torus.h
./obj/validate_lights.o: includes/primitive/paraboloid.h
./obj/validate_lights.o: includes/primitive/rect.h
./obj/validate_lights.o: includes/primitive/disk.h
./obj/validate_lights.o: includes/primitive/cuboid.h
./obj/validate_lights.o: includes/material/material.h
./obj/validate_lights.o: includes/texture/texture.h
./obj/validate_lights.o: includes/array_light/array_light.h
./obj/validate_obj_material.o: srcs/parser/parser_private.h
./obj/validate_obj_material.o: includes/light/light.h
./obj/validate_obj_material.o: includes/light/point_light.h
./obj/validate_obj_material.o: includes/vect3d/vect3d.h
./obj/validate_obj_material.o: includes/light/directional_light.h
./obj/validate_obj_material.o: includes/light/spotlight_light.h
./obj/validate_obj_material.o: includes/scene/scene.h
./obj/validate_obj_material.o: includes/camera/camera.h
./obj/validate_obj_material.o: includes/basis/basis.h
./obj/validate_obj_material.o: includes/array_object/array_object.h
./obj/validate_obj_material.o: includes/object/object.h
./obj/validate_obj_material.o: includes/shape/shape.h
./obj/validate_obj_material.o: includes/primitive/primitive.h
./obj/validate_obj_material.o: includes/primitive/sphere.h
./obj/validate_obj_material.o: includes/raytracing/ray.h
./obj/validate_obj_material.o: includes/primitive/cylinder.h
./obj/validate_obj_material.o: includes/primitive/cone.h
./obj/validate_obj_material.o: includes/primitive/plane.h
./obj/validate_obj_material.o: includes/primitive/torus.h
./obj/validate_obj_material.o: includes/primitive/paraboloid.h
./obj/validate_obj_material.o: includes/primitive/rect.h
./obj/validate_obj_material.o: includes/primitive/disk.h
./obj/validate_obj_material.o: includes/primitive/cuboid.h
./obj/validate_obj_material.o: includes/material/material.h
./obj/validate_obj_material.o: includes/texture/texture.h
./obj/validate_obj_material.o: includes/array_light/array_light.h
./obj/validate_obj_material.o: srcs/parser/parser_values_limits.h
./obj/validate_obj_type.o: srcs/parser/parser_private.h
./obj/validate_obj_type.o: includes/light/light.h
./obj/validate_obj_type.o: includes/light/point_light.h
./obj/validate_obj_type.o: includes/vect3d/vect3d.h
./obj/validate_obj_type.o: includes/light/directional_light.h
./obj/validate_obj_type.o: includes/light/spotlight_light.h
./obj/validate_obj_type.o: includes/scene/scene.h
./obj/validate_obj_type.o: includes/camera/camera.h
./obj/validate_obj_type.o: includes/basis/basis.h
./obj/validate_obj_type.o: includes/array_object/array_object.h
./obj/validate_obj_type.o: includes/object/object.h
./obj/validate_obj_type.o: includes/shape/shape.h
./obj/validate_obj_type.o: includes/primitive/primitive.h
./obj/validate_obj_type.o: includes/primitive/sphere.h
./obj/validate_obj_type.o: includes/raytracing/ray.h
./obj/validate_obj_type.o: includes/primitive/cylinder.h
./obj/validate_obj_type.o: includes/primitive/cone.h
./obj/validate_obj_type.o: includes/primitive/plane.h
./obj/validate_obj_type.o: includes/primitive/torus.h
./obj/validate_obj_type.o: includes/primitive/paraboloid.h
./obj/validate_obj_type.o: includes/primitive/rect.h
./obj/validate_obj_type.o: includes/primitive/disk.h
./obj/validate_obj_type.o: includes/primitive/cuboid.h
./obj/validate_obj_type.o: includes/material/material.h
./obj/validate_obj_type.o: includes/texture/texture.h
./obj/validate_obj_type.o: includes/array_light/array_light.h
./obj/validate_obj_type_num.o: srcs/parser/parser_private.h
./obj/validate_obj_type_num.o: includes/light/light.h
./obj/validate_obj_type_num.o: includes/light/point_light.h
./obj/validate_obj_type_num.o: includes/vect3d/vect3d.h
./obj/validate_obj_type_num.o: includes/light/directional_light.h
./obj/validate_obj_type_num.o: includes/light/spotlight_light.h
./obj/validate_obj_type_num.o: includes/scene/scene.h
./obj/validate_obj_type_num.o: includes/camera/camera.h
./obj/validate_obj_type_num.o: includes/basis/basis.h
./obj/validate_obj_type_num.o: includes/array_object/array_object.h
./obj/validate_obj_type_num.o: includes/object/object.h
./obj/validate_obj_type_num.o: includes/shape/shape.h
./obj/validate_obj_type_num.o: includes/primitive/primitive.h
./obj/validate_obj_type_num.o: includes/primitive/sphere.h
./obj/validate_obj_type_num.o: includes/raytracing/ray.h
./obj/validate_obj_type_num.o: includes/primitive/cylinder.h
./obj/validate_obj_type_num.o: includes/primitive/cone.h
./obj/validate_obj_type_num.o: includes/primitive/plane.h
./obj/validate_obj_type_num.o: includes/primitive/torus.h
./obj/validate_obj_type_num.o: includes/primitive/paraboloid.h
./obj/validate_obj_type_num.o: includes/primitive/rect.h
./obj/validate_obj_type_num.o: includes/primitive/disk.h
./obj/validate_obj_type_num.o: includes/primitive/cuboid.h
./obj/validate_obj_type_num.o: includes/material/material.h
./obj/validate_obj_type_num.o: includes/texture/texture.h
./obj/validate_obj_type_num.o: includes/array_light/array_light.h
./obj/validate_objects.o: srcs/parser/parser_private.h
./obj/validate_objects.o: includes/light/light.h
./obj/validate_objects.o: includes/light/point_light.h
./obj/validate_objects.o: includes/vect3d/vect3d.h
./obj/validate_objects.o: includes/light/directional_light.h
./obj/validate_objects.o: includes/light/spotlight_light.h
./obj/validate_objects.o: includes/scene/scene.h
./obj/validate_objects.o: includes/camera/camera.h
./obj/validate_objects.o: includes/basis/basis.h
./obj/validate_objects.o: includes/array_object/array_object.h
./obj/validate_objects.o: includes/object/object.h
./obj/validate_objects.o: includes/shape/shape.h
./obj/validate_objects.o: includes/primitive/primitive.h
./obj/validate_objects.o: includes/primitive/sphere.h
./obj/validate_objects.o: includes/raytracing/ray.h
./obj/validate_objects.o: includes/primitive/cylinder.h
./obj/validate_objects.o: includes/primitive/cone.h
./obj/validate_objects.o: includes/primitive/plane.h
./obj/validate_objects.o: includes/primitive/torus.h
./obj/validate_objects.o: includes/primitive/paraboloid.h
./obj/validate_objects.o: includes/primitive/rect.h
./obj/validate_objects.o: includes/primitive/disk.h
./obj/validate_objects.o: includes/primitive/cuboid.h
./obj/validate_objects.o: includes/material/material.h
./obj/validate_objects.o: includes/texture/texture.h
./obj/validate_objects.o: includes/array_light/array_light.h
./obj/validate_parsed_values.o: srcs/parser/parser_private.h
./obj/validate_parsed_values.o: includes/light/light.h
./obj/validate_parsed_values.o: includes/light/point_light.h
./obj/validate_parsed_values.o: includes/vect3d/vect3d.h
./obj/validate_parsed_values.o: includes/light/directional_light.h
./obj/validate_parsed_values.o: includes/light/spotlight_light.h
./obj/validate_parsed_values.o: includes/scene/scene.h
./obj/validate_parsed_values.o: includes/camera/camera.h
./obj/validate_parsed_values.o: includes/basis/basis.h
./obj/validate_parsed_values.o: includes/array_object/array_object.h
./obj/validate_parsed_values.o: includes/object/object.h
./obj/validate_parsed_values.o: includes/shape/shape.h
./obj/validate_parsed_values.o: includes/primitive/primitive.h
./obj/validate_parsed_values.o: includes/primitive/sphere.h
./obj/validate_parsed_values.o: includes/raytracing/ray.h
./obj/validate_parsed_values.o: includes/primitive/cylinder.h
./obj/validate_parsed_values.o: includes/primitive/cone.h
./obj/validate_parsed_values.o: includes/primitive/plane.h
./obj/validate_parsed_values.o: includes/primitive/torus.h
./obj/validate_parsed_values.o: includes/primitive/paraboloid.h
./obj/validate_parsed_values.o: includes/primitive/rect.h
./obj/validate_parsed_values.o: includes/primitive/disk.h
./obj/validate_parsed_values.o: includes/primitive/cuboid.h
./obj/validate_parsed_values.o: includes/material/material.h
./obj/validate_parsed_values.o: includes/texture/texture.h
./obj/validate_parsed_values.o: includes/array_light/array_light.h
./obj/validate_value_float.o: srcs/parser/parser_private.h
./obj/validate_value_float.o: includes/light/light.h
./obj/validate_value_float.o: includes/light/point_light.h
./obj/validate_value_float.o: includes/vect3d/vect3d.h
./obj/validate_value_float.o: includes/light/directional_light.h
./obj/validate_value_float.o: includes/light/spotlight_light.h
./obj/validate_value_float.o: includes/scene/scene.h
./obj/validate_value_float.o: includes/camera/camera.h
./obj/validate_value_float.o: includes/basis/basis.h
./obj/validate_value_float.o: includes/array_object/array_object.h
./obj/validate_value_float.o: includes/object/object.h
./obj/validate_value_float.o: includes/shape/shape.h
./obj/validate_value_float.o: includes/primitive/primitive.h
./obj/validate_value_float.o: includes/primitive/sphere.h
./obj/validate_value_float.o: includes/raytracing/ray.h
./obj/validate_value_float.o: includes/primitive/cylinder.h
./obj/validate_value_float.o: includes/primitive/cone.h
./obj/validate_value_float.o: includes/primitive/plane.h
./obj/validate_value_float.o: includes/primitive/torus.h
./obj/validate_value_float.o: includes/primitive/paraboloid.h
./obj/validate_value_float.o: includes/primitive/rect.h
./obj/validate_value_float.o: includes/primitive/disk.h
./obj/validate_value_float.o: includes/primitive/cuboid.h
./obj/validate_value_float.o: includes/material/material.h
./obj/validate_value_float.o: includes/texture/texture.h
./obj/validate_value_float.o: includes/array_light/array_light.h
./obj/vect3d_from_float.o: includes/vect3d/vect3d.h
./obj/cone.o: includes/primitive/cone.h includes/raytracing/ray.h
./obj/cone.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/cone.o: includes/primitive/primitive.h
./obj/cone.o: includes/primitive/sphere.h
./obj/cone.o: includes/primitive/cylinder.h
./obj/cone.o: includes/primitive/plane.h includes/primitive/torus.h
./obj/cone.o: includes/primitive/paraboloid.h
./obj/cone.o: includes/primitive/rect.h includes/primitive/disk.h
./obj/cone.o: includes/primitive/cuboid.h includes/mmath/mmath.h
./obj/cone.o: srcs/primitive/primitive_private.h
./obj/cone_create.o: includes/primitive/cone.h
./obj/cone_create.o: includes/raytracing/ray.h
./obj/cone_create.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/cuboid.o: includes/primitive/cuboid.h
./obj/cuboid.o: includes/primitive/rect.h includes/raytracing/ray.h
./obj/cuboid.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/cuboid.o: includes/primitive/primitive.h
./obj/cuboid.o: includes/primitive/sphere.h
./obj/cuboid.o: includes/primitive/cylinder.h
./obj/cuboid.o: includes/primitive/cone.h includes/primitive/plane.h
./obj/cuboid.o: includes/primitive/torus.h
./obj/cuboid.o: includes/primitive/paraboloid.h
./obj/cuboid.o: includes/primitive/disk.h includes/mmath/mmath.h
./obj/cuboid_create.o: includes/primitive/cuboid.h
./obj/cuboid_create.o: includes/primitive/rect.h
./obj/cuboid_create.o: includes/raytracing/ray.h
./obj/cuboid_create.o: includes/vect3d/vect3d.h
./obj/cuboid_create.o: includes/basis/basis.h
./obj/cylinder.o: includes/primitive/cylinder.h
./obj/cylinder.o: includes/raytracing/ray.h includes/vect3d/vect3d.h
./obj/cylinder.o: includes/basis/basis.h
./obj/cylinder.o: includes/primitive/primitive.h
./obj/cylinder.o: includes/primitive/sphere.h
./obj/cylinder.o: includes/primitive/cone.h
./obj/cylinder.o: includes/primitive/plane.h
./obj/cylinder.o: includes/primitive/torus.h
./obj/cylinder.o: includes/primitive/paraboloid.h
./obj/cylinder.o: includes/primitive/rect.h
./obj/cylinder.o: includes/primitive/disk.h
./obj/cylinder.o: includes/primitive/cuboid.h includes/mmath/mmath.h
./obj/disk.o: includes/primitive/disk.h includes/raytracing/ray.h
./obj/disk.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/disk.o: includes/primitive/primitive.h
./obj/disk.o: includes/primitive/sphere.h
./obj/disk.o: includes/primitive/cylinder.h
./obj/disk.o: includes/primitive/cone.h includes/primitive/plane.h
./obj/disk.o: includes/primitive/torus.h
./obj/disk.o: includes/primitive/paraboloid.h
./obj/disk.o: includes/primitive/rect.h includes/primitive/cuboid.h
./obj/disk.o: includes/mmath/mmath.h
./obj/paraboloid.o: includes/primitive/paraboloid.h
./obj/paraboloid.o: includes/raytracing/ray.h
./obj/paraboloid.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/paraboloid.o: includes/primitive/primitive.h
./obj/paraboloid.o: includes/primitive/sphere.h
./obj/paraboloid.o: includes/primitive/cylinder.h
./obj/paraboloid.o: includes/primitive/cone.h
./obj/paraboloid.o: includes/primitive/plane.h
./obj/paraboloid.o: includes/primitive/torus.h
./obj/paraboloid.o: includes/primitive/rect.h
./obj/paraboloid.o: includes/primitive/disk.h
./obj/paraboloid.o: includes/primitive/cuboid.h
./obj/paraboloid.o: includes/mmath/mmath.h
./obj/paraboloid.o: srcs/primitive/primitive_private.h
./obj/paraboloid_create.o: includes/primitive/paraboloid.h
./obj/paraboloid_create.o: includes/raytracing/ray.h
./obj/paraboloid_create.o: includes/vect3d/vect3d.h
./obj/paraboloid_create.o: includes/basis/basis.h
./obj/plane.o: includes/primitive/plane.h includes/raytracing/ray.h
./obj/plane.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/plane.o: includes/primitive/primitive.h
./obj/plane.o: includes/primitive/sphere.h
./obj/plane.o: includes/primitive/cylinder.h
./obj/plane.o: includes/primitive/cone.h includes/primitive/torus.h
./obj/plane.o: includes/primitive/paraboloid.h
./obj/plane.o: includes/primitive/rect.h includes/primitive/disk.h
./obj/plane.o: includes/primitive/cuboid.h includes/mmath/mmath.h
./obj/rect.o: includes/primitive/rect.h includes/raytracing/ray.h
./obj/rect.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/rect.o: includes/primitive/primitive.h
./obj/rect.o: includes/primitive/sphere.h
./obj/rect.o: includes/primitive/cylinder.h
./obj/rect.o: includes/primitive/cone.h includes/primitive/plane.h
./obj/rect.o: includes/primitive/torus.h
./obj/rect.o: includes/primitive/paraboloid.h
./obj/rect.o: includes/primitive/disk.h includes/primitive/cuboid.h
./obj/rect.o: includes/mmath/mmath.h
./obj/sort_and_left_positive_roots.o: srcs/primitive/primitive_private.h
./obj/sort_and_left_positive_roots.o: ./external/link/libft/libft_includes/libft.h
./obj/sort_and_left_positive_roots.o: ./external/link/libft/libft_includes/get_next_line.h
./obj/sphere.o: includes/primitive/sphere.h
./obj/sphere.o: includes/raytracing/ray.h includes/vect3d/vect3d.h
./obj/sphere.o: includes/basis/basis.h
./obj/sphere.o: includes/primitive/primitive.h
./obj/sphere.o: includes/primitive/cylinder.h
./obj/sphere.o: includes/primitive/cone.h includes/primitive/plane.h
./obj/sphere.o: includes/primitive/torus.h
./obj/sphere.o: includes/primitive/paraboloid.h
./obj/sphere.o: includes/primitive/rect.h includes/primitive/disk.h
./obj/sphere.o: includes/primitive/cuboid.h includes/mmath/mmath.h
./obj/torus.o: includes/primitive/torus.h includes/raytracing/ray.h
./obj/torus.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/torus.o: includes/primitive/primitive.h
./obj/torus.o: includes/primitive/sphere.h
./obj/torus.o: includes/primitive/cylinder.h
./obj/torus.o: includes/primitive/cone.h includes/primitive/plane.h
./obj/torus.o: includes/primitive/paraboloid.h
./obj/torus.o: includes/primitive/rect.h includes/primitive/disk.h
./obj/torus.o: includes/primitive/cuboid.h includes/mmath/mmath.h
./obj/torus.o: srcs/primitive/primitive_private.h
./obj/apply_light.o: srcs/raytracing/raytracing_private.h
./obj/apply_light.o: includes/scene/scene.h
./obj/apply_light.o: includes/camera/camera.h
./obj/apply_light.o: includes/vect3d/vect3d.h
./obj/apply_light.o: includes/basis/basis.h
./obj/apply_light.o: includes/array_object/array_object.h
./obj/apply_light.o: includes/object/object.h
./obj/apply_light.o: includes/shape/shape.h
./obj/apply_light.o: includes/primitive/primitive.h
./obj/apply_light.o: includes/primitive/sphere.h
./obj/apply_light.o: includes/raytracing/ray.h
./obj/apply_light.o: includes/primitive/cylinder.h
./obj/apply_light.o: includes/primitive/cone.h
./obj/apply_light.o: includes/primitive/plane.h
./obj/apply_light.o: includes/primitive/torus.h
./obj/apply_light.o: includes/primitive/paraboloid.h
./obj/apply_light.o: includes/primitive/rect.h
./obj/apply_light.o: includes/primitive/disk.h
./obj/apply_light.o: includes/primitive/cuboid.h
./obj/apply_light.o: includes/material/material.h
./obj/apply_light.o: includes/texture/texture.h
./obj/apply_light.o: includes/array_light/array_light.h
./obj/apply_light.o: includes/light/light.h
./obj/apply_light.o: includes/light/point_light.h
./obj/apply_light.o: includes/light/directional_light.h
./obj/apply_light.o: includes/light/spotlight_light.h
./obj/apply_light.o: includes/raytracing/intersection.h
./obj/find_closest_intersection.o: includes/scene/scene.h
./obj/find_closest_intersection.o: includes/camera/camera.h
./obj/find_closest_intersection.o: includes/vect3d/vect3d.h
./obj/find_closest_intersection.o: includes/basis/basis.h
./obj/find_closest_intersection.o: includes/array_object/array_object.h
./obj/find_closest_intersection.o: includes/object/object.h
./obj/find_closest_intersection.o: includes/shape/shape.h
./obj/find_closest_intersection.o: includes/primitive/primitive.h
./obj/find_closest_intersection.o: includes/primitive/sphere.h
./obj/find_closest_intersection.o: includes/raytracing/ray.h
./obj/find_closest_intersection.o: includes/primitive/cylinder.h
./obj/find_closest_intersection.o: includes/primitive/cone.h
./obj/find_closest_intersection.o: includes/primitive/plane.h
./obj/find_closest_intersection.o: includes/primitive/torus.h
./obj/find_closest_intersection.o: includes/primitive/paraboloid.h
./obj/find_closest_intersection.o: includes/primitive/rect.h
./obj/find_closest_intersection.o: includes/primitive/disk.h
./obj/find_closest_intersection.o: includes/primitive/cuboid.h
./obj/find_closest_intersection.o: includes/material/material.h
./obj/find_closest_intersection.o: includes/texture/texture.h
./obj/find_closest_intersection.o: includes/array_light/array_light.h
./obj/find_closest_intersection.o: includes/light/light.h
./obj/find_closest_intersection.o: includes/light/point_light.h
./obj/find_closest_intersection.o: includes/light/directional_light.h
./obj/find_closest_intersection.o: includes/light/spotlight_light.h
./obj/find_closest_intersection.o: includes/raytracing/intersection.h
./obj/fresnel.o: srcs/raytracing/raytracing_private.h
./obj/fresnel.o: includes/vect3d/vect3d.h
./obj/get_ray_dir.o: srcs/raytracing/raytracing_private.h
./obj/get_ray_dir.o: includes/vect3d/vect3d.h
./obj/get_ray_dir.o: includes/camera/camera.h
./obj/get_ray_dir.o: includes/basis/basis.h
./obj/get_ray_dir.o: includes/canvas/canvas.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/get_ray_dir.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/get_refraction_ray.o: srcs/raytracing/raytracing_private.h
./obj/get_refraction_ray.o: includes/vect3d/vect3d.h
./obj/handle_reflection_and_refraction.o: srcs/raytracing/raytracing_private.h
./obj/handle_reflection_and_refraction.o: includes/raytracing/intersection.h
./obj/handle_reflection_and_refraction.o: includes/vect3d/vect3d.h
./obj/handle_reflection_and_refraction.o: includes/object/object.h
./obj/handle_reflection_and_refraction.o: includes/basis/basis.h
./obj/handle_reflection_and_refraction.o: includes/shape/shape.h
./obj/handle_reflection_and_refraction.o: includes/primitive/primitive.h
./obj/handle_reflection_and_refraction.o: includes/primitive/sphere.h
./obj/handle_reflection_and_refraction.o: includes/raytracing/ray.h
./obj/handle_reflection_and_refraction.o: includes/primitive/cylinder.h
./obj/handle_reflection_and_refraction.o: includes/primitive/cone.h
./obj/handle_reflection_and_refraction.o: includes/primitive/plane.h
./obj/handle_reflection_and_refraction.o: includes/primitive/torus.h
./obj/handle_reflection_and_refraction.o: includes/primitive/paraboloid.h
./obj/handle_reflection_and_refraction.o: includes/primitive/rect.h
./obj/handle_reflection_and_refraction.o: includes/primitive/disk.h
./obj/handle_reflection_and_refraction.o: includes/primitive/cuboid.h
./obj/handle_reflection_and_refraction.o: includes/material/material.h
./obj/handle_reflection_and_refraction.o: includes/texture/texture.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/raytracing/raytracing.h
./obj/raytracing_get_obj_idx_on_coord.o: srcs/raytracing/raytracing_private.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/scene/scene.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/camera/camera.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/vect3d/vect3d.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/basis/basis.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/array_object/array_object.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/object/object.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/shape/shape.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/primitive.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/sphere.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/raytracing/ray.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/cylinder.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/cone.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/plane.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/torus.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/paraboloid.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/rect.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/disk.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/primitive/cuboid.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/material/material.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/texture/texture.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/array_light/array_light.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/light/light.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/light/point_light.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/light/directional_light.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/light/spotlight_light.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/canvas/canvas.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/raytracing_get_obj_idx_on_coord.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/raytracing_get_obj_idx_on_coord.o: includes/raytracing/intersection.h
./obj/raytracing_get_obj_on_dir.o: includes/raytracing/raytracing.h
./obj/raytracing_get_obj_on_dir.o: srcs/raytracing/raytracing_private.h
./obj/raytracing_get_obj_on_dir.o: includes/vect3d/vect3d.h
./obj/raytracing_get_obj_on_dir.o: includes/scene/scene.h
./obj/raytracing_get_obj_on_dir.o: includes/camera/camera.h
./obj/raytracing_get_obj_on_dir.o: includes/basis/basis.h
./obj/raytracing_get_obj_on_dir.o: includes/array_object/array_object.h
./obj/raytracing_get_obj_on_dir.o: includes/object/object.h
./obj/raytracing_get_obj_on_dir.o: includes/shape/shape.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/primitive.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/sphere.h
./obj/raytracing_get_obj_on_dir.o: includes/raytracing/ray.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/cylinder.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/cone.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/plane.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/torus.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/paraboloid.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/rect.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/disk.h
./obj/raytracing_get_obj_on_dir.o: includes/primitive/cuboid.h
./obj/raytracing_get_obj_on_dir.o: includes/material/material.h
./obj/raytracing_get_obj_on_dir.o: includes/texture/texture.h
./obj/raytracing_get_obj_on_dir.o: includes/array_light/array_light.h
./obj/raytracing_get_obj_on_dir.o: includes/light/light.h
./obj/raytracing_get_obj_on_dir.o: includes/light/point_light.h
./obj/raytracing_get_obj_on_dir.o: includes/light/directional_light.h
./obj/raytracing_get_obj_on_dir.o: includes/light/spotlight_light.h
./obj/raytracing_get_obj_on_dir.o: includes/raytracing/intersection.h
./obj/raytracing_trace.o: includes/raytracing/raytracing.h
./obj/raytracing_trace.o: srcs/raytracing/raytracing_private.h
./obj/raytracing_trace.o: includes/scene/scene.h
./obj/raytracing_trace.o: includes/camera/camera.h
./obj/raytracing_trace.o: includes/vect3d/vect3d.h
./obj/raytracing_trace.o: includes/basis/basis.h
./obj/raytracing_trace.o: includes/array_object/array_object.h
./obj/raytracing_trace.o: includes/object/object.h
./obj/raytracing_trace.o: includes/shape/shape.h
./obj/raytracing_trace.o: includes/primitive/primitive.h
./obj/raytracing_trace.o: includes/primitive/sphere.h
./obj/raytracing_trace.o: includes/raytracing/ray.h
./obj/raytracing_trace.o: includes/primitive/cylinder.h
./obj/raytracing_trace.o: includes/primitive/cone.h
./obj/raytracing_trace.o: includes/primitive/plane.h
./obj/raytracing_trace.o: includes/primitive/torus.h
./obj/raytracing_trace.o: includes/primitive/paraboloid.h
./obj/raytracing_trace.o: includes/primitive/rect.h
./obj/raytracing_trace.o: includes/primitive/disk.h
./obj/raytracing_trace.o: includes/primitive/cuboid.h
./obj/raytracing_trace.o: includes/material/material.h
./obj/raytracing_trace.o: includes/texture/texture.h
./obj/raytracing_trace.o: includes/array_light/array_light.h
./obj/raytracing_trace.o: includes/light/light.h
./obj/raytracing_trace.o: includes/light/point_light.h
./obj/raytracing_trace.o: includes/light/directional_light.h
./obj/raytracing_trace.o: includes/light/spotlight_light.h
./obj/raytracing_trace.o: includes/canvas/canvas.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/raytracing_trace.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/raytracing_trace_with_antialiasing.o: includes/raytracing/raytracing.h
./obj/raytracing_trace_with_antialiasing.o: srcs/raytracing/raytracing_private.h
./obj/raytracing_trace_with_antialiasing.o: includes/scene/scene.h
./obj/raytracing_trace_with_antialiasing.o: includes/camera/camera.h
./obj/raytracing_trace_with_antialiasing.o: includes/vect3d/vect3d.h
./obj/raytracing_trace_with_antialiasing.o: includes/basis/basis.h
./obj/raytracing_trace_with_antialiasing.o: includes/array_object/array_object.h
./obj/raytracing_trace_with_antialiasing.o: includes/object/object.h
./obj/raytracing_trace_with_antialiasing.o: includes/shape/shape.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/primitive.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/sphere.h
./obj/raytracing_trace_with_antialiasing.o: includes/raytracing/ray.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/cylinder.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/cone.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/plane.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/torus.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/paraboloid.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/rect.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/disk.h
./obj/raytracing_trace_with_antialiasing.o: includes/primitive/cuboid.h
./obj/raytracing_trace_with_antialiasing.o: includes/material/material.h
./obj/raytracing_trace_with_antialiasing.o: includes/texture/texture.h
./obj/raytracing_trace_with_antialiasing.o: includes/array_light/array_light.h
./obj/raytracing_trace_with_antialiasing.o: includes/light/light.h
./obj/raytracing_trace_with_antialiasing.o: includes/light/point_light.h
./obj/raytracing_trace_with_antialiasing.o: includes/light/directional_light.h
./obj/raytracing_trace_with_antialiasing.o: includes/light/spotlight_light.h
./obj/raytracing_trace_with_antialiasing.o: includes/canvas/canvas.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/raytracing_trace_with_antialiasing.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/trace_ray.o: srcs/raytracing/raytracing_private.h
./obj/trace_ray.o: includes/scene/scene.h includes/camera/camera.h
./obj/trace_ray.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/trace_ray.o: includes/array_object/array_object.h
./obj/trace_ray.o: includes/object/object.h includes/shape/shape.h
./obj/trace_ray.o: includes/primitive/primitive.h
./obj/trace_ray.o: includes/primitive/sphere.h
./obj/trace_ray.o: includes/raytracing/ray.h
./obj/trace_ray.o: includes/primitive/cylinder.h
./obj/trace_ray.o: includes/primitive/cone.h
./obj/trace_ray.o: includes/primitive/plane.h
./obj/trace_ray.o: includes/primitive/torus.h
./obj/trace_ray.o: includes/primitive/paraboloid.h
./obj/trace_ray.o: includes/primitive/rect.h
./obj/trace_ray.o: includes/primitive/disk.h
./obj/trace_ray.o: includes/primitive/cuboid.h
./obj/trace_ray.o: includes/material/material.h
./obj/trace_ray.o: includes/texture/texture.h
./obj/trace_ray.o: includes/array_light/array_light.h
./obj/trace_ray.o: includes/light/light.h
./obj/trace_ray.o: includes/light/point_light.h
./obj/trace_ray.o: includes/light/directional_light.h
./obj/trace_ray.o: includes/light/spotlight_light.h
./obj/trace_ray.o: includes/raytracing/raytracing.h
./obj/trace_ray.o: includes/raytracing/intersection.h
./obj/render_on_canvas.o: includes/render/render.h
./obj/render_on_canvas_parallel.o: includes/render/render.h
./obj/render_on_canvas_parallel.o: srcs/render/render_private.h
./obj/render_on_canvas_parallel.o: includes/canvas/canvas.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/render_on_canvas_parallel.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/render_on_canvas_single.o: includes/render/render.h
./obj/render_on_canvas_single.o: srcs/render/render_private.h
./obj/render_on_canvas_single.o: includes/scene/scene.h
./obj/render_on_canvas_single.o: includes/camera/camera.h
./obj/render_on_canvas_single.o: includes/vect3d/vect3d.h
./obj/render_on_canvas_single.o: includes/basis/basis.h
./obj/render_on_canvas_single.o: includes/array_object/array_object.h
./obj/render_on_canvas_single.o: includes/object/object.h
./obj/render_on_canvas_single.o: includes/shape/shape.h
./obj/render_on_canvas_single.o: includes/primitive/primitive.h
./obj/render_on_canvas_single.o: includes/primitive/sphere.h
./obj/render_on_canvas_single.o: includes/raytracing/ray.h
./obj/render_on_canvas_single.o: includes/primitive/cylinder.h
./obj/render_on_canvas_single.o: includes/primitive/cone.h
./obj/render_on_canvas_single.o: includes/primitive/plane.h
./obj/render_on_canvas_single.o: includes/primitive/torus.h
./obj/render_on_canvas_single.o: includes/primitive/paraboloid.h
./obj/render_on_canvas_single.o: includes/primitive/rect.h
./obj/render_on_canvas_single.o: includes/primitive/disk.h
./obj/render_on_canvas_single.o: includes/primitive/cuboid.h
./obj/render_on_canvas_single.o: includes/material/material.h
./obj/render_on_canvas_single.o: includes/texture/texture.h
./obj/render_on_canvas_single.o: includes/array_light/array_light.h
./obj/render_on_canvas_single.o: includes/light/light.h
./obj/render_on_canvas_single.o: includes/light/point_light.h
./obj/render_on_canvas_single.o: includes/light/directional_light.h
./obj/render_on_canvas_single.o: includes/light/spotlight_light.h
./obj/render_on_canvas_single.o: includes/canvas/canvas.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/render_on_canvas_single.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/render_on_canvas_single.o: includes/options/options.h
./obj/render_on_canvas_single.o: includes/color/color.h
./obj/render_on_canvas_single.o: includes/raytracing/raytracing.h
./obj/render_on_canvas_single.o: includes/filter/filter.h
./obj/render_on_canvas_with_stereoscopy.o: includes/render/render.h
./obj/render_on_canvas_with_stereoscopy.o: includes/scene/scene.h
./obj/render_on_canvas_with_stereoscopy.o: includes/camera/camera.h
./obj/render_on_canvas_with_stereoscopy.o: includes/vect3d/vect3d.h
./obj/render_on_canvas_with_stereoscopy.o: includes/basis/basis.h
./obj/render_on_canvas_with_stereoscopy.o: includes/array_object/array_object.h
./obj/render_on_canvas_with_stereoscopy.o: includes/object/object.h
./obj/render_on_canvas_with_stereoscopy.o: includes/shape/shape.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/primitive.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/sphere.h
./obj/render_on_canvas_with_stereoscopy.o: includes/raytracing/ray.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/cylinder.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/cone.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/plane.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/torus.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/paraboloid.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/rect.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/disk.h
./obj/render_on_canvas_with_stereoscopy.o: includes/primitive/cuboid.h
./obj/render_on_canvas_with_stereoscopy.o: includes/material/material.h
./obj/render_on_canvas_with_stereoscopy.o: includes/texture/texture.h
./obj/render_on_canvas_with_stereoscopy.o: includes/array_light/array_light.h
./obj/render_on_canvas_with_stereoscopy.o: includes/light/light.h
./obj/render_on_canvas_with_stereoscopy.o: includes/light/point_light.h
./obj/render_on_canvas_with_stereoscopy.o: includes/light/directional_light.h
./obj/render_on_canvas_with_stereoscopy.o: includes/light/spotlight_light.h
./obj/render_on_canvas_with_stereoscopy.o: includes/canvas/canvas.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/render_on_canvas_with_stereoscopy.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/render_on_canvas_with_stereoscopy.o: includes/color/color.h
./obj/scene.o: includes/scene/scene.h includes/camera/camera.h
./obj/scene.o: includes/vect3d/vect3d.h includes/basis/basis.h
./obj/scene.o: includes/array_object/array_object.h
./obj/scene.o: includes/object/object.h includes/shape/shape.h
./obj/scene.o: includes/primitive/primitive.h
./obj/scene.o: includes/primitive/sphere.h includes/raytracing/ray.h
./obj/scene.o: includes/primitive/cylinder.h includes/primitive/cone.h
./obj/scene.o: includes/primitive/plane.h includes/primitive/torus.h
./obj/scene.o: includes/primitive/paraboloid.h includes/primitive/rect.h
./obj/scene.o: includes/primitive/disk.h includes/primitive/cuboid.h
./obj/scene.o: includes/material/material.h includes/texture/texture.h
./obj/scene.o: includes/array_light/array_light.h includes/light/light.h
./obj/scene.o: includes/light/point_light.h
./obj/scene.o: includes/light/directional_light.h
./obj/scene.o: includes/light/spotlight_light.h
./obj/technical_effect_make_screenshot.o: includes/technical_effect/technical_effect.h
./obj/technical_effect_make_screenshot.o: includes/canvas/canvas.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2_image/sdl2_image_includes/SDL_image.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2_image/SDL2/SDL.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2_image/SDL2/SDL_version.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2_image/SDL2/begin_code.h
./obj/technical_effect_make_screenshot.o: ./external/link/sdl2_image/SDL2/close_code.h
./obj/technical_effect_make_screenshot.o: ./external/link/libft/libft_includes/libft.h
./obj/technical_effect_make_screenshot.o: ./external/link/libft/libft_includes/get_next_line.h
./obj/texture_load.o: includes/texture/texture.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_main.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_stdinc.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_config.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_platform.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/begin_code.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/close_code.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_assert.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_atomic.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_audio.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_error.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_endian.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_mutex.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_thread.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_rwops.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_clipboard.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_cpuinfo.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_events.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_video.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_pixels.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_rect.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_surface.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_blendmode.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_keyboard.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_keycode.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_scancode.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_mouse.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_joystick.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_gamecontroller.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_quit.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_gesture.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_touch.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_filesystem.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_haptic.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_hints.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_loadso.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_log.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_messagebox.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_power.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_render.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_shape.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_system.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_timer.h
./obj/texture_load.o: ./external/link/sdl2/sdl2_includes/SDL_version.h
./obj/texture_load.o: ./external/link/sdl2_image/sdl2_image_includes/SDL_image.h
./obj/texture_load.o: ./external/link/sdl2_image/SDL2/SDL.h
./obj/texture_load.o: ./external/link/sdl2_image/SDL2/SDL_version.h
./obj/texture_load.o: ./external/link/sdl2_image/SDL2/begin_code.h
./obj/texture_load.o: ./external/link/sdl2_image/SDL2/close_code.h
./obj/texture_load.o: ./external/link/libft/libft_includes/libft.h
./obj/texture_load.o: ./external/link/libft/libft_includes/get_next_line.h
./obj/vect3d.o: includes/vect3d/vect3d.h
./obj/vect3d_clamp.o: includes/vect3d/vect3d.h includes/mmath/mmath.h
./obj/vect3d_cos.o: includes/vect3d/vect3d.h
./obj/vect3d_cos_normed.o: includes/vect3d/vect3d.h
./obj/vect3d_cross.o: includes/vect3d/vect3d.h
./obj/vect3d_div_on_scalar.o: includes/vect3d/vect3d.h
./obj/vect3d_dot.o: includes/vect3d/vect3d.h
./obj/vect3d_fill_rotate_matrix.o: includes/vect3d/vect3d.h
./obj/vect3d_from_scalar.o: includes/vect3d/vect3d.h
./obj/vect3d_fst_closer_snd_to.o: includes/vect3d/vect3d.h
./obj/vect3d_inf.o: includes/vect3d/vect3d.h
./obj/vect3d_is_equal.o: includes/vect3d/vect3d.h
./obj/vect3d_is_in_range.o: includes/vect3d/vect3d.h
./obj/vect3d_is_in_range_abs.o: includes/vect3d/vect3d.h
./obj/vect3d_len.o: includes/vect3d/vect3d.h
./obj/vect3d_mult_on_matrix.o: includes/vect3d/vect3d.h
./obj/vect3d_mult_on_scalar.o: includes/vect3d/vect3d.h
./obj/vect3d_norm.o: includes/vect3d/vect3d.h
./obj/vect3d_reflect.o: includes/vect3d/vect3d.h
./obj/vect3d_rotate_around_axis.o: includes/vect3d/vect3d.h
./obj/vect3d_sq_len.o: includes/vect3d/vect3d.h
