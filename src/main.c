// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "../includes/cub3d.h"
#include "../includes/params.h"
#include "../includes/parser.h"
#include "../includes/errors.h"
#include "../includes/drawing.h"
#include "../includes/player.h"
#include "../includes/moves.h"
#include "../includes/keys.h"

#define WIDTH 512
#define HEIGHT 512

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

int	main(int argc, char **argv)
{
	mlx_t*		mlx;
	t_map		*map;
	t_params	*params;

	if (argc != 2)
	{
		ft_putendl_fd("Error: Waiting 2 arguments", 2);
		exit (1);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		error();
	init_galloc();
	map = parser(argv[1]);
	params = init_params(mlx, map);
	draw_grid(params);
	move_player(0, 0, params->player, params);
	mlx_loop_hook(mlx, keys_hook, params);
	mlx_loop(mlx);
	free(params->player);
	free(params->map->grid);
	free(params->map);
	free(params);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
