/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:52:43 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/23 18:43:48 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "cub3d.h"

typedef struct map
{
	int	**grid;
	int	width;
	int	cell_size;
}	t_map;

t_map	*init_map(void);
#endif
