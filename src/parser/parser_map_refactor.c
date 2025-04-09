/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_refactor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:27:14 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:27:14 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static	char	**fill_new_map(t_map *map, char **new_grid)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y] && (check_line(map->grid[y], NULL)
			|| map->grid[y][0] != '\0'))
	{
		x = 0;
		while (map->grid[y][x])
		{
			new_grid[y][x] = map->grid[y][x];
			x++;
		}
		while (x < map->width)
		{
			new_grid[y][x] = ' ';
			x++;
		}
		new_grid[y][map->width] = '\0';
		y++;
	}
	gfree_arr((void **)map->grid);
	return (new_grid);
}

void	map_refactor(t_map *map)
{
	char	**new_grid;
	int		y;

	if (!map->grid)
		terminate_error("Error: Map not found");
	map->height = calc_height(map->grid);
	map->width = calc_width(map->grid);
	if (map->width < 3 && map->height < 3)
		terminate_error("Error: Map very little");
	new_grid = galloc((map->height + 1) * sizeof(char *));
	y = 0;
	while (map->height > y)
	{
		new_grid[y] = galloc((map->width + 1) * sizeof(char));
		new_grid[y][map->width] = '\0';
		y++;
	}
	new_grid[y] = NULL;
	map->grid = fill_new_map(map, new_grid);
}
