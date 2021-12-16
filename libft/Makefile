# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburri <rburri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:29:27 by rburri            #+#    #+#              #
#    Updated: 2021/11/05 12:02:16 by rburri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = 	ft_atoi.c ft_isspace.c ft_putchar.c ft_putnbr.c ft_putstr.c \
			ft_bzero.c ft_strcat ft_strcmp.c ft_strcpy.c ft_strncpy.c \
			ft_calloc.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
			ft_isalnum.c ft_putchar_fd.c ft_split.c ft_strmapi.c \
			ft_isalpha.c ft_striteri.c ft_itoa.c ft_substr.c \
			ft_isascii.c ft_toupper.c ft_tolower.c ft_strjoin.c \
			ft_isdigit.c ft_strtrim.c ft_strrchr.c ft_strnstr.c \
			ft_isprint.c ft_strncmp.c ft_strlen.c ft_strlcpy.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \

			
OBJECTS =	$(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc -c $(FLAGS)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc libft.a $(OBJECTS)

%.o: %.c
	$(CC) $< -o $@ 
	
clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f  $(NAME)

re: fclean all

.PHONY:	all clean fclean re