/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:12:09 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/04 23:01:34 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/args.h"
#include "../includes/minimap.h"
#include "../includes/player.h"

t_args	*init_args(mlx_image_t *img, mlx_t *mlx, t_map *map)
{
	t_args	*args;

	args = galloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->mlx = mlx;
	args->img = img;
	args->map = map;
	args->player = init_player(map);
	args->minimap = init_minimap(mlx, img, map);
	args->step_angle = FOV / img->width;
	args->scale = (float)args->img->width * 2 / CASTED_RAYS;
	args->texture[NO] = mlx_load_png(map->texture[NO]);
	args->texture[EA] = mlx_load_png(map->texture[EA]);
	args->texture[SO] = mlx_load_png(map->texture[SO]);
	args->texture[WE] = mlx_load_png(map->texture[WE]);
	args->ceiling = map->ceiling;
	args->floor = map->floor;
	return (args);
}
