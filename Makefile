CC		:= gcc
NAME	:= cub3d
CFLAGS	:= -g -Wextra -Wall -Werror -Ofast -march=native -ffast-math #-fsanitize=address
LIBMLX	:= ./libs/MLX42
LIBFT	:= ./libs/libft

INCLUDE_DIR := ./include
SRC_DIR := ./src
LIBMLX_INC := $(LIBMLX)/include
LIBMLX_LIB := $(LIBMLX)/build/libmlx42.a
LIBFT_LIB := $(LIBFT)
LIBFT_INC := $(LIBFT)/includes

HEADERS	:= -I $(INCLUDE_DIR) -I $(LIBMLX_INC) -I $(LIBFT_INC)
LIBS	:= -L $(LIBFT_LIB) -lft $(LIBMLX_LIB) -ldl -lglfw -pthread -lm

SRC_MAIN_DIR := $(SRC_DIR)
SRC_DRAWING_DIR := $(SRC_DIR)/drawing
SRC_PARSER_DIR := $(SRC_DIR)/parser
SRC_GALLOC_DIR := $(SRC_DIR)/galloc
SRC_GNL_DIR := $(SRC_DIR)/get_next_line

SRCS := $(wildcard $(SRC_MAIN_DIR)/*.c) \
        $(wildcard $(SRC_DRAWING_DIR)/*.c) \
        $(wildcard $(SRC_PARSER_DIR)/*.c) \
        $(wildcard $(SRC_GALLOC_DIR)/*.c) \
        $(wildcard $(SRC_GNL_DIR)/*.c)

OBJS := ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j$(nproc)

libft:
	@make -s -C $(LIBFT)

%.o: %.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -s -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -s -C $(LIBFT) fclean

re: clean all

.PHONY: all clean fclean re libmlx
