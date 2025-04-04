#include "../includes/raycasting.h"


void	raycast_3d(mlx_image_t *img, double player_angle, double start_angle, int ray, double depth, double scale)
{
	int			color;
	int			wall_height;
	t_point		rect_pos;
	t_point		rect_size;

	color = 255 / (1 + depth * depth * 0.0001);
	depth *= cos(player_angle - start_angle);
	wall_height = 21000 / depth;
	if (wall_height > (int)img->height)
		wall_height = img->height;
	rect_pos.x = ray * scale / 2;
	rect_pos.y = (img->height / 2) - wall_height / 2;
	rect_size.x = scale;
	rect_size.y = wall_height;
	draw_rectangle(img, rect_pos, rect_size, encode_rgb(color, color, color));
}


void	raycaster(mlx_image_t *img, t_args *args)
{
	int			ray;
	double		depth;
	int			col;
	int			row;
	double		start_angle;
	double		player_angle;
	double		scale;
	t_vector	vector;

	ray = 0;
	scale = (img->width * 2) / CASTED_RAYS;
	player_angle = deg2rad(args->player->angle - 90);
	start_angle = player_angle - HALF_FOV;
	vector.p1.x = (int)(args->player->pos.x * args->minimap->tile_size.x + args->minimap->tile_size.x / 2);
	vector.p1.y = (int)(args->player->pos.y * args->minimap->tile_size.y + args->minimap->tile_size.y / 2);
	while (ray < CASTED_RAYS)
	{
		depth = 0;
		while (depth < MAX_DEPTH)
		{
			vector.p2.x = (int)(roundf(vector.p1.x - sin(start_angle) * depth));
			vector.p2.y = (int)(roundf(vector.p1.y + cos(start_angle) * depth));
			row = (int)vector.p2.x / args->minimap->tile_size.x;
			col = (int)vector.p2.y / args->minimap->tile_size.y;
			if (args->map->grid[row][col] == '1')
			{
				raycast_3d(img, player_angle, start_angle, ray, depth, scale);
				draw_line(img, vector, 1, encode_rgb(255, 0, 255));
				break ;
			}
			depth += 0.05;
		}
		ray++;
		start_angle += STEP_ANGLE;
	}
}
