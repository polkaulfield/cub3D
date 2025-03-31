/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:54:34 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/18 20:00:36 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H
# include "cub3d.h"
# include "params.h"
# include "player.h"
# include "images.h"
# include "color.h"

void	move_player(int x, int y, t_player *player, t_params *params);
#endif
