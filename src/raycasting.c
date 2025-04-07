#include "../includes/raycasting.h"


/*static int	get_direction_grades(double theta)
{
	//6.28
	//printf("%f\n", theta);
	if (theta > deg2rad(45) && theta < deg2rad(135))
		return (0);
	if (theta > deg2rad(135) && theta < deg2rad(225))
		return (1);
	if (theta > deg2rad(225) && theta < deg2rad(315))
		return (0);
	printf("Norte\n");
	return (1);
}*/

/*static int	get_direction_rad(t_point point, t_point wall_point, double theta)
{
	(void)theta;
	///get_direction_grades(theta);//debug
	//printf("wall x:%i y:%i\n act x:%i y:%i\n", wall_point.x, wall_point.y, point.x, point.y);
	*//*if (wall_point.y < point.y && wall_point.x < point.x)
	{
		if (get_direction_grades(theta))
			return WE;
		return NO;
	}
	else if (wall_point.y > point.y && wall_point.x > point.x)
	{
		if (get_direction_grades(theta))
			return EA;
		return SO;
	}
	else if (wall_point.y > point.y && wall_point.x < point.x)
	{
		if (get_direction_grades(theta))
			return WE;
		return SO;
	}
	else if (wall_point.y < point.y && wall_point.x > point.x)
	{
		if (get_direction_grades(theta))
			return EA;
		return NO;
	}*//*
	if (wall_point.y > point.y)
		return (SO);//S
	else if (wall_point.y < point.y)
		return (NO);//N
	else if (wall_point.x > point.x)
		return (EA);//E
	else if (wall_point.x < point.x)
		return (WE);//W
	printf("errro in rads\n");
	return (0);
}*/

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

/*static int	get_direction(t_args *args, double depth, double theta, t_point	wall_point)
{
	t_point	point;
	t_vector	ray_vector;

	//t_point	aprox;

	//t_point	wall_point;
	//printf("wall x:%i y:%i\n", wall_point.x, wall_point.y);
	start_ray_vector(&ray_vector, args);
	while (depth > 0)
	{
		end_ray_vector(&ray_vector, theta, depth);
		get_collision_coords(&point, &ray_vector, args);
		if (args->map->grid[point.x][point.y] != '1')
		{

			//printf("adyacente x:%i y:%i\n\n\n", point.x, point.y);
			return (get_direction_rad(point, wall_point, theta));
			break ;
		}
		//printf("%c\n", args->map->grid[point.x][point.y]);
		//wall_point = point;
		depth -= 0.2;
	}
	printf("error  %f\n", depth);
	return(0);
}*/

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

void	draw_ray_texture(t_args *args, t_point pos, t_point size, double theta, double out_scale, double depth, t_point wall_point, int wall_height, t_vector ray_vector)
{
	int	x;
	static double	x_static = 0;
	static int	last_texture = 0;
	int	y;
	int	color;
	int	texture_direction = get_texture_dir(&ray_vector, args);//get_direction(args, depth, theta, wall_point);
	mlx_texture_t	*texture = args->texture[texture_direction];
	x = 0;
	//draw__floor_ceiling(args, pos, size);
	draw_ray_ceiling(args, pos, size);
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
		//x_static += x * ((double)texture->width / ((double)size.y));
	}
	draw_ray_floor(args, pos, size);
	x_static += ((double)texture->width / (double)size.y);
	//printf("%f\n", x_static);
	//printf("%i\n", (int)((double)texture->width / (double)size.x));
	if (x_static >= (int)texture->width || last_texture != texture_direction)
		x_static = 0;
	last_texture = texture_direction;
	(void)out_scale;
	(void)wall_height;
	(void)wall_point;
	(void)theta;
}

void	raycast_3d(double theta, int ray, double depth, t_args *args, t_point wall_point, t_vector ray_vector)
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
	wall_height = 40000 / depth;
	if (wall_height > (int)args->img->height)
		wall_height = args->img->height;
	rect_pos.x = ray * scale / 2;
	rect_pos.y = (args->img->height / 2) - wall_height / 2;
	rect_size.x = scale;
	rect_size.y = wall_height;
	(void)wall_point;
	draw_ray_texture(args, rect_pos, rect_size, theta, scale, depth, wall_point, wall_height, ray_vector);
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
	while (ray < CASTED_RAYS * 2)
	{
		depth = 0;
		while (depth < MAX_DEPTH)
		{
			end_ray_vector(&ray_vector, theta, depth);
			get_collision_coords(&point, &ray_vector, args);
			if (args->map->grid[point.x][point.y] == '1')
			{
				raycast_3d(theta, ray, depth, args, point, ray_vector);
				draw_line(args->minimap->img, ray_vector, 1, encode_rgb(255, 0, 255));
				break ;
			}
			depth += 0.2;
		}
		ray++;
		theta += args->step_angle;
	}
}
