#include "../includes/raycasting.h"

static int  get_texture_dir(t_vector *ray_vector, t_args *args)
{
    t_point point;

    point.x = (int)(ray_vector->p2.x + 1) / args->minimap->tile_size.x;
    point.y = (int)ray_vector->p2.y / args->minimap->tile_size.y;
    if (args->map->grid[point.x][point.y] == '0')
        return (WE);
    point.x = (int)ray_vector->p2.x / args->minimap->tile_size.x;
    point.y = (int)(ray_vector->p2.y + 1) / args->minimap->tile_size.y;
    if (args->map->grid[point.x][point.y] == '0')
        return (NO);
    point.x = (int)(ray_vector->p2.x - 1)/ args->minimap->tile_size.x;
    point.y = (int)ray_vector->p2.y / args->minimap->tile_size.y;
    if (args->map->grid[point.x][point.y] == '0')
        return (EA);
    point.x = (int)ray_vector->p2.x / args->minimap->tile_size.x;
    point.y = (int)(ray_vector->p2.y - 1) / args->minimap->tile_size.y;
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
	return(	get_rgba(texture->pixels[index + 0] / (1 + depth * depth * 0.0001),
					texture->pixels[index + 1] / (1 + depth * depth * 0.0001),
					texture->pixels[index + 2] / (1 + depth * depth * 0.0001),
					texture->pixels[index + 3] / (1 + depth * depth * 0.0001)));
}

void	draw_ray_texture(t_args *args, t_point pos, t_point size, double depth, t_vector ray_vector, int flag)
{
	int	x;
	static double	x_static = 0;
	static int	last_texture = 0;
	int	y;
	int	color;
	int	texture_direction = get_texture_dir(&ray_vector, args);
	mlx_texture_t	*texture = args->texture[texture_direction];
	x = 0;
	if (flag)
		x_static = 0;
	//x_static = ((int)((double)ray_vector.p2.x / (double)args->minimap->tile_size.x) + 1.0 - ((double)ray_vector.p2.x / (double)args->minimap->tile_size.x)) * texture->width;
	draw_ray_ceiling(args, pos, size);
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			x_static = ((int)((double)ray_vector.p2.x / (double)args->minimap->tile_size.x) + 1.0 - ((double)ray_vector.p2.x / (double)args->minimap->tile_size.x)) * texture->width;
			if (pos.x + x < (int)args->img->width && pos.y < (int)args->img->height)
			{
				color = calc_color(texture, pos, size, y, x_static, depth);
				mlx_put_pixel(args->img, pos.x + x, pos.y + y, color);
			}
			y++;
		}
		x++;
	}
	draw_ray_floor(args, pos, size);
	x_static += ((double)texture->width / (double)size.y);
	if (x_static >= (int)texture->width || last_texture != texture_direction)
		x_static = 0;
	last_texture = texture_direction;

}

void	raycast_3d(double theta, int ray, double depth, t_args *args, t_vector ray_vector, int flag)
{
	int			clr;
	int			wall_height;
	t_point		rect_pos;
	t_point		rect_size;
	double		scale;

	//printf("tail_x:%i tail_y:%i\n", args->minimap->tile_size.x, args->minimap->tile_size.y);
	scale = (double)args->img->width * 2 / CASTED_RAYS;
	//printf("%f\n", scale);
	clr = 255 / (1 + depth * depth * 0.0001);
	(void)clr;
	depth *= cos(args->player->angle - theta);
	wall_height = 40000 / depth;
	if (wall_height > (int)args->img->height)
		wall_height = args->img->height;
	rect_pos.x = ray * scale / 2;
	rect_pos.y = (args->img->height / 2) - wall_height / 2;
	rect_size.x = scale;
	rect_size.y = wall_height;
	draw_ray_texture(args, rect_pos, rect_size, depth, ray_vector, flag);
	//draw_rectangle(args->img, rect_pos, rect_size, encode_rgb(clr, clr, clr));
}

void	start_ray_vector(t_vector *vector, t_args *args)
{
	vector->p1.x = (int)roundf(args->player->pos.x * args->minimap->tile_size.x \
		+ (double)args->minimap->tile_size.x / 2);
	vector->p1.y = (int)roundf(args->player->pos.y * args->minimap->tile_size.y \
		+ (double)args->minimap->tile_size.y / 2);
}

void	end_ray_vector(t_vector *vect, double theta, double depth)
{
	vect->p2.x = (int)(roundf(vect->p1.x - sin(theta) * depth));
	vect->p2.y = (int)(roundf(vect->p1.y + cos(theta) * depth));
}

void	get_collision_coords(t_point *point, t_vector *ray_vector, t_args *args)
{
	point->x = (int)ray_vector->p2.x / args->minimap->tile_size.x;
	point->y = (int)ray_vector->p2.y / args->minimap->tile_size.y;
}

void	raycaster(t_args *args)
{
	int			ray;
	double		depth;
	t_point		point;
	double		theta;
	t_vector	ray_vector;
	t_point		last_point;
	int			flag;

	last_point.x = -1;
	last_point.y = -1;
	flag = 0;
	ray = 0;
	theta = args->player->angle - HALF_FOV;
	start_ray_vector(&ray_vector, args);
	args->ray = 0;
	while (ray < CASTED_RAYS)
	{
		depth = 0;
		while (depth < MAX_DEPTH)
		{
			end_ray_vector(&ray_vector, theta, depth);
			get_collision_coords(&point, &ray_vector, args);
			if (args->map->grid[point.x][point.y] == '1')
			{
				if (last_point.x != point.x || last_point.y != point.y)
				{
					last_point.x = point.x;
					last_point.y = point.y;
					flag = 1;
				}
				raycast_3d(theta, ray, depth, args, ray_vector, flag);
				draw_line(args->minimap->img, ray_vector, 1, encode_rgb(255, 0, 255));
				flag = 0;
				break ;
			}
			depth += 0.2;
		}
		ray++;
		args->ray++;
		theta += args->step_angle;
	}
}
