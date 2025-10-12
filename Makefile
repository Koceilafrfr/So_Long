NAME = so_long

RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
BLUE			= \e[34m
MAGENTA			= \e[35m
CYAN			= \e[36m
RESET			= \e[m

SRC_DIR = srcs/

GNL = $(GNL_DIR)/get_next_line.a
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = \
	$(SRC_DIR)/so_long.c \ga
	$(SRC_DIR)/setup/setup.c \
	$(SRC_DIR)/setup/setup2.c \
	$(SRC_DIR)/setup/moves.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/parsing/more_pars.c \
	$(SRC_DIR)/parsing/even_more_pars.c \
	$(SRC_DIR)/parsing/too_much_pars.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c
OBJS = $(SRCS:%.c=build/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

MLX_DIR = mlx/
MLX_LIB = mlx/libmlx_$(shell uname).a

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIB) $(GNL)
	@echo "$(GREEN)Linking $@$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS) 
	@echo "$(GREEN)Build complete$(NO_COLOR)"


$(OBJS): | build

build:
	@mkdir -p build

build/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<$(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@echo "$(RED)Cleaning object files$(NO_COLOR)"
	@rm -rf build

fclean: clean
	@echo "$(RED)Cleaning executable$(NO_COLOR)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 

