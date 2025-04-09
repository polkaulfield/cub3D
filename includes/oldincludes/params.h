/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:33:38 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/23 18:30:30 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H
# include "cub3d.h"
# include "parser.h"
# include "player.h"

typedef struct s_params
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	int		tile_size;
	t_map	*map;
	float	fov;
	float	half_fov;
	t_player *player;
	int		casted_rays;
	float	max_depth;
}	t_params;

t_params *init_params(mlx_t *mlx, t_map *map);
#endif
