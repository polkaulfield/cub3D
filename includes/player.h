#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"
# include "drawing.h"
# include "parser.h"
# include "minimap.h"

typedef struct s_player
{
	t_dpoint	pos;
	double	fov;
	double	half_fov;
	double	angle;
}	t_player;

t_player	*init_player(t_map *map);
void	move_player(int key, t_player *player, double len);
void	draw_player_minimap(t_player *player, t_minimap *minimap, t_map *map, mlx_image_t *img);

#endif
