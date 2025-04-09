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
	return(	get_rgba(texture->pixels[index + 0] / (1 + depth * depth * 0.0001),
					texture->pixels[index + 1] / (1 + depth * depth * 0.0001),
					texture->pixels[index + 2] / (1 + depth * depth * 0.0001),
					texture->pixels[index + 3] / (1 + depth * depth * 0.0001)));
}

void	draw_ray_texture(t_args *args, t_point pos, t_point size, double depth, t_dvector ray_vector)
{
	int	x;
	int	y;
  double  x_2;
	int	color;
	int	texture_direction;
	mlx_texture_t	*texture;
	
  x = 0;
  x_2 = 0;
	texture_direction = get_texture_dir(&ray_vector, args);
  texture = args->texture[texture_direction];
	draw_ray_ceiling(args, pos, size);
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			if (texture_direction == NO || texture_direction == SO)
				x_2 = ray_vector.p2.x - (ray_vector.p2.x + 0.5) * texture->width;
			else
				x_2 = ray_vector.p2.y - (ray_vector.p2.y + 0.5) * texture->width;
			if (pos.x + x < (int)args->img->width && pos.y < (int)args->img->height)
			{
				color = calc_color(texture, pos, size, y, x_2, depth);
				mlx_put_pixel(args->img, pos.x + x, pos.y + y, color);
			}
			y++;
		}
		x++;
	}
	draw_ray_floor(args, pos, size);
}

void	raycast_3d(double theta, int ray, double depth, t_args *args, t_dvector ray_vector)
{
	int			clr;
	int			wall_height;
	t_point		rect_pos;
	t_point		rect_size;
	double		scale;

  	scale = (double)args->img->width * 2 / CASTED_RAYS;
	//printf("%f\n", scale);
	clr = 255 / (1 + depth * depth * 0.05);
	(void)clr;
  	(void)theta;
	depth *= cos(args->player->angle - theta);
	wall_height = roundf(args->img->width / depth);
	if (wall_height > (int)args->img->height)
		wall_height = args->img->height;
	rect_pos.x = ray * scale / 2;
	rect_pos.y = (args->img->height / 2) - wall_height / 2;
	rect_size.x = scale;
	rect_size.y = wall_height;
  	(void)ray_vector;
  	draw_ray_texture(args, rect_pos, rect_size, depth, ray_vector);
	//draw_rectangle(args->img, rect_pos, rect_size, encode_rgb(clr, clr, clr));
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

void	raycaster(t_args *args)
{
	int			ray;
	double		depth;
	t_point		point;
	double		theta;
	t_dvector	ray_vector;

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
			get_collision_coords(&point, &ray_vector);
			if (args->map->grid[point.x][point.y] == '1')
			{
				//printf("%f %f\n", ray_vector.p2.x, ray_vector.p2.y);
				raycast_3d(theta, ray, depth, args, ray_vector);
				draw_line(args->minimap->img, get_ray_minimap(&ray_vector, args), 1, encode_rgb(255, 0, 255));
				break ;
			}
			depth += 0.001;
		}
		ray++;
		args->ray++;
		theta += args->step_angle;
	}
}
/*void	draw_ray_texture(t_args *args, t_point pos, t_point size, double depth, t_dvector ray_vector)
{
	int	x;
	static double	x_static = 0;
	static int	last_texture = 0;
	int	y;
	int	color;
	int	texture_direction = get_texture_dir(&ray_vector, args);
	mlx_texture_t	*texture = args->texture[texture_direction];
	x = 0;
	//x_static = ((int)((double)ray_vector.p2.x / (double)args->minimap->tile_size.x) + 1.0 - ((double)ray_vector.p2.x / (double)args->minimap->tile_size.x)) * texture->width;
	draw_ray_ceiling(args, pos, size);
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			x_static = ray_vector.p2.x + 1.0 - ray_vector.p2.x * texture->width;
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
	//x_static += ((double)texture->width / (double)size.y);
	if (x_static >= (int)texture->width || last_texture != texture_direction)
		x_static = 0;
	last_texture = texture_direction;

}*/
