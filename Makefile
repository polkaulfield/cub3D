CC      := clang
NAME    := cub3d
CFLAGS  := -Wall -Werror -Wextra -O3 -ffast-math -fsanitize=address

LIBMLX  := ./libs/MLX42
LIBFT   := ./libs/libft

INCLUDE_DIR := ./include
SRC_DIR := ./src/
LIBMLX_INC := $(LIBMLX)/include
LIBMLX_LIB := $(LIBMLX)/build/libmlx42.a
LIBFT_LIB := $(LIBFT)
LIBFT_INC := $(LIBFT)/includes

HEADERS := -I $(INCLUDE_DIR) -I $(LIBMLX_INC) -I $(LIBFT_INC)
LIBS    := -L $(LIBFT_LIB) -lft $(LIBMLX_LIB) -ldl -lglfw -pthread -lm

SRCS := src/get_next_line/get_next_line_utils.c\
		src/get_next_line/get_next_line.c\
		src/galloc/galloc.c\
		src/galloc/galloc_utils.c\
		src/galloc/init_galloc.c\
		src/minimap.c\
		src/parser/init_map.c\
		src/parser/parser_checkers.c\
		src/parser/parser_map_refactor.c\
		src/parser/parser.c\
		src/parser/parser_utils.c\
		src/parser/parser_file.c\
		src/parser/parser_map_struct.c\
		src/parser/parser_map.c\
		src/misc.c\
		src/drawing/ray.c\
		src/drawing/circles.c\
		src/drawing/rectangles.c\
		src/drawing/lines.c\
		src/raycasting/raycasting_utils.c\
		src/raycasting/raycasting.c\
		src/raycasting/textures.c\
		src/args.c\
		src/errors.c\
		src/player/player.c\
		src/player/moves.c\
		src/color.c\
		src/main.c\
		src/game.c\

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
