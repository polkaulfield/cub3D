/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:17:14 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/04 23:00:44 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H
# include "cub3d.h"
# include "drawing.h"
# include "parser.h"
# include "args.h"

# include "structs.h"

t_minimap	*init_minimap(mlx_t *mlx, mlx_image_t *img, t_map *map);
void		draw_minimap(t_args *args);

#endif
