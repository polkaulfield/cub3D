CC		:= gcc
NAME	:= cub3d
CFLAGS	:= -g -Wextra -Wall -Werror -Ofast -ffast-math -march=native #-fsanitize=address
LIBMLX	:= ./libs/MLX42
LIBFT	:= ./libs/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= -L $(LIBFT) -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= ./src/main.c \
			./src/color.c \
			./src/args.c \
			./src/errors.c \
			./src/player.c \
			./src/tests.c \
			./src/minimap.c \
			./src/drawing/circles.c \
			./src/drawing/lines.c \
			./src/drawing/rectangles.c \
			./src/parser/init_map.c \
			./src/parser/parser.c \
			./src/parser/parser_checkers.c \
			./src/parser/parser_file.c \
			./src/parser/parser_map.c \
			./src/parser/parser_map_refactor.c \
			./src/parser/parser_map_struct.c \
			./src/parser/parser_utils.c \
			./src/galloc/galloc.c \
			./src/galloc/galloc_utils.c \
			./src/galloc/init_galloc.c \
			./src/get_next_line/get_next_line.c \
			./src/get_next_line/get_next_line_utils.c


OBJS	:= ${SRCS:.c=.o}

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

.PHONY: all, clean, fclean, re, libmlx
