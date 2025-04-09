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
