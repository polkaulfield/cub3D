#include "../../includes/drawing.h"

void	draw_ray_ceiling(t_args *args, t_point pos, t_point size)
{
	int		x;
	int		y;
	double	depth;
	int		*color;

	color = args->ceiling;
	x = -1;
	while (++x < size.x)
	{
		y = -1;
		while (++y < pos.y)
		{
			if (pos.x + x < (int)args->img->width && pos.y < (int)args->img->height)
			{
				depth = (1 + y * y * 0.000005);
				mlx_put_pixel(args->img, x + pos.x, y, get_rgba(color[0] / depth,
						color[1] / depth,
						color[2] / depth,
						255 / depth));

			}
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
			//mlx_put_pixel(args->img, x + pos.x, y, get_rgba(255,255,255,255));
		}
	}
}
