# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cscache <cscache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 09:47:02 by cscache           #+#    #+#              #
#    Updated: 2025/07/03 15:48:04 by cscache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx-linux
MLX = $(MLX_DIR)/libmlx.a

INCLUDES = -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)
HEADER = includes/so_long.h

NAME = so_long

OBJS_DIR = obj

SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/check_file.c \
		$(SRCS_DIR)/check_elements.c \
		$(SRCS_DIR)/check_constraints_1.c \
		$(SRCS_DIR)/check_constraints_2.c \
		$(SRCS_DIR)/init_grid.c \
		$(SRCS_DIR)/init_win.c \
		$(SRCS_DIR)/init_imgs.c \
		$(SRCS_DIR)/display_move_count.c \
		$(SRCS_DIR)/display_game.c \
		$(SRCS_DIR)/manage_game.c \
		$(SRCS_DIR)/run_game.c \
		$(SRCS_DIR)/free.c \
		$(SRCS_DIR)/b_create_enemy_utils.c \
		$(SRCS_DIR)/b_create_enemy.c \
		$(SRCS_DIR)/b_move_enemy_utils.c \
		$(SRCS_DIR)/b_move_enemy.c

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re