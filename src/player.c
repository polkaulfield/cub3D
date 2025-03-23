/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:39:22 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/22 23:53:05 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/player.h"
#include "../includes/color.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->img = NULL;
	player->x = 400;
	player->y = 400;
	player->step = 5;
	player->color = get_rgba(255, 0 ,255, 255);
	player->player_angle = MPI;
	return (player);
}
