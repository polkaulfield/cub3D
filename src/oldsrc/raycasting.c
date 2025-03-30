#include "../includes/raycasting.h"
#include <math.h>
#include "../includes/drawing.h"

void	raycaster(t_params *params)
{
    int ray;
    double depth;
    double target_x;
    double target_y;
    int     col;
    int     row;
    double  start_angle;
    t_coords   pos;

    ray = 0;
    start_angle = 0;
    while (ray < params->casted_rays)
    {
        depth = 0;
        while (depth < params->max_depth)
        {
            printf("INSIDE CASTER\n");
            target_x = params->player->x - sin(start_angle) * depth;
            target_y = params->player->y - cos(start_angle) * depth;
            params->player->pos.x = params->player->x;
            params->player->pos.y = params->player->y;
            pos.x = target_x;
            pos.y = target_y;
            col =  (int)target_x / params->tile_size;
            row = (int)target_y / params->tile_size;
            if (params->map->grid[row][col] == '1')
            {
                printf("CASTING RAY!\n");
                draw_line(params->img, params->player->pos, pos, get_rgba(255, 0, 255, 255));
                break ;
            }
            depth++;
        }
        ray++;
        start_angle += 5;
    }
}