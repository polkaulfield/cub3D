#include "../includes/keys.h"

/*
void    handle_up_right(t_player *player, t_params *params)
{
    if (mlx_is_key_down(params->mlx, MLX_KEY_UP))
    {
        if (mlx_is_key_down(params->mlx, MLX_KEY_RIGHT))
            move_player(+5, -5, player, params);
        else
		    move_player(0, - 5, player, params);
    }
    if (mlx_is_key_down(params->mlx, MLX_KEY_RIGHT))
    {
        if (mlx_is_key_down(params->mlx, MLX_KEY_UP))
            move_player(+5, -5, player, params);
        else
		    move_player(+5, 0, player, params);
    }
}

void    handle_up_left(t_player *player, t_params *params)
{
    if (mlx_is_key_down(params->mlx, MLX_KEY_UP))
    {
        if (mlx_is_key_down(params->mlx, MLX_KEY_LEFT))
            move_player(-5, -5, player, params);
        else
		    move_player(0, -5, player, params);
    }
    if (mlx_is_key_down(params->mlx, MLX_KEY_LEFT))
    {
        if (mlx_is_key_down(params->mlx, MLX_KEY_UP))
            move_player(-5, -5, player, params);
        else
		    move_player(-5, 0, player, params);
    }
}

void    handle_down_right(t_player *player, t_params *params)
{
    if (mlx_is_key_down(params->mlx, MLX_KEY_DOWN))
    {
        if (mlx_is_key_down(params->mlx, MLX_KEY_RIGHT))
            move_player(+5, +5, player, params);
        else
		    move_player(0, +5, player, params);
    }
    if (mlx_is_key_down(params->mlx, MLX_KEY_RIGHT))
    {
        if (mlx_is_key_down(params->mlx, MLX_KEY_DOWN))
            move_player(+5, +5, player, params);
        else
		    move_player(+5, 0, player, params);
    }
}

void    handle_down_left(t_player *player, t_params *params)
{
    if (mlx_is_key_down(params->mlx, MLX_KEY_DOWN))
    {
        if (mlx_is_key_down(params->mlx, MLX_KEY_LEFT))
            move_player(-5, +5, player, params);
        else
		    move_player(0, +5, player, params);
    }
    if (mlx_is_key_down(params->mlx, MLX_KEY_LEFT))
    {
        if (mlx_is_key_down(params->mlx, MLX_KE    }
    }
}

void	keys_hook(void* args)
{
	t_params	*params;
	t_player	*player;

	params = (t_params *)args;
	player = params->player;
	handle_up_right(player, params);
    handle_up_left(player, params);
    handle_down_right(player, params);
    handle_up_left(player, params);

}
*/

void	keys_hook(void* args)
{
	t_params	*params;
	t_player	*player;

	params = (t_params *)args;
	player = params->player;
	if (mlx_is_key_down(params->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(params->mlx);
	if (mlx_is_key_down(params->mlx, MLX_KEY_UP))
		move_player(0, - 5, player, params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_DOWN))
		move_player(0,  + 5, player, params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_LEFT))
		move_player(- 5, 0, player, params);
	if (mlx_is_key_down(params->mlx, MLX_KEY_RIGHT))
		move_player(+ 5, 0, player, params);
}

