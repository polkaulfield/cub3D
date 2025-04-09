/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:49 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 00:45:30 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "cub3d.h"
# include "color.h"
# include "args.h"
# include "structs.h"
# include "drawing.h"

void	start_ray_vector(t_dvector *vector, t_args *args);
void	end_ray_vector(t_dvector *vect, t_raycast *raycast);
void	get_collision_coords(t_point *point, t_dvector *ray_vector);
int		get_texture_dir(t_dvector *ray_vector, t_args *args);
void	draw_ray_texture(t_args *args, t_raycast *raycast, t_dvector ray);
void	raycaster(t_args *args);
#endif
