# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburri <rburri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 08:06:22 by rburri            #+#    #+#              #
#    Updated: 2022/02/03 11:51:52 by rburri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################################################
# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
####################################################################
CC = gcc 

NAME = fdf

FLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR	= libft
LIBFT_A		= libft.a
LIBFT		= -L. -lft

MLX_DIR		= mlx
MLX_A		= libmlx.a
MLX			= -L. -lmlx -framework OpenGL -framework AppKit

SRC = fdf_src

BIN = bin

SOURCE =  $(SRC)/main.c\
			$(SRC)/init.c\
			$(SRC)/key_hook.c\
			$(SRC)/utils.c\
			$(SRC)/drawing.c\
			$(SRC)/read_map.c\
			$(SRC)/stack_to_coods_array.c\
			$(SRC)/project.c\
			$(SRC)/free.c\
			
			
		
OBJS = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.o)))

$(BIN)/%.o : $(SRC)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)


help: 
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJS)"

${NAME}:	${OBJS}
			@make -C ${LIBFT_DIR}/
			@cp ${LIBFT_DIR}/$(LIBFT_A) .
			@make -C ${MLX_DIR}/
			@cp ${MLX_DIR}/$(MLX_A) .
			$(CC)  ${OBJS} $(LIBFT) $(MLX) -o $(NAME)
			@echo "$(GREEN)$(NAME) sucessfully created$(RESET)"

clean:
		@rm -f $(OBJS)
		make -C ${LIBFT_DIR} fclean
		make -C ${MLX_DIR} clean

fclean: clean
		@rm -f $(NAME)
		@rm -f $(MLX_A)
		@rm -f $(LIBFT_A)
	
re: fclean all

.PHONY: fclean re all clean bonus
