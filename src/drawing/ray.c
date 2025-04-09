/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:25:06 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:25:53 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/drawing.h"

void	draw_multiple_pixels(mlx_image_t *img, int x, int y, int color)
{
	mlx_put_pixel(img, x, y, color);
	mlx_put_pixel(img, x + 1, y, color);
	mlx_put_pixel(img, x, y + 1, color);
	mlx_put_pixel(img, x + 1, y + 1, color);
	y += 2;
	mlx_put_pixel(img, x, y, color);
	mlx_put_pixel(img, x + 1, y, color);
	mlx_put_pixel(img, x, y + 1, color);
	mlx_put_pixel(img, x + 1, y + 1, color);
}

void	draw_ray_ceiling(t_args *args, t_point pos, t_point size)
{
	int			y;
	float		depth;
	int			color;

	y = size.y;
	y = -1;
	while (++y < pos.y)
	{
		depth = (1 + y * y * 0.000005);
		color = get_rgba(args->ceiling[0] / depth, args->ceiling[1] \
			/ depth, args->ceiling[2] / depth, 255);
		if (pos.x + 1 < (int)args->img->width && y + 3 < (int)args->img->height)
		{
			draw_multiple_pixels(args->img, pos.x, y, color);
			y += 3;
		}
		else if (pos.x < (int)args->img->width \
			&& pos.y + y < (int)args->img->height)
		{
			mlx_put_pixel(args->img, pos.x, pos.y + y, color);
			mlx_put_pixel(args->img, pos.x + 1, y, color);
		}
	}
}

void	draw_ray_floor(t_args *args, t_point pos, t_point size)
{
	int			y;
	float		depth;
	int			color;

	y = pos.y + size.y;
	while (++y < (int)args->img->height)
	{
		color = get_rgba(args->ceiling[0] / depth, args->ceiling[1] \
			/ depth, args->ceiling[2] / depth, 255);
		depth = (1 + (args->img->height - y) * (args->img->height - y) * 0.000005);
		if (pos.x + 1 < (int)args->img->width && y + 3 < (int)args->img->height)
		{
			draw_multiple_pixels(args->img, pos.x, y, color);
			y += 3;
		}
		else if (pos.x + 1 < (int)args->img->width \
			&& pos.y < (int)args->img->height)
		{
			mlx_put_pixel(args->img, pos.x, y, color);
			mlx_put_pixel(args->img, pos.x + 1, y, color);
		}
	}
}


void	draw_ceiling(t_args *args, int color)
{
	t_point	start;
	t_point	size;

	start.x = 0;
	start.y = 0;
	size.x = args->img->width;
	size.y = args->img->height / 2;
	draw_rectangle(args->img, start, size, color);
}

void	draw_floor(t_args *args, int color)
{
	t_point	start;
	t_point	size;

	start.x = 0;
	start.y = args->img->height / 2;
	size.x = args->img->width;
	size.y = args->img->height / 2;
	draw_rectangle(args->img, start, size, color);
}
