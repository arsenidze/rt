# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelihov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 18:37:28 by amelihov          #+#    #+#              #
#    Updated: 2018/06/15 21:37:40 by amelihov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = ./srcs
OBJ_DIR = ./obj
INC_DIR = ./includes

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_memset.c \
	  ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	  ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
	  ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	  ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_swap_int.c \
		ft_swap_str.c \
	  	ft_arr_map.c \
		ft_arr_foreach.c \
		ft_arr_filter.c \
		ft_max.c \
		ft_min.c \
	  	print_bits.c \
		get_next_line.c \
	   	read_file.c \
		free_strs.c \
		ret_free.c \
		is_number.c \
		atoi_base.c \
		ft_abs.c \
		ft_sign.c \
		list_strs_del.c \
		ft_get_size_of_str_arr.c \
	
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC = $(INC_DIR)/libft.h $(INC_DIR)/get_next_line.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
HFLAGS = -I $(INC_DIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf $(OBJ_DIR)

re: fclean all
