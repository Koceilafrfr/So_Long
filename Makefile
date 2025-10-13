NAME = so_long

RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
BLUE			= \e[34m
MAGENTA			= \e[35m
CYAN			= \e[36m
RESET			= \e[m
NO_COLOR		= \e[m

SRC_DIR = srcs/

GNL_DIR = gnl
PRINTF_DIR = printf
LIBFT_DIR = libft

GNL = $(GNL_DIR)/get_next_line.a
PRINTF = $(PRINTF_DIR)/printf.a
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
	$(SRC_DIR)/so_long.c \
	$(SRC_DIR)/setup/setup.c \
	$(SRC_DIR)/setup/setup2.c \
	$(SRC_DIR)/setup/moves.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/parsing/more_pars.c \
	$(SRC_DIR)/parsing/even_more_pars.c \
	$(SRC_DIR)/parsing/too_much_pars.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:%.c=build/%.o)

GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:%.c=build/%.o)

LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:%.c=build/%.o)

PRINTF_SRCS = $(wildcard $(PRINTF_DIR)/*.c)
PRINTF_OBJS = $(PRINTF_SRCS:%.c=build/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx -I$(LIBFT_DIR) -I$(PRINTF_DIR)
else
	INCLUDES = -I/opt/X11/include -Imlx -I$(LIBFT_DIR) -I$(PRINTF_DIR)
endif

MLX_DIR = mlx/
MLX_LIB = mlx/libmlx_$(shell uname).a

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(GNL) $(LIBFT) $(PRINTF) $(NAME)

$(GNL): $(GNL_OBJS)
	@echo "$(CYAN)Archiving $@$(NO_COLOR)"
	@ar rcs $@ $^

$(LIBFT): $(LIBFT_OBJS)
	@echo "$(CYAN)Archiving $@$(NO_COLOR)"
	@ar rcs $@ $^

$(PRINTF): $(PRINTF_OBJS)
	@echo "$(CYAN)Archiving $@$(NO_COLOR)"
	@ar rcs $@ $^

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT) $(PRINTF) $(GNL)
	@echo "$(GREEN)Linking $@$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)
	@echo "$(GREEN)Build complete$(NO_COLOR)"

$(OBJS): | build
$(GNL_OBJS): | build
$(LIBFT_OBJS): | build
$(PRINTF_OBJS): | build

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
	@echo "$(RED)Cleaning executables and archives$(NO_COLOR)"
	@rm -f $(NAME) $(GNL) $(LIBFT) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
