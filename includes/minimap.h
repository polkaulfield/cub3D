/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:17:14 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/30 20:34:21 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H
# include "cub3d.h"
# include "drawing.h"
# include "parser.h"
# include "player.h"

typedef struct s_minimap
{
	t_point	tile_size;
	t_point	size;
}	t_minimap;

t_minimap	*init_minimap(mlx_image_t *img, t_map *map);
void	draw_minimap(mlx_image_t *img, t_minimap *minimap, t_map *map);

#endif
