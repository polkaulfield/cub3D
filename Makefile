CC      := clang
NAME    := cub3d
CFLAGS  := -Wall -Werror -Wextra -O3 -ffast-math -pipe -march=native -flto

LIBMLX  := ./libs/MLX42
LIBFT   := ./libs/libft

INCLUDE_DIR := ./include
SRC_DIR := ./src
LIBMLX_INC := $(LIBMLX)/include
LIBMLX_LIB := $(LIBMLX)/build/libmlx42.a
LIBFT_LIB := $(LIBFT)
LIBFT_INC := $(LIBFT)/includes

HEADERS := -I $(INCLUDE_DIR) -I $(LIBMLX_INC) -I $(LIBFT_INC)
LIBS    := -L $(LIBFT_LIB) -lft $(LIBMLX_LIB) -ldl -lglfw -pthread -lm

SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS := $(SRCS:.c=.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j$(nproc)

libft:
	@make -s -C $(LIBFT)

%.o: %.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -s -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -s -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft