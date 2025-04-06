#include "../includes/cub3d.h"
#include "../includes/args.h"
#include "../includes/parser.h"
#include "../includes/errors.h"
#include "../includes/game.h"

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
	args->texture[0] = add_galloc(mlx_load_png("./textures/img_no.png"));
	args->texture[1] = add_galloc(mlx_load_png("./textures/img_ea.png"));
	args->texture[2] = add_galloc(mlx_load_png("./textures/img_so.png"));
	args->texture[3] = add_galloc(mlx_load_png("./textures/img_we.png"));
	game_loop(args);
	mlx_loop_hook(args->mlx, keys_hook, args);
	//mlx_key_hook(args->mlx, keys_hook, args);
	mlx_loop(args->mlx);
	mlx_terminate(args->mlx);
	terminate(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
