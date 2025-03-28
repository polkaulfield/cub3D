/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:39:22 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/26 17:57:37 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/player.h"
#include "../includes/color.h"
#include "../includes/galloc.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = galloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->img = NULL;
	player->x = 0;
	player->y = 0;
	player->step = 5;
	player->color = get_rgba(0, 255 ,0, 255);
	player->player_angle = MPI;
	return (player);
}
