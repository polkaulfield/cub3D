/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:02:01 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/04 22:31:46 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

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

static double	get_angle_nsew(char direction)
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

t_dpoint	get_next_pos(double h, double angle, t_dpoint pos)
{
	pos.y += cos(angle) * h;
	pos.x -= sin(angle) * h;
	return (pos);
}

double	add_angle(double angle, double increment)
{
	angle += increment;
	while (angle < 0)
		angle += TWOPI;
	while (angle >= TWOPI)
		angle -= TWOPI;
	return (angle);
}

void	move_player(int key, t_player *player, double len, t_args *args)
{
	t_dpoint	dpoint;

	dpoint.x = 0;
	if (key == UP || key == W)
		dpoint = get_next_pos(len, player->angle, player->pos);
	else if (key == DOWN || key == S)
		dpoint = get_next_pos(len, player->angle, player->pos);
	else if (key == D || key == A)
		dpoint = get_next_pos(len, player->angle + 1.5708, player->pos);
	else if (key == RIGHT)
		player->angle = add_angle(player->angle, len);
	else if (key == LEFT)
		player->angle = add_angle(player->angle, len);
	else
		return ;
	if (dpoint.x != 0 && !is_grid_collision((int)roundf(dpoint.x), (int)roundf(dpoint.y), args->map))
		player->pos = dpoint;
}

void	render(t_args *args)
{
	raycaster(args);
}
