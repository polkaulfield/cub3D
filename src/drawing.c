/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:25 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/20 23:54:51 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/drawing.h"
#include "../includes/images.h"
#include "../includes/parser.h"

void	draw_grid(t_params *params)
{
	int			x;
	int			y;
	int			size;
	mlx_image_t	*img;

	y = 0;
	size = params->tile_size;
	while (y < params->map->map_height)
	{
		x = 0;
		while (x < params->map->map_width)
		{
			printf("%c ", params->map->grid[x][y]);
			if (params->map->grid[x][y] == '1')
				img = init_simple_image(size, size, get_rgba(255, 0, 0, 255), params);
			else
				img = init_simple_image(size, size, get_rgba(0, 255, 0, 0), params);
			add_image_mlx(x * size, y * size, img, params);
			x++;
		}
		y++;
		printf("\n");

	}
}
