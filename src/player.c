/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:02:01 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/04 00:21:52 by pohernan         ###   ########.fr       */
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
		return (0);
	if (direction == 'W')
		return (180);
	if (direction == 'N')
		return (270);
	if (direction == 'S')
		return (90);
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
	player->angle = get_angle_nsew(map->player_direction);
	return (player);
}

t_dpoint	get_next_pos(double h, double angle, t_dpoint pos)
{
	angle = deg2rad(angle);
	pos.x += cos(angle) * h;
	pos.y += sin(angle) * h;
	//printf("New position: (%.2f, %.2f)\n", pos.x, pos.y);
	return pos;
}

double	add_angle(double angle, double increment)
{
	angle += increment;
	while (angle < 0)
		angle += 360;
	while (angle > 360)
		angle -= 360;
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
		dpoint = get_next_pos(len, player->angle + 90, player->pos);
	else if (key == RIGHT)
		player->angle = add_angle(player->angle, 10);
	else if (key == LEFT)
		player->angle = add_angle(player->angle, -10);
	else
		return ;
	if (dpoint.x != 0 && !is_grid_collision((int)roundf(dpoint.x), (int)roundf(dpoint.y), args->map))
		player->pos = dpoint;
}

void	render(t_args *args)
{
	t_point	point;

	point.x = (int)(args->player->pos.x * args->minimap->tile_size.x + args->minimap->tile_size.x / 2);
	point.y = (int)(args->player->pos.y * args->minimap->tile_size.y + args->minimap->tile_size.y / 2);
	draw_circle(args->img, point, 10, encode_rgb(255, 255, 255));
	raycaster(args->img, args);
}
