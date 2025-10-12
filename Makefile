# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/12 19:50:57 by yzidani           #+#    #+#              #
#    Updated: 2025/10/12 19:51:02 by yzidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Iprintf -Iminilibx-linux

LIBFT_DIR = libft
PRINTF_DIR = printf
MLX_DIR = minilibx-linux
SRC_DIR = srcs
OBJ_DIR = obj

# === Source files ===

SRCS = \
	$(SRC_DIR)/so_long.c \
	$(SRC_DIR)/setup/setup.c \
	$(SRC_DIR)/setup/setup2.c \
	$(SRC_DIR)/setup/moves.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/parsing/more_pars.c \
	$(SRC_DIR)/parsing/even_more_pars.c \
	$(SRC_DIR)/parsing/too_much_pars.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c

# === Object files ===

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# === Libraries ===

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11

# === Rules ===

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# === Compilation of object files with folder creation ===

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# === Clean rules ===

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
