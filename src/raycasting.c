#include "../includes/raycasting.h"

void	raycaster(mlx_image_t *img, t_map *map, t_minimap *minimap, t_player *player)
{
	int			ray;
	double		depth;
	int			col;
	int			row;
	double		start_angle;
	t_vector	vector;

	ray = 0;
	start_angle = deg2rad(player->angle - 90) - HALF_FOV;
	printf("tile size x: %d y: %d\n", minimap->tile_size.x, minimap->tile_size.y);
	vector.p1.x = (int)(player->pos.x * minimap->tile_size.x + minimap->tile_size.x / 2);
	vector.p1.y = (int)(player->pos.y * minimap->tile_size.y + minimap->tile_size.y / 2);
	while (ray < CASTED_RAYS)
	{
		depth = 0;
		while (depth < MAX_DEPTH)
		{
			printf("INSIDE CASTER\n");
			vector.p2.x = (int)(vector.p1.x - sin(start_angle) * depth);
			vector.p2.y = (int)(vector.p1.y + cos(start_angle) * depth);
			printf("Target x: %d Target y: %d\n", vector.p2.x, vector.p2.y);
			row = (int)vector.p2.x / minimap->tile_size.x;
			col = (int)vector.p2.y / minimap->tile_size.y;
			printf("Col x: %d Row y: %d\n", col, row);
			if (map->grid[row][col] == '1')
			{
				printf("CASTING RAY!\n");
				(void)img;
				draw_line(img, vector, 1, encode_rgb(255, 0, 255));
				break ;
			}
			depth += 4;
		}
		ray++;
		start_angle += STEP_ANGLE;
	}
}
