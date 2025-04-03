#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"
# include "drawing.h"
# include "parser.h"
# include "minimap.h"
# include "misc.h"

# include "structs.h"

t_player	*init_player(t_map *map);
void	move_player(int key, t_player *player, double len, t_args *args);
void	draw_player_minimap(t_player *player, t_minimap *minimap, t_map *map, mlx_image_t *img);

#endif
