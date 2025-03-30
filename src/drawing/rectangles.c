/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:25 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/30 17:14:03 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/drawing.h"

void	draw_square(mlx_image_t *img, t_point pos, int side, int color)
{
	int	x;
	int	y;

	if (side == 1)
	{
		mlx_put_pixel(img, pos.x, pos.y, color);
		return ;
	}
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

void	draw_rectangle(mlx_image_t *img, t_point pos, t_point size, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			if (pos.x + x < (int)img->width && pos.y < (int)img->height)
				mlx_put_pixel(img, pos.x + x, pos.y + y, color);
			y++;
		}
		x++;
	}
}
/*
void	draw_circle(mlx_image_t *img, t_point center, int radius, int color)
{
	double	dtheta;
	double	theta;
	int		n_points;
	int		i;
	t_point	point;

	n_points = 12;
	dtheta = 2 * MPI / n_points;
	theta = 0;
	i = 0;
	while (i < n_points)
	{
		point.x = (int)center.x + radius * cos(theta);
		point.y = (int)center.y + radius * sin(theta);
		mlx_put_pixel(img, point.x, point.y, color);
		theta += dtheta;
		i++;
	}
}
*/


