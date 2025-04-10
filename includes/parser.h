/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:44:19 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 15:47:09 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "galloc.h"
# include "get_next_line.h"
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "structs.h"
# include "misc.h"
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define Y 0
# define X 1

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
void	check_file_name(char *file_name);
void	open_file(t_map *map);
void	read_file(t_map *map);

//	parser_map.c
int		open_map(t_map *map, int x, int y);
void	player_pos(t_map *map, int x, int y, char c);
void	map_parser(t_map *map);

//map_refactor.c
void	map_refactor(t_map *map);

//parser_map_struct.c
void	color_parser(char *line, t_map *map);
void	texture_parser(char *line, t_map *map);
void	check_maps_args(t_map *map);

//parser_utils.c
int		calc_height(char **grid);
int		calc_width(char **grid);
int		char_in_set(char c, char *set);
char	**dynamic_arr(char **arr, char *line);

#endif
