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
	draw_minimap(args->img, args->minimap, args->map);
	mlx_image_to_window(args->mlx, args->img, 0, 0);
	mlx_loop(args->mlx);
	mlx_terminate(args->mlx);
	mlx_terminate(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
