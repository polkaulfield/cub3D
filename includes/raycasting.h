/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:49 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/04 22:17:49 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "cub3d.h"
# include "color.h"
# include "args.h"
# include "structs.h"

void	draw_ray_texture(t_args *args, t_point pos, t_point size, double theta);
void	raycaster(t_args *args);
#endif
