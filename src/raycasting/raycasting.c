/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:20:40 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 14:53:55 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

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
