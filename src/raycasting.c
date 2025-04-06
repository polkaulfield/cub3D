#include "../includes/raycasting.h"

/*static int	get_direction(double theta)
{
	//6.28
	if (theta >= 4.71 * 1.5)
		return (1);
	if (theta >= 3.14 * 1.5)
		return (0);
	if (theta >= 1.57 * 1.5)
		return (3);
	if (theta >= 0.785)
		return (2);
	return (2);
}*/

void	draw__floor_ceiling(t_args *args, t_point pos, t_point size)
{
	int x = 0;
	int y = 0;

	while (x < size.x)
	{
		y = 0;
		while (y < pos.y)
		{
			mlx_put_pixel(args->img, x + pos.x, y, get_rgba(0 / (1 + y * y * 0.000005),
															0 / (1 + y * y * 0.000005),
															125 / (1 + y * y * 0.000005),
															255 / (1 + y * y * 0.000005)));
			y++;
		}
		x++;
	}
	x = 0;
	while (x <= size.x)
	{
		y = pos.y + size.y + 1;
		while (y < (int)args->img->height)
		{
			mlx_put_pixel(args->img, x + pos.x, y, get_rgba(0 / (1 + (args->img->height - y) * (args->img->height - y) * 0.000005),
															125 / (1 + (args->img->height - y) * (args->img->height - y) * 0.000005),
															0 / (1 + (args->img->height - y) * (args->img->height - y) * 0.000005),
															255/ (1 + (args->img->height - y) * (args->img->height - y) * 0.000005)));
			y++;
		}
		x++;
	}
}

static int	get_direction_rad(t_point point, t_point wall_point)
{
	//printf("wall x:%i y:%i\n act x:%i y:%i\n", wall_point.x, wall_point.y, point.x, point.y);
	if (wall_point.y > point.y)
		return (0);
	else if (wall_point.y < point.y)
		return (1);
	else if (wall_point.x > point.x)
		return (2);
	else if (wall_point.x < point.x)
		return (3);
	printf("errro in rads\n");
	return (0);
}

static int	get_direction(t_args *args, double depth, double theta, t_point	wall_point)
{
	t_point	point;
	t_vector	ray_vector;
	//t_point	wall_point;

	start_ray_vector(&ray_vector, args);
	while (depth > 0)
	{
		depth -= 0.2;
		end_ray_vector(&ray_vector, theta, depth);
		get_collision_coords(&point, &ray_vector, args);
		if (args->map->grid[point.x][point.y] == '0')
		{
			return (get_direction_rad(point, wall_point));
			break ;
		}
		//wall_point = point;
	}
	printf("errro\n");
	return(0);
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

void	draw_ray_texture(t_args *args, t_point pos, t_point size, double theta, double out_scale, double depth, t_point wall_point, int wall_height)
{
	int	x;
	static int	x_static = 0;
	int	y;
	int	color;
	mlx_texture_t	*texture = args->texture[get_direction(args, depth, theta, wall_point)];
	(void)theta;
	x = 0;
	draw__floor_ceiling(args, pos, size);
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{

			if (pos.x + x < (int)args->img->width && pos.y < (int)args->img->height)
			{
				color = calc_color(texture, pos, size, y, x_static, depth);
				mlx_put_pixel(args->img, pos.x + x, pos.y + y, color);
			}
			y++;
		}
		x++;
	}
	//x_static += x * ((double)texture->width / (double)size.x);
	x_static += x * ((double)texture->width / (double)size.y);//* out_scale;
	(void)out_scale;
	(void)wall_height;
	//printf("%i\n", (int)((double)texture->width / (double)size.x));
	if (x_static >= (int)texture->width)
		x_static = 0;
}

void	raycast_3d(double theta, int ray, double depth, t_args *args, t_point wall_point)
{
	int			clr;
	int			wall_height;
	t_point		rect_pos;
	t_point		rect_size;
	double		scale;

	//printf("tail_x:%i tail_y:%i\n", args->minimap->tile_size.x, args->minimap->tile_size.y);
	scale = args->img->width * 2 / CASTED_RAYS;
	//printf("%f\n", scale);
	clr = 255 / (1 + depth * depth * 0.0001);
	(void)clr;
	depth *= cos(args->player->angle - theta);
	wall_height = 21000 / depth;
	if (wall_height > (int)args->img->height)
		wall_height = args->img->height;
	rect_pos.x = ray * scale / 2;
	rect_pos.y = (args->img->height / 2) - wall_height / 2;
	rect_size.x = scale;
	rect_size.y = wall_height;
	(void)wall_point;
	draw_ray_texture(args, rect_pos, rect_size, theta, scale, depth, wall_point, wall_height);
	//draw_rectangle(args->img, rect_pos, rect_size, encode_rgb(clr, clr, clr));
}

void	start_ray_vector(t_vector *vector, t_args *args)
{
	vector->p1.x = (int)(args->player->pos.x * args->minimap->tile_size.x \
		+ args->minimap->tile_size.x / 2);
	vector->p1.y = (int)(args->player->pos.y * args->minimap->tile_size.y \
		+ args->minimap->tile_size.y / 2);
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

	ray = 0;
	theta = args->player->angle - HALF_FOV;
	start_ray_vector(&ray_vector, args);
	while (ray < CASTED_RAYS)
	{
		depth = 0;
		while (depth < MAX_DEPTH)
		{
			end_ray_vector(&ray_vector, theta, depth);
			get_collision_coords(&point, &ray_vector, args);
			if (args->map->grid[point.x][point.y] == '1')
			{
				raycast_3d(theta, ray, depth, args, point);
				draw_line(args->minimap->img, ray_vector, 1, encode_rgb(255, 0, 255));
				break ;
			}
			depth += 0.2;
		}
		ray++;
		theta += args->step_angle;
	}
}
