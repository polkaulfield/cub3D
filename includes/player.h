/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:46:23 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 00:46:31 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"
# include "drawing.h"
# include "parser.h"
# include "minimap.h"
# include "misc.h"
# include "raycasting.h"

# include "structs.h"

t_player	*init_player(t_map *map);
void		move_player(int key, t_player *player, float len, t_args *args);

#endif
