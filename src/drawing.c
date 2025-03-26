/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:25 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/26 17:54:18 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/drawing.h"
#include "../includes/images.h"
#include "../includes/parser.h"
#include "../includes/coords.h"

void	draw_square(mlx_image_t *img, t_coords pos, int side, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < side)
	{
		y = 0;
		while (y < side)
		{
			mlx_put_pixel(img, pos.x + x, pos.y + y, color);
			y++;
		}
		x++;
	}
}

void	draw_grid(t_params *params)
{
	t_coords	size;
	t_coords	coords;
	t_coords	pos;
	mlx_image_t	*new_img;

	coords.y = 0;
	size.x = params->mlx->width;
	size.y =params->mlx->height;
	new_img = new_image(params, size);
	while (coords.y < params->map->height)
	{
		coords.x = 0;
		while (coords.x < params->map->width)
		{
			printf("%c ", params->map->grid[coords.x][coords.y]);
			pos.x = params->tile_size * coords.x;
			pos.y = params->tile_size * coords.y;
			if (params->map->grid[coords.x][coords.y] == '1')
				draw_square(new_img, pos, params->tile_size, get_rgba(255, 0, 0, 255));
			else
				draw_square(new_img, pos, params->tile_size, get_rgba(0, 255, 0, 0));
			coords.x++;
		}
		coords.y++;
		printf("\n");
	}
	if (params->img)
		mlx_delete_image(params->mlx, params->img);
	params->img = new_img;
}
/*
void	raycaster(t_params *params)
{
	int	ray;
	int	depth;
	int	target_x;
	int	target_y;

	ray = 0;
	while (ray < params->casted_rays)
	{
		depth = 0;
		while (depth < params->max_depth)
		{

		}
	}
}
*/
