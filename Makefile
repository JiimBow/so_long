# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 10:31:35 by jodone            #+#    #+#              #
#    Updated: 2025/11/12 14:54:22 by jodone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=so_long

MLX_DIR= mlx/
SRC_DIR= src/

SRC= $(SRC_DIR)main.c \
	$(SRC_DIR)load_map.c \
	$(SRC_DIR)map_init.c \
	$(SRC_DIR)player_pos.c \
	$(SRC_DIR)player_move.c

INCLUDES=-I include \
		-I Great_Libft/Libft \
		-I Great_Libft/ft_printf \
		-I Great_Libft/GNL \
		-I $(MLX_DIR)includes

OBJECT=$(SRC:.c=.o)
LIBFT= ./Great_Libft/g_libft.a
CFLAGS=-Wall -Wextra -Werror -g $(LIBFT) $(MLX_DIR)libmlx.so -lSDL2

all: $(NAME)

$(NAME): $(MLX_DIR)libmlx.so $(OBJECT) $(LIBFT)
		$(CC) $(OBJECT) $(CFLAGS) -o $(NAME)

$(LIBFT):
		$(MAKE) -C Great_Libft

%.o: %.c
		$(CC) $(INCLUDES) -c $< -o $@

$(MLX_DIR)libmlx.so:
		git clone https://github.com/seekrs/MacroLibX.git -b v2.2.2 mlx
		$(MAKE) -C mlx -j

clean:
		rm -f $(OBJECT)
		$(MAKE) -C Great_Libft clean

fclean: clean
		rm -f $(NAME)
		rm -rf $(MLX_DIR)
		$(MAKE) -C Great_Libft fclean
		
re: fclean all

.PHONY: all clean fclean re