// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "../includes/cub3d.h"
#include "../includes/drawing.h"
#include "../includes/player.h"
#include "../includes/args.h"
#include "../includes/parser.h"
#include "../includes/errors.h"
#include "../includes/tests.h"

#define WIDTH 1920
#define HEIGHT 1080

static void	game_loop(t_args *args)
{
	draw_minimap(args->img, args->minimap, args->map);
	draw_player_minimap(args->player, args->minimap, args->map, args->img);
	mlx_image_to_window(args->mlx, args->img, 0, 0);
}

static void	keys_hook(void* params)
{
	t_args      *args;
	t_player	*player;


	args = (t_args *)params;
	player = args->player;
	if (mlx_is_key_down(args->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(args->mlx);
	if (mlx_is_key_down(args->mlx, MLX_KEY_UP))
	{
		move_player(UP, args->player, 2);
		game_loop(args);
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_DOWN))
		move_player(DOWN, player, 2);
	if (mlx_is_key_down(args->mlx, MLX_KEY_LEFT))
		move_player(LEFT, player, 2);
	if (mlx_is_key_down(args->mlx, MLX_KEY_RIGHT))
		move_player(RIGHT, player, 2);
}

int	main(int argc, char **argv)
{
	mlx_t*		mlx;
	mlx_image_t	*img;
	t_args		*args;
	t_map		*map;

	(void)argc;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		error();
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	init_galloc();
	map = parser(argv[1]);
	args = init_args(img, mlx, map);
	//draw_stuff(args);
	//draw_minimap(args->img, args->minimap, args->map);
	mlx_image_to_window(args->mlx, args->img, 0, 0);
	mlx_loop_hook(args->mlx, keys_hook, args);
	mlx_loop(args->mlx);
	mlx_terminate(args->mlx);
	mlx_terminate(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
