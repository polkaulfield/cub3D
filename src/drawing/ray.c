#include "../../includes/drawing.h"

void	draw_ray_ceiling(t_args *args, t_point pos, t_point size)
{
	int		x;
	int		y;
	double	depth;

	x = -1;
	while (++x < size.x)
	{
		y = -1;
		while (++y < pos.y)
		{
			depth = (1 + y * y * 0.000005);
			mlx_put_pixel(args->img, x + pos.x, y, get_rgba(0 / depth,
					0 / depth,
					125 / depth,
					255 / depth));
		}
	}
}

void	draw_ray_floor(t_args *args, t_point pos, t_point size)
{
	int		x;
	int		y;
	double	depth;

	x = -1;
	while (++x <= size.x)
	{
		y = pos.y + size.y;
		while (++y < (int)args->img->height)
		{
			depth = (1 + (args->img->height - y)
					* (args->img->height - y) * 0.000005);
			mlx_put_pixel(args->img, x + pos.x, y, get_rgba(0 / depth,
					125 / depth,
					0 / depth,
					255 / depth));
		}
	}
}
