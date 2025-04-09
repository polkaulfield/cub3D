/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:27:16 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:28:02 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	color_parser(char *line, t_map *map)
{
	int		i;
	char	**line_splited;
	int		*number_arr;

	i = 1;
	while (line[i] == ' ')
		i++;
	line_splited = add_galloc_arr((void **)ft_split(&line[i], ','));
	while (line[i])
	{
		if (line[i] != ' ' && !ft_isdigit(line[i]) && line[i] != ',')
			terminate_error("Error: Ceiling or Floor wrong arguments");
		i++;
	}
	if (color_check(line) == 1)
		number_arr = map->floor;
	else
		number_arr = map->ceiling;
	if (!line_splited[0] || !line_splited[1]
		|| !line_splited[2] || line_splited[3])
		terminate_error("Error: Ceiling or Floor not 3 numbers found");
	number_arr[0] = ft_atoi(add_galloc(ft_strtrim(line_splited[0], " ")));
	number_arr[1] = ft_atoi(add_galloc(ft_strtrim(line_splited[1], " ")));
	number_arr[2] = ft_atoi(add_galloc(ft_strtrim(line_splited[2], " ")));
}

void	texture_parser(char *line, t_map *map)
{
	int	i;
	int	fd;

	if (ft_strncmp(ft_strrchr(line, '.'), ".png", 5) != 0)
		terminate_error("Error: Wrong file extension");
	i = 2;
	while (line[i] == ' ')
		i++;
	if (map->texture[texture_check(line) - 1] != NULL)
		terminate_error("Error: Found a duplicated texture direction");
	map->texture[texture_check(line) - 1] = add_galloc(ft_strdup(&line[i]));
	fd = open(map->texture[texture_check(line) - 1], O_RDONLY);
	if (fd == -1)
		terminate_error("Error: Can't open the file texture");
	close(fd);
}

static void	check_maps_args_extend(int *floor_ceiling)
{
	int	i;

	i = 0;
	while (i < 3 && floor_ceiling[i] != -1)
	{
		if (floor_ceiling[i] >= 256)
			terminate_error("Error: Wrong floor number");
		i++;
	}
	if (i != 3)
		terminate_error("Error: Not found 3 number in ceiling");
}

//check if is the map struct is complete
void	check_maps_args(t_map *map)
{
	int	i;

	i = -1;
	while (map->texture[++i])
		;
	if (i != 4)
		terminate_error("Error: Not found 4 textures");
	check_maps_args_extend(map->floor);
	check_maps_args_extend(map->ceiling);
}
//check if direction repeat in texture string
