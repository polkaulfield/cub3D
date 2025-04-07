/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:16:49 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/04 22:57:45 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minimap.h"
#include <string.h>

t_minimap	*init_minimap(mlx_t *mlx, mlx_image_t *img, t_map *map)
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
		return (NULL);
	minimap->size.x = img->width / 4;
	minimap->size.y = img->height / 4;
	img = mlx_new_image(mlx, minimap->size.x, minimap->size.y);
	minimap->tile_size.x = minimap->size.x / map->width;
	minimap->tile_size.y = minimap->size.y / map->height;
	return (minimap);
}

void	draw_player_minimap(t_args *args)
{
	t_point	point;

	point.x = (int)(args->player->pos.x * args->minimap->tile_size.x \
		+ args->minimap->tile_size.x / 2);
	point.y = (int)(args->player->pos.y * args->minimap->tile_size.y \
		+ args->minimap->tile_size.y / 2);
	draw_circle(args->minimap->img, point, 10, encode_rgb(255, 255, 255));
}

void	put_map_on_img(mlx_image_t *img_map, mlx_image_t *img)
{
	unsigned int		x;
	unsigned int		y;

	y = 0;
	while (y < img_map->height)
	{
		x = 0;
		while (x < img_map->width)
		{
			memcpy(&img->pixels[(y * img->width + x) * 4], &img_map->pixels[(y * img_map->width + x) * 4], 4);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_args *args)
{
	int		grey;
	int		dgrey;
	t_point	cell;
	t_point	pos;

	grey = encode_rgb(192, 191, 191);
	dgrey = encode_rgb(65, 65, 65);
	cell.y = 0;
	while (cell.y < args->map->height)
	{
		cell.x = 0;
		while (cell.x < args->map->width)
		{
			pos.x = cell.x * args->minimap->tile_size.x;
			pos.y = cell.y * args->minimap->tile_size.y;
			if (args->map->grid[(int)cell.x][(int)cell.y] == '1')
				draw_rectangle(args->minimap->img, pos, args->minimap->tile_size, grey);
			else
				draw_rectangle(args->minimap->img, pos, args->minimap->tile_size, dgrey);
			cell.x++;
		}
		cell.y++;
	}
	draw_player_minimap(args);
}


