/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:03:30 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/03 23:41:34 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/drawing.h"

void	draw_circle(mlx_image_t *img, t_point center, int radius, int color)
{
	int	x;
	int	y;

	y = 0;
	//printf("center x: %d, y: %d\n", center.x, center.y);
	while (y <= radius)
	{
		x = 0;
		while (x <= sqrt(radius * radius - y * y))
		{
			mlx_put_pixel(img, center.x + x, center.y + y, color);
			mlx_put_pixel(img, center.x - x, center.y + y, color);
			mlx_put_pixel(img, center.x + x, center.y - y, color);
			mlx_put_pixel(img, center.x - x, center.y - y, color);
			x++;
		}
		y++;
	}
}
/*
void	draw_circle(mlx_image_t *img, t_dpoint center, int radius, int color)
{
	double		dtheta;
	double		theta;
	int			n_points;
	int			i;
	t_dvector	vector;

	while (radius > 0)
	{
		n_points = 100;
		dtheta = 2 * MPI / n_points;
		theta = 0;
		i = 0;
		while (i < n_points)
		{
			vector.p1.x = (int)center.x + radius * cos(theta);
			vector.p1.y = (int)center.y + radius * sin(theta);
			theta += dtheta;
			vector.p2.x = (int)center.x + radius * cos(theta);
			vector.p2.y = (int)center.y + radius * sin(theta);
			draw_line(img, vector, 3, color);
			i++;
		}
		radius--;
	}
}
*/
// TODO square and check radius
