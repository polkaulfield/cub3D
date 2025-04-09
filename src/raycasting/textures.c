/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:42:17 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 00:42:53 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

static int	get_texture_dir(t_dvector *ray_vector, t_args *args)
{
	t_point	point;

	point.x = (int)roundf(ray_vector->p2.x + DIR_CHECK_STEP);
	point.y = (int)roundf(ray_vector->p2.y);
	if (args->map->grid[point.x][point.y] != '1')
		return (WE);
	point.x = (int)roundf(ray_vector->p2.x);
	point.y = (int)roundf(ray_vector->p2.y + DIR_CHECK_STEP);
	if (args->map->grid[point.x][point.y] != '1')
		return (NO);
	point.x = (int)roundf(ray_vector->p2.x - DIR_CHECK_STEP);
	point.y = (int)roundf(ray_vector->p2.y);
	if (args->map->grid[point.x][point.y] != '1')
		return (EA);
	point.x = (int)roundf(ray_vector->p2.x);
	point.y = (int)roundf(ray_vector->p2.y - DIR_CHECK_STEP);
	if (args->map->grid[point.x][point.y] != '1')
		return (SO);
	return (NO);
}

int	calc_color(mlx_texture_t *texture, t_raycast *raycast, int y, int x)
{
	int		index;
	float	scale;
	float	depth;
	float	pixel_divider;
	int		last_pixel;

	last_pixel = texture->height * texture->width * 4;
	depth = raycast->depth;
	scale = (float)texture->height / (float)raycast->size.y;
	index = (((int)(y * scale)) * texture->width + x) * 4;
	pixel_divider = 1 + depth * depth * 0.01;
	if (index < 0 || index >= last_pixel)
		index = 0;
	return (get_rgba(texture->pixels[index + 0] / pixel_divider,
			texture->pixels[index + 1] / pixel_divider,
			texture->pixels[index + 2] / pixel_divider,
			texture->pixels[index + 3] / pixel_divider));
}

float	calc_x_scale(t_raycast *raycast, t_dvector ray_vector)
{
	if (raycast->texture_dir == NO || raycast->texture_dir == SO)
		return ((ray_vector.p2.x - 0.5) * raycast->texture->width);
	return ((ray_vector.p2.y - 0.5) * raycast->texture->width);
}

void	draw_ray_texture(t_args *args, t_raycast *raycast, t_dvector ray_vector)
{
	int		x;
	int		y;
	float	x_2;
	int		color;

	x = -1;
	while (++x < raycast->size.x)
	{
		y = -1;
		if (raycast->pos.y + y < 0)
			y = -(raycast->pos.y - 1);
		while (++y < raycast->size.y)
		{
			x_2 = calc_x_scale(raycast, ray_vector);
			if (raycast->pos.x + x < (int)args->img->width
				&& raycast->pos.y + y < (int)args->img->height)
			{
				if (y + raycast->pos.y > (int)args->img->height)
					break ;
				color = calc_color(raycast->texture, raycast, y, x_2);
				mlx_put_pixel(args->img, raycast->pos.x + x,
					raycast->pos.y + y, color);
			}
		}
	}
}
