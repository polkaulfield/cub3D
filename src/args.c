/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:12:09 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/30 19:14:56 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/args.h"
#include "../includes/minimap.h"

t_args	*init_args(mlx_image_t *img, mlx_t *mlx, t_map *map)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->mlx = mlx;
	args->img = img;
	args->map = map;
	args->player = init_player(map);
	args->minimap = init_minimap(img, map);
	return (args);
}
