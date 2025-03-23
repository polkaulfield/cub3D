/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:55:44 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/20 23:42:23 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"
#include "../includes/cub3d.h"

int		is_grid_collision(int x, int y, t_map *map)
{
	if (x <= map->map_width && y >= 1 &&
		x >= 1 && y <= map->map_width)
	{
		if (map->grid[x][y] == '1')
			return (1);
	}
	else
		return (1);
	return (0);
}

int		is_collision(double x, double y, t_params *params)
{
	int	cell_floor[2];
	int	cell_ceil[2];
	double	cell_size;

	cell_size = params->mlx->width / params->map->map_width;
	cell_floor[0] = (int)floor(x / cell_size);
	cell_floor[1] = (int)floor(y / cell_size);
	cell_ceil[0] = (int)ceil(x / cell_size);
	cell_ceil[1] = (int)ceil(y / cell_size);
	printf("Curr cell floor: x:%d y:%d\n", cell_floor[0], cell_floor[1]);
	printf("Curr cell ceil: x:%d y:%d\n", cell_ceil[0], cell_ceil[1]);
	if (is_grid_collision(cell_floor[0], cell_floor[1], params->map) ||
		is_grid_collision(cell_ceil[0], cell_floor[1], params->map) ||
		is_grid_collision(cell_floor[0], cell_ceil[1], params->map) ||
		is_grid_collision(cell_ceil[0], cell_ceil[1], params->map))
		return (1);
	return (0);
}
/*
int		is_collision(double x, double y, t_params *params)
{
	int cell_round[2];
	double	cell_size;

	cell_size = params->mlx->width / params->map->map_width;
	printf("map width: %d map height: %d\n", params->map->map_width, params->map->map_height);
	cell_round[0] = (int)round(x / cell_size);
	cell_round[1] = (int)round(y / cell_size);
	printf("Curr cell: x:%d y:%d\n", cell_round[0], cell_round[1]);
	if (is_grid_collision(cell_round[0], cell_round[1], params->map))
		return (1);
	return (0);
}
*/

void	move_player(int x, int y, t_player *player, t_params *params)
{
	if (is_collision(x, y, params))
		return ;
	player->x = x;
	player->y = y;
	if (player->img)
		mlx_delete_image(params->mlx, player->img);
	player->img = init_simple_image(params->tile_size, params->tile_size, player->color, params);
	add_image_mlx(x, y, player->img, params);
}
