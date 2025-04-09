#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"
# include "drawing.h"
# include "parser.h"
# include "minimap.h"
# include "misc.h"
# include "raycasting.h"

# include "structs.h"

t_player	*init_player(t_map *map);
void	move_player(int key, t_player *player, float len, t_args *args);
void	render(t_args *args);

#endif
