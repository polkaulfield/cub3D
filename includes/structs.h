#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	char	*file_name;
	int		fd_file;
	char	player_direction;
	float	x_player;
	float	y_player;
	char	**grid;
	int		height;
	int		width;
	char	*texture[5];
	int		floor[3];
	int		ceiling[3];
}	t_map;


typedef struct s_dpoint
{
	float	x;
	float	y;
}	t_dpoint;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_dvector
{
	t_dpoint	p1;
	t_dpoint	p2;
}	t_dvector;

typedef struct s_vector
{
	t_point	p1;
	t_point	p2;
}	t_vector;

typedef struct s_minimap
{
	t_point		tile_size;
	t_point		size;
	mlx_image_t	*img;
}	t_minimap;

typedef struct s_player
{
	t_dpoint	pos;
	float	fov;
	float	half_fov;
	float	angle;
	float	start_angle;
}	t_player;

typedef struct	s_raycast
{
	float		theta;
	float		depth;
	int			ray;
	int			texture_dir;
	mlx_texture_t	*texture;
	t_dvector	ray_vector;
	t_point		pos;
	t_point		size;
}	t_raycast;
typedef struct s_args
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	t_player	*player;
	t_minimap	*minimap;
	float		scale;
	float		step_angle;
	mlx_texture_t	*texture[4];
	int			*ceiling;
	int			*floor;
	t_raycast	raycast;
}	t_args;

#endif
