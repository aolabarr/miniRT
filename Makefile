# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 15:23:12 by aolabarr          #+#    #+#              #
#    Updated: 2025/03/16 15:46:49 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror -g3 -pedantic -g
SFLAGS =  -fsanitize=address

OBJ_DIR = ./obj
SRC_DIR = ./src

INC_DIR = .
LIBFT_DIR = ./lib/libft
LIBIO_DIR = ./lib/libio
LIBMLX_DIR = ./lib/libmlx
MATH_DIR = /usr/local/lib

LIBFLAGS = -L$(LIBFT_DIR) -lft -L$(LIBIO_DIR) -lio -L$(LIBMLX_DIR) -lmlx_Linux -L$(MATH_DIR) -lm -lX11 -lXext

SRC =	main.c \
		aux.c \
		libx.c \
		render.c \
		keys.c \
		init.c \
		get_data.c \
		check_values.c \
		raytracing.c \
		free.c \
		parse.c \
		math_1.c \
		math_2.c \
		color.c \
		matrix_1.c \
		matrix_2.c \
		intersection.c \
		
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBIO_DIR)
	@if [ ! -d $(LIBMLX_DIR) ]; then \
		cd lib; \
		tar -xvzf minilibx-linux.tgz; \
		mv minilibx-linux libmlx; \
		cd ..; \
	fi
	make -C $(LIBMLX_DIR)


fclean: clean
	rm -f $(NAME) a.out
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBIO_DIR)
	make clean -C $(LIBMLX_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBIO_DIR)

re: fclean all

.PHONY: all fclean clean re lib

#.SILENT: