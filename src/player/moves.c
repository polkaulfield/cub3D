/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:41:16 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 00:41:17 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

t_dpoint	get_next_pos(float h, float angle, t_dpoint pos)
{
	pos.y += cos(angle) * h;
	pos.x -= sin(angle) * h;
	return (pos);
}

float	add_angle(float angle, float increment)
{
	angle += increment;
	while (angle < 0)
		angle += TWOPI;
	while (angle >= TWOPI)
		angle -= TWOPI;
	return (angle);
}

void	move_player(int key, t_player *player, float len, t_args *args)
{
	t_dpoint	dpoint;

	dpoint.x = 0;
	if (key == UP || key == W)
		dpoint = get_next_pos(len, player->angle, player->pos);
	else if (key == DOWN || key == S)
		dpoint = get_next_pos(len, player->angle, player->pos);
	else if (key == D || key == A)
		dpoint = get_next_pos(len, player->angle + 1.5708, player->pos);
	else if (key == RIGHT)
		player->angle = add_angle(player->angle, len);
	else if (key == LEFT)
		player->angle = add_angle(player->angle, len);
	else
		return ;
	if (dpoint.x != 0 && !is_grid_collision((int)roundf(dpoint.x), \
		(int)roundf(dpoint.y), args->map))
		player->pos = dpoint;
}
