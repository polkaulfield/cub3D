/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:14:13 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/30 18:59:57 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H
# include "cub3d.h"
# include "parser.h"
# include "player.h"
# include "minimap.h"

typedef struct s_args
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	t_player	*player;
	t_minimap	*minimap;

}	t_args;

t_args	*init_args(mlx_image_t *img, mlx_t *mlx, t_map *map);

#endif
