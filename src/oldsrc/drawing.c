/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:25 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/03 23:41:34 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/drawing.h"
#include "../includes/images.h"
#include "../includes/parser.h"
#include "../includes/coords.h"

t_coords get_pixel_pos_x(t_coords p1, t_coords p2, int y)
{
	t_coords p3;

	p3.y = y;
	p3.x = (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
	return (p3);
}

t_coords get_pixel_pos_y(t_coords p1, t_coords p2, int x)
{
	t_coords p3;

	p3.x = x;
	p3.y = (x - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y;
	return (p3);
}

void	draw_line(mlx_image_t *img, t_coords p1, t_coords p2, int color)
{
	t_coords pixel_pos;
	int		x;
	int		y;
	int		dir;

	dir = 1;
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
	{
		if (p2.x - p1.x < 0)
			dir = -1;
		x = p1.x;
		while ((dir == 1 && x < p2.x) || (dir == -1 && x > p2.x))
		{
			pixel_pos = get_pixel_pos_y(p1, p2, x);
			mlx_put_pixel(img, pixel_pos.x, pixel_pos.y, color);
			x += dir;
		}
	}
	else
	{
		if (p2.y - p1.y < 0)
			dir = -1;
		y = p1.y;
		while ((dir == 1 && y < p2.y) || (dir == -1 && y > p2.y))
		{
			pixel_pos = get_pixel_pos_x(p1, p2, y);
			mlx_put_pixel(img, pixel_pos.x, pixel_pos.y, color);
			y += dir;
		}
	}
}

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
void	draw_verical_line(mlx_image_t *img, t_coords pos_start, int len, int width, int color)
{
	int	y;
	int	y_end;

	draw_rectangle(img, pos_start, width, len, color);

}
*/
mlx_image_t	*make_minimap_image(t_params *params)
{
	int			width;
	int			height;
	mlx_image_t	*img;

	width = params->mlx->width / 4;
	height = params->mlx->height / 4;
	img = init_simple_image(width, height, encode_rgb(0, 255, 0), params);
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
			//printf("%c ", params->map->grid[coords.x][coords.y]);
			pos.x = params->tile_size * coords.x;
			pos.y = params->tile_size * coords.y;
			if (params->map->grid[coords.x][coords.y] == '1')
				draw_square(minimap, pos, params->tile_size, encode_rgb(100, 0, 0));
			else
				draw_square(minimap, pos, params->tile_size, encode_rgb(255, 255, 255));
			coords.x++;
		}
		coords.y++;
		//printf("\n");
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
