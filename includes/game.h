/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:45:13 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 00:45:14 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "cub3d.h"
# include "player.h"
# include "args.h"
# include "parser.h"
# include "errors.h"

void	keys_hook(void *params);
void	game_loop(void *params);
#endif
