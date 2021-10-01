# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olgerret <olgerret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 13:34:53 by olgerret          #+#    #+#              #
#    Updated: 2021/08/27 15:28:07 by olgerret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft_so_long.a

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -Lmlx -framework OpenGL -framework AppKit

SRC = ft_so_long.c \
	ft_error_checker.c \
	ft_get_next_line.c \
	ft_array_functions.c \
	ft_free_functions.c \
	ft_window_fillers.c \
	ft_move_player.c \

all: $(NAME)

$(NAME): *.c
	Make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	$(CC) $(FLAGS) -L. -lft_so_long ./mlx/libmlx.a $(MLX) ft_so_long.c -o so_long

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean $(NAME)
