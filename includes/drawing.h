/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:49 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/30 20:35:09 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H
# include "cub3d.h"
# include <math.h>
# include "color.h"

# include "structs.h"

void	draw_ray_floor(t_args *args, t_point pos, t_point size);
void	draw_ray_ceiling(t_args *args, t_point pos, t_point size);

void	draw_square(mlx_image_t *img, t_point pos, int side, int color);
void	draw_rectangle(mlx_image_t *img, t_point pos, t_point size, int color);
void	draw_line(mlx_image_t *img, t_vector vector, int width, int color);
void	draw_circle(mlx_image_t *img, t_point center, int radius, int color);


#endif
