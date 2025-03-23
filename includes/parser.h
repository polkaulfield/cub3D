#ifndef PARSER_H
# define PARSER_H

# include "galloc.h"
# include "get_next_line.h"
#include "../libs/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define Y 0
# define X 1

typedef struct s_map
{
	char	*file_name;
	int		fd_file;
	char	player_direction;
	int		x_player;
	int		y_player;
	char	**grid;
	int		height;
	int		width;
	char	*texture[5];
	int		floor[3];
	int		ceiling[3];
}	t_map;

//	init_map.c
t_map	*init_map(char *file);

//		parser.c
t_map	*parser(char *file);

//	parser_checkers.c
int		texture_check(char *line);
int		color_check(char *line);
int		check_line(char *line, int *spaces_count);
int		check_char(t_map *map, int x, int y);
void	check_player(t_map *map);

//parser_file.c
void	check_file_name(char *file_name); // need move no enough space in the other file
void	open_file(t_map *map);
//static void	read_all_file(char *line, t_map *map);
void	read_file(t_map *map);

//	parser_map.c
int		open_map(t_map *map, int x, int y);
void	player_pos(t_map *map, int x, int y, char c);
void	map_parser(t_map *map);

//map_refactor.c
//static	void	fill_new_map_extend(t_map *map,
	//char **new_grid, int *y_x, int *n_y_x)
//static char	**fill_new_map(t_map *map, char **new_grid);
void	map_refactor(t_map *map);

//parser_map_struct.c
void	color_parser(char *line, t_map *map);
void	texture_parser(char *line, t_map *map);
//static void	check_maps_args_extend(int *floor_ceiling);
void	check_maps_args(t_map *map);

//parser_utils.c
int		calc_height(char **grid);
int		calc_width(char **grid);
int 	char_in_set(char c, char *set);
char	**dynamic_arr(char **arr, char *line);


#endif
