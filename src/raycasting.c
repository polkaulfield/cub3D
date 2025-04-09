/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:20:40 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:34:27 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

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

void	raycast_3d(t_args *args, t_point *pos, t_point *size)
{
	t_raycast	*raycast;
	int			wall_height;
	float		scale;

	raycast = &args->raycast;
	scale = (float)args->img->width * 2 / CASTED_RAYS;
	raycast->depth *= cos(args->player->angle - raycast->theta);
	wall_height = roundf(args->img->width / raycast->depth);
	pos->x = raycast->ray * scale / 2;
	pos->y = (args->img->height / 2) - wall_height / 2;
	size->x = scale;
	size->y = wall_height;
	draw_ray_ceiling(args, raycast->pos, raycast->size);
	draw_ray_floor(args, raycast->pos, raycast->size);
	raycast->texture_dir = get_texture_dir(&raycast->ray_vector, args);
	raycast->texture = args->texture[args->raycast.texture_dir];
	draw_ray_texture(args, &args->raycast, raycast->ray_vector);
}

t_vector	get_ray_minimap(t_dvector *ray_vector, t_args *args)
{
	t_vector	vector_minimap;
	float		div_tile_x;
	float		div_tile_y;

	div_tile_x = (float)args->minimap->tile_size.x / 2;
	div_tile_y = (float)args->minimap->tile_size.y / 2;
	vector_minimap.p1.x = (int)roundf(args->player->pos.x \
			* args->minimap->tile_size.x + div_tile_x);
	vector_minimap.p1.y = (int)roundf(args->player->pos.y \
			* args->minimap->tile_size.y + div_tile_y);
	vector_minimap.p2.x = (int)roundf(ray_vector->p2.x \
			* args->minimap->tile_size.x + div_tile_x);
	vector_minimap.p2.y = (int)roundf(ray_vector->p2.y \
			* args->minimap->tile_size.y + div_tile_y);
	return (vector_minimap);
}

void	init_raycast(t_args *args, t_raycast *raycast)
{
	raycast->ray = 0;
	raycast->theta = args->player->angle - HALF_FOV;
	raycast->depth = 0;
	raycast->texture_dir = 0;
	raycast->texture = NULL;
	raycast->ray_vector.p1.x = 0;
	raycast->ray_vector.p1.y = 0;
	raycast->ray_vector.p2.x = 0;
	raycast->ray_vector.p2.y = 0;
	raycast->pos.x = 0;
	raycast->pos.y = 0;
	raycast->size.x = 0;
	raycast->size.y = 0;
}

void	raycaster(t_args *args)
{
	t_point		point;
	t_raycast	*raycast;

	init_raycast(args, &args->raycast);
	raycast = &args->raycast;
	start_ray_vector(&raycast->ray_vector, args);
	while (raycast->ray < CASTED_RAYS)
	{
		raycast->depth = 0;
		while (raycast->depth < MAX_DEPTH)
		{
			end_ray_vector(&raycast->ray_vector, raycast);
			get_collision_coords(&point, &raycast->ray_vector);
			if (args->map->grid[point.x][point.y] == '1')
			{
				raycast_3d(args, &raycast->pos, &raycast->size);
				draw_line(args->minimap->img, get_ray_minimap(\
					&raycast->ray_vector, args), 1, encode_rgb(255, 0, 255));
				break ;
			}
			raycast->depth += DIR_CHECK_STEP;
		}
		raycast->ray++;
		raycast->theta += args->step_angle;
	}
}
