#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"
# include "drawing.h"
# include "parser.h"

typedef struct s_player
{
	t_dpoint	pos;
	double	fov;
	double	half_fov;
	double	angle;
}	t_player;

t_player	*init_player(t_map *map);

#endif
