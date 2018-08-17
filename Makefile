# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 13:43:11 by amelihov          #+#    #+#              #
#    Updated: 2018/08/16 20:12:29 by amelihov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

CC     = gcc
LD     = $(CC)

SRC_DIR = ./srcs
OBJ_DIR = ./obj
INC_DIR = ./includes
LIB_DIR = ./lib
FRM_DIR = ./lib/Frameworks

SRC = $(notdir $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*/*/*.c))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC = $(notdir $(wildcard $(INC_DIR)/*.h) $(wildcard $(INC_DIR)/*/*.h))

TMP_INC = $(foreach inc, $(wildcard $(INC_DIR)/*), $(addprefix -I, $(inc)))

LIBFT = $(LIB_DIR)/libft/libft.a
LIBFT_INC = $(LIB_DIR)/libft/includes/
LIBFT_FLAGS = -lft -L $(LIB_DIR)/libft/

SDL_INC 	= ./lib/Frameworks/SDL2.framework/Headers/
SDL_FLAGS	= -F ./lib/Frameworks -framework SDL2 -rpath ./lib/Frameworks

SDL_IMG_INC 	= ./lib/Frameworks/SDL2_image.framework/Headers/
SDL_IMG_FLAGS	= -F ./lib/Frameworks -framework SDL2_image -rpath ./lib/Frameworks

CFLAGS = -Wall -Wextra -Werror -g
HFLAGS = -I $(INC_DIR) -I $(LIBFT_INC) -I $(SDL_INC) -I $(SDL_IMG_INC) $(TMP_INC) -I ./lib
LFLAGS = $(LIBFT_FLAGS) $(SDL_FLAGS) $(SDL_IMG_FLAGS)

all:
	make -C $(LIB_DIR)/libft/
	make $(NAME)

$(NAME): $(OBJ) $(LIBFT) Makefile
	$(LD) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
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

r: all
	./$(NAME) scenes/scene3

re: fclean all

vpath %.c $(SRC_DIR)
vpath %.c $(SRC_DIR)/camera
vpath %.c $(SRC_DIR)/drawer
vpath %.c $(SRC_DIR)/events
vpath %.c $(SRC_DIR)/light
vpath %.c $(SRC_DIR)/mmath
vpath %.c $(SRC_DIR)/object
vpath %.c $(SRC_DIR)/parser
vpath %.c $(SRC_DIR)/primitive
vpath %.c $(SRC_DIR)/primitive/helpers
vpath %.c $(SRC_DIR)/raytracing
vpath %.c $(SRC_DIR)/scene
vpath %.c $(SRC_DIR)/vect3d
vpath %.c $(SRC_DIR)/parallelism
vpath %.c $(SRC_DIR)/basis
vpath %.c $(SRC_DIR)/filter
vpath %.c $(SRC_DIR)/err
vpath %.c $(SRC_DIR)/event
vpath %.c $(SRC_DIR)/render
vpath %.c $(SRC_DIR)/canvas
vpath %.c $(SRC_DIR)/options
vpath %.c $(SRC_DIR)/technical_effect
vpath %.c $(SRC_DIR)/texture

vpath %.h $(INC_DIR)
vpath %.h $(INC_DIR)/drawer
vpath %.h $(INC_DIR)/defines

.PHONY: all clean fclean re
