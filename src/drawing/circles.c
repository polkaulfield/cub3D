/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:03:30 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:30:26 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/drawing.h"

void	draw_circle(mlx_image_t *img, t_point center, int radius, int color)
{
	int	x;
	int	y;

	y = 0;
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
