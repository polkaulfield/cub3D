/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:27:12 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:27:12 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/get_next_line.h"

void	check_file_name(char *file_name)
{
	int	i;

	i = -1;
	while (file_name[++i])
	{
		if (file_name[i] == ' ')
			terminate_error("Error: File name not accepted");
	}
	if (!ft_strrchr(file_name, '.') || (ft_strrchr(file_name, '.')
			&& ft_strncmp(ft_strrchr(file_name, '.'), ".cub", 5) != 0))
		terminate_error("Error: Wrong file extension");
}

void	open_file(t_map *map)
{
	check_file_name(map->file_name);
	map->fd_file = open(map->file_name, O_RDONLY);
	if (map->fd_file == -1)
		terminate_error("Error: Can't open file");
}

static void	read_all_file(char *line, t_map *map)
{
	if (!line)
		terminate_error("Error: Map not found");
	line = ft_strdup(line);
	add_galloc(line);
	while (line && *line)
	{
		line = add_galloc(ft_strtrim(line, "\n"));
		map->grid = dynamic_arr(map->grid, line);
		gfree(line);
		line = get_next_line(map->fd_file);
		add_galloc(line);
	}
	close(map->fd_file);
}

void	read_file(t_map *map)
{
	char	*line;
	int		i;

	while (true)
	{
		i = 0;
		line = get_next_line(map->fd_file);
		add_galloc(line);
		if (!line)
			break ;
		if (line[0] == '\n' || check_line(line, &i))
			continue ;
		line = add_galloc(ft_strtrim(line, "\n"));
		if (texture_check(&line[i]))
			texture_parser(&line[i], map);
		else if (ft_strncmp(&line[i], "F ", 2) == 0
			|| ft_strncmp(&line[i], "C ", 2) == 0)
			color_parser(&line[i], map);
		else
			break ;
		gfree(line);
	}
	check_maps_args(map);
	read_all_file(line, map);
}
