#include "../includes/raycasting.h"

static int  get_texture_dir(t_dvector *ray_vector, t_args *args)
{
    t_point point;

    point.x = (int)roundf(ray_vector->p2.x + 0.001);
    point.y = (int)roundf(ray_vector->p2.y);
    if (args->map->grid[point.x][point.y] == '0')
        return (WE);
    point.x = (int)roundf(ray_vector->p2.x);
    point.y = (int)roundf(ray_vector->p2.y + 0.001);
    if (args->map->grid[point.x][point.y] == '0')
        return (NO);
    point.x = (int)roundf(ray_vector->p2.x - 0.001);
    point.y = (int)roundf(ray_vector->p2.y);
    if (args->map->grid[point.x][point.y] == '0')
        return (EA);
    point.x = (int)roundf(ray_vector->p2.x);
    point.y = (int)roundf(ray_vector->p2.y - 0.001);
    if (args->map->grid[point.x][point.y] == '0')
        return (SO);
    return(NO);
}

int calc_color(mlx_texture_t *texture, t_point pos, t_point size, int y, int x, double depth)
{
	int	index;
	double	scale;
	(void)x;
	(void)pos;

	scale = (double)texture->height / (double)size.y;

	index = (((int)(y * scale)) * texture->width + x) * 4;
	if (index < 0)
		index = 0;
	return(	get_rgba(texture->pixels[index + 0] / (1 + depth * depth * 0.01),
					texture->pixels[index + 1] / (1 + depth * depth * 0.01),
					texture->pixels[index + 2] / (1 + depth * depth * 0.01),
					texture->pixels[index + 3] / (1 + depth * depth * 0.01)));
	printf("%i\n", texture->pixels[0]);
}

void	draw_ray_texture(t_args *args, t_point pos, t_point size, t_dvector ray_vector)
{
	int	x;
	int	y;
	double  x_2;
	int	color;
	mlx_texture_t	*texture;

	x = 0;
	x_2 = 0;
	args->raycast.texture_dir = get_texture_dir(&ray_vector, args);
	texture = args->texture[args->raycast.texture_dir];
	draw_ray_ceiling(args, pos, size);
	while (x < size.x)
	{
		y = 0;
		if (pos.y + y < 0)
			y = -pos.y;
		while (y < size.y)
		{//args, x_2, pos, size,
			if (args->raycast.texture_dir == NO || args->raycast.texture_dir == SO)
				x_2 = ray_vector.p2.x - (ray_vector.p2.x + 0.5) * texture->width;
			else
				x_2 = ray_vector.p2.y - (ray_vector.p2.y + 0.5) * texture->width;
			if (pos.x + x < (int)args->img->width && pos.y < (int)args->img->height)
			{
				color = calc_color(texture, pos, size, y, x_2, args->raycast.depth);
				if (y + pos.y > (int)args->img->height)
					break ;
				if (y + pos.y < (int)args->img->height)
					mlx_put_pixel(args->img, pos.x + x, pos.y + y, color);
			}
			y++;
		}
		x++;
	}
	draw_ray_floor(args, pos, size);
}

void	raycast_3d(t_args *args, t_dvector ray_vector)
{
	t_raycast	*raycast = &args->raycast;
	int			clr;
	int			wall_height;
	t_point		rect_pos;
	t_point		rect_size;
	double		scale;

  	scale = (double)args->img->width * 2 / CASTED_RAYS;
	clr = 255 / (1 + raycast->depth * raycast->depth * 0.05);
	raycast->depth *= cos(args->player->angle - raycast->theta);
	wall_height = roundf(args->img->width / raycast->depth);
	rect_pos.x = raycast->ray * scale / 2;
	rect_pos.y = (args->img->height / 2) - wall_height / 2;
	rect_size.x = scale;
	rect_size.y = wall_height;
  	draw_ray_texture(args, rect_pos, rect_size, ray_vector);
	//draw_rectangle(args->img, rect_pos, rect_size, encode_rgb(clr, clr, clr));
	(void)clr;
	(void)ray_vector;
}

void	start_ray_vector(t_dvector *vector, t_args *args)
{
	vector->p1.x = args->player->pos.x;
	vector->p1.y = args->player->pos.y;
}

void	end_ray_vector(t_dvector *vect, double theta, double depth)
{
	vect->p2.x = vect->p1.x - sin(theta) * depth;
	vect->p2.y = vect->p1.y + cos(theta) * depth;
}

void	get_collision_coords(t_point *point, t_dvector *ray_vector)
{
	point->x = (int)roundf(ray_vector->p2.x);
	point->y = (int)roundf(ray_vector->p2.y);
}

t_vector get_ray_minimap(t_dvector *ray_vector, t_args *args)
{
	t_vector  vector_minimap;

	vector_minimap.p1.x = (int)roundf(args->player->pos.x * args->minimap->tile_size.x \
		+ (double)args->minimap->tile_size.x / 2);
	vector_minimap.p1.y = (int)roundf(args->player->pos.y * args->minimap->tile_size.y \
		+ (double)args->minimap->tile_size.y / 2);
	vector_minimap.p2.x = (int)roundf(ray_vector->p2.x * args->minimap->tile_size.x \
    	+ (double)args->minimap->tile_size.x / 2);
	vector_minimap.p2.y = (int)roundf(ray_vector->p2.y * args->minimap->tile_size.y \
		+ (double)args->minimap->tile_size.y / 2);
	return (vector_minimap);
}

void	init_raycast(t_args *args, t_raycast *raycast)
{
	raycast->ray = 0;
	raycast->theta = args->player->angle - HALF_FOV;
	raycast->depth = 0;
	raycast->texture_dir = 0;
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
			end_ray_vector(&raycast->ray_vector, raycast->theta, raycast->depth);
			get_collision_coords(&point, &raycast->ray_vector);
			if (args->map->grid[point.x][point.y] == '1')
			{
				raycast_3d(args, raycast->ray_vector);
				draw_line(args->minimap->img, get_ray_minimap(&raycast->ray_vector, args), 1, encode_rgb(255, 0, 255));
				break ;
			}
			raycast->depth += 0.001;
		}
		raycast->ray++;
		raycast->theta += args->step_angle;
	}
}
