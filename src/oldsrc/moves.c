/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:55:44 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/03 23:41:34 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"

int		is_grid_collision(int x, int y, t_map *map)
{
	if (y >= 1 &&
		x >= 1)
	{
		if (map->grid[x][y] == '1')
			return (1);
	}
	else
		return (1);
	return (0);
}

/*
int		is_collision_borders(double x, double y, t_params *params)
{
	int	cell_floor[2];
	int	cell_ceil[2];
	double	cell_size;

	cell_size = params->mlx->width / params->map->width;
	cell_floor[0] = (int)floor(x / cell_size);
	cell_floor[1] = (int)floor(y / cell_size);
	cell_ceil[0] = (int)ceil(x / cell_size);
	cell_ceil[1] = (int)ceil(y / cell_size);
	//printf("Curr cell floor: x:%d y:%d\n", cell_floor[0], cell_floor[1]);
	//printf("Curr cell ceil: x:%d y:%d\n", cell_ceil[0], cell_ceil[1]);
	if (is_grid_collision(cell_floor[0], cell_floor[1], params->map) ||
		is_grid_collision(cell_ceil[0], cell_floor[1], params->map) ||
		is_grid_collision(cell_floor[0], cell_ceil[1], params->map) ||
		is_grid_collision(cell_ceil[0], cell_ceil[1], params->map))
		return (1);
	return (0);
}

int		is_collision(double x, double y, t_params *params)
{
	int cell_round[2];

	//printf("map width: %d map height: %d\n", params->map->width, params->map->height);
	cell_round[0] = (int)round(x / params->tile_size);
	cell_round[1] = (int)round(y / params->tile_size);
	//printf("Curr cell: x:%d y:%d\n", cell_round[0], cell_round[1]);
	if (is_grid_collision(cell_round[0], cell_round[1], params->map))
		return (1);
	return (0);
}

void	move_player(int x_offset, int y_offset, t_player *player, t_params *params)
{
	t_coords	pos;
	//t_coords	p1;
	//t_coords	p2;

	//printf("Player: x: %f y: %f\n", params->player->x , params->player->y);
	pos.x = player->x + x_offset;
	pos.y = player->y + y_offset;
	if (is_collision(pos.x, pos.y, params))
		return ;
	player->x = pos.x;
	player->y = pos.y;
	draw_minimap(params);
	draw_square(params->img, pos, params->tile_size, player->color);
	// Test lines
	//p1.x = 1;
	//p1.y = 2;
	//p2.x = 20;
	//p2.y = 30;
	//draw_line(params->img, p1, p2, player->color);
	raycaster(params);
	add_image_mlx(0, 0, params->img, params);
}
*/
