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

typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_dvector
{
	t_dpoint	p1;
	t_dpoint	p2;
}	t_dvector;


typedef struct s_vector
{
	t_point	p1;
	t_point	p2;
}	t_vector;


void	draw_square(mlx_image_t *img, t_point pos, int side, int color);
void	draw_rectangle(mlx_image_t *img, t_point pos, t_point size, int color);
void	draw_line(mlx_image_t *img, t_vector vector, int width, int color);
void	draw_circle(mlx_image_t *img, t_point center, int radius, int color);


#endif
