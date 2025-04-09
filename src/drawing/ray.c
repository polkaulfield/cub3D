#include "../../includes/drawing.h"

void	draw_multiple_pixels(mlx_image_t *img, int x, int y, int color)
{
	printf("hola");
	mlx_put_pixel(img, x, y, color);
	mlx_put_pixel(img, x + 1, y, color);
	mlx_put_pixel(img, x, y + 1, color);
	mlx_put_pixel(img, x + 1, y + 1, color);
}

void	draw_ray_ceiling(t_args *args, t_point pos, t_point size)
{
	int			y;
	double		depth;
	int			color;

	//color = args->ceiling;
	y = -1;
	(void)size;
	while (++y < pos.y)
	{
		printf("hola\n");
		depth = (1 + y * y * 0.000005);
		color = get_rgba(args->ceiling[0] / depth, args->ceiling[1] / depth, args->ceiling[2] / depth, 255);
		if (pos.x < (int)args->img->width && pos.y + y < (int)args->img->height)
		{
			draw_multiple_pixels(args->img, pos.x, pos.y + y, color);
			y++;
		}
		else
		{
			mlx_put_pixel(args->img, pos.x, pos.y + y, color);
			mlx_put_pixel(args->img, pos.x + 1, pos.y + y, color);
		}
	}
}

void	draw_ray_floor(t_args *args, t_point pos, t_point size)
{
	int		x;
	int		y;
	double	depth;
	int		*color;

	color = args->floor;
	x = -1;
	while (++x <= size.x)
	{
		y = pos.y + size.y;
		while (++y < (int)args->img->height)
		{
			if (pos.x + x < (int)args->img->width && pos.y < (int)args->img->height)
			{
				depth = (1 + (args->img->height - y)
						* (args->img->height - y) * 0.000005);
				mlx_put_pixel(args->img, x + pos.x, y, get_rgba(color[0] / depth,
						color[1] / depth,
						color[2] / depth,
						255 / depth));
			}
		}
	}
}
