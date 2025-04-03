/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:02:01 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/03 19:57:01 by pohernan         ###   ########.fr       */
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
	printf("New position: (%.2f, %.2f)\n", pos.x, pos.y);
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

void	draw_player_minimap(t_player *player, t_minimap *minimap, t_map *map, mlx_image_t *img)
{
	t_point	point;

	(void)map;
	printf("Player x: %d, y: %d\n", (int)player->pos.x, (int)player->pos.y);
	printf("minimap size x: %d, y: %d\n", minimap->size.x, minimap->size.y);
	point.x = (int)(player->pos.x * minimap->tile_size.x + minimap->tile_size.x / 2);
	point.y = (int)(player->pos.y * minimap->tile_size.y + minimap->tile_size.y / 2);
	printf("Point x: %d, y: %d\n", point.x, point.y);
	draw_circle(img, point, 10, encode_rgb(255, 255, 255));
	printf("-_- angle: %f\n", player->angle);
	//vector.p1 = point;
	//vector.p2 = point2;
	//draw_line(img, vector, 5, get_rgba(0,0,255,255));
	raycaster(img, map, minimap, player);

	/*dpoint = get_next_pos(50, player->angle - 45, dpoint);
	point2.x = dpoint.x;
	point2.y = dpoint.y;
	vector.p1 = point;
	vector.p2 = point2;
	draw_line(img, vector, 2, get_rgba(0,255,0,255));

	dpoint = get_next_pos(50, player->angle + 45, dpoint);
	point2.x = dpoint.x;
	point2.y = dpoint.y;
	//vector.p1 = point;
	vector.p2 = point2;
	draw_line(img, vector, 2, get_rgba(0,255,0,255));

	dpoint = get_next_pos(50, player->angle + 90, dpoint);
	point2.x = dpoint.x;
	point2.y = dpoint.y;
	//vector.p1 = point;
	vector.p2 = point2;
	draw_line(img, vector, 2, get_rgba(0,255,0,255));*/
}
