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
	mlx_image_t	*tmp_img;

	tmp_img = args->img;
	args->img = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	draw_minimap(args->img, args->minimap, args->map);
	render(args);
	mlx_image_to_window(args->mlx, args->img, 0, 0);
	mlx_delete_image(args->mlx, tmp_img);
}

int	key_checker(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || \
		mlx_is_key_down(mlx, MLX_KEY_W) || \
		mlx_is_key_down(mlx, MLX_KEY_S) || \
		mlx_is_key_down(mlx, MLX_KEY_D) || \
		mlx_is_key_down(mlx, MLX_KEY_A) || \
		mlx_is_key_down(mlx, MLX_KEY_DOWN) || \
		mlx_is_key_down(mlx, MLX_KEY_LEFT) || \
		mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		return (1);
	return (0);
}

static void	keys_hook(void *params)
{
	t_args	*args;
	int		flag;

	args = (t_args *)params;
	flag = key_checker(args->mlx);
	if (mlx_is_key_down(args->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(args->mlx);
	if (mlx_is_key_down(args->mlx, MLX_KEY_UP) || \
		mlx_is_key_down(args->mlx, MLX_KEY_W))
		move_player(UP, args->player, 0.2, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_S))
		move_player(S, args->player, -0.2, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_D))
		move_player(D, args->player, 0.2, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_A))
		move_player(A, args->player, -0.2, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_DOWN))
		move_player(DOWN, args->player, 2, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_LEFT))
		move_player(LEFT, args->player, 2, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_RIGHT))
		move_player(RIGHT, args->player, 2, args);
	if (flag == 1)
		game_loop(args);
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
	game_loop(args);
	mlx_image_to_window(args->mlx, args->img, 0, 0);
	mlx_loop_hook(args->mlx, keys_hook, args);
	mlx_loop(args->mlx);
	mlx_terminate(args->mlx);
	terminate(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
