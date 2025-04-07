#ifndef GAME_H
# define GAME_H
# include "cub3d.h"
# include "player.h"
# include "args.h"
# include "parser.h"
# include "errors.h"

void	keys_hook(void *params);
void	game_loop(void *params);
#endif