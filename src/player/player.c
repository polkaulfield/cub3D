/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:02:01 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 00:41:09 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

int	is_grid_collision(int x, int y, t_map *map)
{
	if (y >= 1 && x >= 1)
	{
		if (map->grid[x][y] == '1')
			return (1);
	}
	else
		return (1);
	return (0);
}

static float	get_angle_nsew(char direction)
{
	if (direction == 'E')
		return (270);
	if (direction == 'W')
		return (90);
	if (direction == 'N')
		return (180);
	if (direction == 'S')
		return (0);
	return (-1);
}

t_player	*init_player(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos.x = map->x_player;
	player->pos.y = map->y_player;
	player->angle = deg2rad(get_angle_nsew(map->player_direction));
	player->start_angle = player->angle - HALF_FOV;
	return (player);
}
