/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:33:38 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/20 22:05:38 by pohernan         ###   ########.fr       */
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
	int		tile_size;
	t_map	*map;
	double	fov;
	double	half_fov;
	t_player *player;
	int		casted_rays;
}	t_params;

t_params *init_params(mlx_t *mlx, t_map *map);
#endif
