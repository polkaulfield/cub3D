/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:27:07 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:27:08 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_map	*init_map(char *file)
{
	int		i;
	t_map	*map;

	map = galloc(sizeof(t_map));
	map->file_name = file;
	map->fd_file = -1;
	map->player_direction = '\0';
	map->y_player = -1;
	map->x_player = -1;
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	i = -1;
	while (++i < 5)
		map->texture[i] = NULL;
	i = -1;
	while (++i < 3)
		map->floor[i] = -1;
	i = -1;
	while (++i < 3)
		map->ceiling[i] = -1;
	return (map);
}
