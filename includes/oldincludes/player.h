/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:38:34 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/23 20:00:35 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"
# include "coords.h"

typedef struct s_player
{
	double		x;
	double		y;
	t_coords	pos;
	double		player_angle;
	double		step;
	int			color;
	int			size;
	mlx_image_t	*img;
}	t_player;

t_player	*init_player(void);
#endif
