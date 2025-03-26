/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:39:22 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/26 17:41:41 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/params.h"

t_params	*init_params(mlx_t *mlx, t_map *map)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->mlx = mlx;
	params->img = mlx_new_image(params->mlx, mlx->width, mlx->height);
	params->player = init_player();
	params->player->x = (mlx->width / map->width) * map->x_player;
	params->player->y = (mlx->height / map->width) * map->y_player;
	printf("Player: x: %d y: %d\n", map->x_player, map->y_player);
	printf("Player: x: %f y: %f\n", params->player->x , params->player->y);
	params->map = map;
	params->tile_size = mlx->width / map->width;
	params->fov = MPI / 3;
	params->half_fov = params->fov / 2;
	params->casted_rays = 30;
	return (params);
}
