#include "../../includes/parser.h"

char	**make_xy_grid(char **grid, int width, int height)
{
	int	x;
	int	y;
	char	**new_grid;

	new_grid = galloc(sizeof(char *) * (width + 1));
	x = 0;
	while (x < width)
	{
		y = 0;
		new_grid[x] = galloc((sizeof(char) * height) + 1);
		while (y < height)
		{
			new_grid[x][y] = grid[y][x];
			y++;
		}
		new_grid[x][y] = '\0';
		x++;
	}
	new_grid[x] = NULL;
	return (new_grid);
}

char	**map_replace(char **grid)
{
	int	y;
	int	x;

	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == ' ')
				grid[y][x] = '1';
		}
	}
	return (grid);
}

t_map	*parser(char *file)
{
	t_map	*map;
	char	**grid;

	map = init_map(file);
	open_file(map);
	read_file(map);
	map_refactor(map);
	map_parser(map);
	check_player(map);
	grid = map_replace(map->grid);
	map->height = calc_height(grid);
	map->width = calc_width(grid);
	map->grid = make_xy_grid(grid, map->width, map->height);
	//gfree_arr((void **)grid);
	return (map);
}
/*
//printf("check\n");
	//printf("%s\n", map->file_name);
	//printf("%i\n", map->fd_file);
	int i = -1;
	while (map->grid && map->grid[++i])
		//printf("%s\n", map->grid[i]);
	//printf("end map\n");
	i = -1;
	while (map->texture[++i])
		//printf("%s\n", map->texture[i]);
	//printf("%i\n", map->floor[0]);
	//printf("%i\n", map->floor[1]);
	//printf("%i\n", map->floor[2]);
	//printf("%i\n", map->ceiling[0]);
	//printf("%i\n", map->ceiling[1]);
	//printf("%i\n", map->ceiling[2]);


i = -1;
	while (map->grid && map->grid[++i])
		//printf("%s\n", map->grid[i]);
	//printf("end map\n");
*/
