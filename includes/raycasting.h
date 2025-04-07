/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:49 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/07 18:03:30 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "cub3d.h"
# include "color.h"
# include "args.h"
# include "structs.h"
# include "drawing.h"

void	start_ray_vector(t_vector *vector, t_args *args);
void	end_ray_vector(t_vector *vect, double theta, double depth);
void	get_collision_coords(t_point *point, t_vector *ray_vector, t_args *args);

void	draw_ray_texture(t_args *args, t_point pos, t_point size, double theta, double out_scale, double depth, t_point wall_point, int wall_height);
void	raycaster(t_args *args);
#endif
