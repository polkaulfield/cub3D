#include "../includes/raycasting.h"
#include <math.h>

void	raycaster(t_params *params)
{
    int ray;
    double depth;
    double target_x;
    double target_y;
    int     col;
    int     row;

    ray = 0;
    while (ray < params->casted_rays)
    {
        depth = 0;
        while (depth < params->max_depth)
        {
            target_x = params->player->x - sin(0) * depth;
            target_y = params->player->x - cos(0) * depth;
            
            col =  target_x / params->tile_size;
            row = target_y / params->tile_size;

        }
    }
}