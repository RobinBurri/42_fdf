CC = gcc 

NAME = fdf

FLAGS = -Wall -Wextra -Werror -g

SRCS = ${wildcard *.c}

OBJS = ${SRCS:.c=.o}

all: $(NAME)

LIBFT_DIR	= libft
LIBFT_A		= libft.a
LIBFT		= -L. -lft

MLX_DIR		= mlx
MLX_A		= libmlx.a
MLX			= -L. -lmlx -framework OpenGL -framework AppKit 

.c.o:	
			${CC} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}/
			cp ${LIBFT_DIR}/$(LIBFT_A) .
			make -C ${MLX_DIR}/
			cp ${MLX_DIR}/$(MLX_A) .
			$(CC) -o $(NAME) ${OBJS} $(LIBFT) $(MLX)

clean:
		@rm -f $(OBJS)
		make -C ${LIBFT_DIR} fclean
		make -C ${MLX_DIR} clean

fclean: clean
		@rm -f $(NAME)
	
re: fclean all

.PHONY: fclean re all clean bonus
