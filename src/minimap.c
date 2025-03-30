/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:16:49 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/30 19:35:03 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minimap.h"

t_minimap	*init_minimap(mlx_image_t *img, t_map *map)
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
		return (NULL);
	minimap->size.x = img->width / 4;
	minimap->size.y = img->height / 4;
	minimap->tile_size.x = minimap->size.x / map->width;
	minimap->tile_size.y = minimap->size.y / map->height;
	printf("minimap size x: %f y: %f tile size x: %f y: %f\n", minimap->size.x, minimap->size.y, minimap->tile_size.x, minimap->tile_size.y);
	return (minimap);
}

void	draw_minimap(mlx_image_t *img, t_minimap *minimap, t_map *map)
{
	int		light_grey;
	int		dark_grey;
	t_point	cell;
	t_point	minimap_pos;

	light_grey = get_rgba(192, 191, 191, 255);
	dark_grey = get_rgba(65, 65, 65, 255);
	cell.y = 0;
	while (cell.y < minimap->size.y)
	{
		cell.x = 0;
		while (cell.x < minimap->size.x)
		{
			minimap_pos.x = cell.x;// * minimap->tile_size.x;
			minimap_pos.y = cell.y;// * minimap->tile_size.y;
			printf("%c ", map->grid[(int)cell.x][(int)cell.y]);
			if (map->grid[(int)cell.x][(int)cell.y] == '1')
				draw_rectangle(img, minimap_pos, minimap->tile_size, dark_grey);
			else
				draw_rectangle(img, minimap_pos, minimap->tile_size, light_grey);
			cell.x++;
		}
		cell.y++;
	}
}
