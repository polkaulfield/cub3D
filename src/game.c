/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:28:48 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 16:25:51 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/player.h"

static void	put_map_on_img(mlx_image_t *img_map, mlx_image_t *img)
{
	unsigned int		x;
	unsigned int		y;

	y = 0;
	while (y < img_map->height)
	{
		x = 0;
		while (x < img_map->width)
		{
			memcpy(&img->pixels[(y * img->width + x) * 4], \
				&img_map->pixels[(y * img_map->width + x) * 4], 4);
			x++;
		}
		y++;
	}
}

void	game_loop(void *params)
{
	mlx_image_t	*tmp_img;
	mlx_image_t	*tmp_minimap_img;
	t_args		*args;

	args = (t_args *)params;
	tmp_img = args->img;
	tmp_minimap_img = args->minimap->img;
	args->img = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	args->minimap->img = mlx_new_image(args->mlx, WIDTH / 4, HEIGHT / 4);
	draw_minimap(args);
	raycaster(args);
	put_map_on_img(args->minimap->img, args->img);
	mlx_image_to_window(args->mlx, args->img, 0, 0);
	mlx_delete_image(args->mlx, tmp_img);
	mlx_delete_image(args->mlx, tmp_minimap_img);
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

void	delete_texture(t_args *args)
{
	mlx_delete_texture(args->texture[NO]);
	mlx_delete_texture(args->texture[SO]);
	mlx_delete_texture(args->texture[WE]);
	mlx_delete_texture(args->texture[EA]);
}

void	keys_hook(void *params)
{
	t_args	*args;

	args = (t_args *)params;
	if (mlx_is_key_down(args->mlx, MLX_KEY_ESCAPE))
	{
		delete_texture(args);
		mlx_close_window(args->mlx);
		terminate(1);
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_W))
		move_player(UP, args->player, 0.1, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_S))
		move_player(S, args->player, -0.1, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_D))
		move_player(D, args->player, 0.1, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_A))
		move_player(A, args->player, -0.1, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_LEFT))
		move_player(LEFT, args->player, -0.1, args);
	if (mlx_is_key_down(args->mlx, MLX_KEY_RIGHT))
		move_player(RIGHT, args->player, 0.1, args);
	if (key_checker(args->mlx))
		game_loop(args);
}
