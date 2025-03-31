#include "../../includes/parser.h"

static	void	fill_new_map_extend(t_map *map,
	char **new_grid, int *y_x, int *n_y_x)
{
	while (map->grid[y_x[Y]][y_x[X]])
	{
		new_grid[n_y_x[Y]][n_y_x[X]] = map->grid[y_x[Y]][y_x[X]];
		y_x[X]++;
		n_y_x[X]++;
	}
	while (n_y_x[X] < map->width + 2)
		new_grid[n_y_x[Y]][n_y_x[X]++] = ' ';
}

static	char	**fill_new_map(t_map *map, char **new_grid)
{
	int	y_x[2];
	int	n_y_x[2];

	y_x[Y] = 0;
	n_y_x[Y] = 0;
	new_grid[n_y_x[Y]] = ft_memset(new_grid[n_y_x[0]],
			' ', map->width + 2);
	n_y_x[Y]++;
	while (map->grid[y_x[Y]] && (check_line(map->grid[y_x[Y]], NULL)
			|| map->grid[y_x[Y]][0] != '\0'))
	{
		y_x[X] = 0;
		n_y_x[X] = 0;
		new_grid[n_y_x[Y]][n_y_x[X]] = ' ';
		n_y_x[X]++;
		fill_new_map_extend(map, new_grid, y_x, n_y_x);
		y_x[Y]++;
		n_y_x[Y]++;
	}
	new_grid[n_y_x[Y]] = ft_memset(new_grid[n_y_x[Y]],
			' ', map->width + 2);
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
	new_grid = galloc((map->height + 3) * sizeof(char *));
	y = 0;
	while (map->height + 2 > y)
	{
		new_grid[y] = galloc((map->width + 3) * sizeof(char));
		new_grid[y][map->width + 2] = '\0';
		y++;
	}
	new_grid[y] = NULL;
	map->grid = fill_new_map(map, new_grid);
}
