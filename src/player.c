/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:02:01 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/01 20:20:51 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

static double	get_angle_nsew(char direction)
{
	if (direction == 'N')
		return (0);
	if (direction == 'S')
		return (180);
	if (direction == 'E')
		return (270);
	if (direction == 'W')
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
	if (angle <= 90)
	{
		pos.x += cos(angle) * h;
		pos.y -= sin(angle) * h;
	}
	else if (angle <= 180)
	{
		angle -= 90;
		pos.x += cos(angle) * h;
		pos.y += sin(angle) * h;
	}
	else if (angle <= 270)
	{
		angle -= 180;
		pos.x -= cos(angle) * h;
		pos.y += sin(angle) * h;
	}
	else if (angle <= 360)
	{
		angle -= 270;
		pos.x -= cos(angle) * h;
		pos.y -= sin(angle) * h;
	}
	printf("Angle: %f\n", angle);
	return (pos);
}

double	add_angle(double angle, double increment)
{
	angle += increment;
	while (angle > 360)
		angle -= 360;
	return (angle);
}

void	move_player(int key, t_player *player, double len)
{
	if (key == UP)
		player->pos = get_next_pos(len, player->angle, player->pos);
	if (key == RIGHT)
		player->angle = add_angle(player->angle, 10);
	if (key == LEFT)
		player->angle = add_angle(player->angle, -10);
}

void	draw_player_minimap(t_player *player, t_minimap *minimap, t_map *map, mlx_image_t *img)
{
	t_point	point;

	(void)map;
	printf("Player x: %d, y: %d\n", (int)player->pos.x, (int)player->pos.y);
	printf("minimap size x: %d, y: %d\n", minimap->size.x, minimap->size.y);
	point.x = minimap->size.x / (int)player->pos.x;
	point.y = minimap->size.y / (int)player->pos.y;
	printf("Point x: %d, y: %d\n", point.x, point.y);
	draw_circle(img, point, 10, encode_rgb(255, 255, 255));
}

