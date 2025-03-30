/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:06:41 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/30 17:06:41 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/drawing.h"

static void	draw_line_x(mlx_image_t *img, t_vector vector, int width, int color)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	bool	neg;

	neg = false;
	p1 = vector.p1;
	p2 = vector.p2;
	if (p2.y - p1.y < 0)
		neg = true;
	p3.y = p1.y;
	while ((!neg && p3.y < p2.y) || (neg && p3.y > p2.y))
	{
		printf("printing pixel Y!\n");
		p3.x = (p3.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
		draw_square(img, p3, width, color);
		if (neg)
			p3.y--;
		else
			p3.y++;
	}
}

static void	draw_line_y(mlx_image_t *img, t_vector vector, int width, int color)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	bool	neg;

	neg = false;
	p1 = vector.p1;
	p2 = vector.p2;
	if (p2.x - p1.x < 0)
		neg = true;
	p3.x = p1.x;
	while ((!neg && p3.x < p2.x) || (neg && p3.x > p2.x))
	{
		p3.y = (p3.x - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y;
		draw_square(img, p3, width, color);
		if (neg)
			p3.x--;
		else
			p3.x++;
	}
}

void	draw_line(mlx_image_t *img, t_vector vector, int width, int color)
{
	if (fabs(vector.p2.x - vector.p1.x) < fabs(vector.p2.y - vector.p1.y))
		draw_line_x(img, vector, width, color);
	else
		draw_line_y(img, vector, width, color);
}
