/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:25 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/26 19:57:33 by pohernan         ###   ########.fr       */
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
			if (pos.x + x < (int)img->width && pos.y < (int)img->height)
				mlx_put_pixel(img, pos.x + x, pos.y + y, color);
			y++;
		}
		x++;
	}
}

void	draw_rectangle(mlx_image_t *img, t_coords pos, int width, int height, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			if (pos.x + x < (int)img->width && pos.y < (int)img->height)
				mlx_put_pixel(img, pos.x + x, pos.y + y, color);
			y++;
		}
		x++;
	}
}

/*
void	draw_line(mlx_image_t *img, t_coords pos_start, t_coords pos_end, int width, int color);
{

}
*/
mlx_image_t	*make_minimap_image(t_params *params)
{
	int			width;
	int			height;
	mlx_image_t	*img;

	width = params->mlx->width / 4;
	height = params->mlx->height / 4;
	img = init_simple_image(width, height, get_rgba(0, 255, 0, 255), params);
	return (img);
}

void	draw_minimap(t_params *params)
{
	t_coords	pos;
	t_coords	coords;
	mlx_image_t	*minimap;

	minimap =  make_minimap_image(params);
	coords.y = 0;
	while (coords.y < params->map->height)
	{
		coords.x = 0;
		while (coords.x < params->map->width)
		{
			printf("%c ", params->map->grid[coords.x][coords.y]);
			pos.x = params->tile_size * coords.x;
			pos.y = params->tile_size * coords.y;
			if (params->map->grid[coords.x][coords.y] == '1')
				draw_square(minimap, pos, params->tile_size, get_rgba(255, 0, 0, 255));
			else
				draw_square(minimap, pos, params->tile_size, get_rgba(255, 255, 255, 255));
			coords.x++;
		}
		coords.y++;
		printf("\n");
	}
	if (params->img)
		mlx_delete_image(params->mlx, params->img);
	params->img = minimap;
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
