/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:22:15 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 00:43:00 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	start_ray_vector(t_dvector *vector, t_args *args)
{
	vector->p1.x = args->player->pos.x;
	vector->p1.y = args->player->pos.y;
}

void	end_ray_vector(t_dvector *vect, t_raycast *raycast)
{
	vect->p2.x = vect->p1.x - sin(raycast->theta) * raycast->depth;
	vect->p2.y = vect->p1.y + cos(raycast->theta) * raycast->depth;
}

void	get_collision_coords(t_point *point, t_dvector *ray_vector)
{
	point->x = (int)roundf(ray_vector->p2.x);
	point->y = (int)roundf(ray_vector->p2.y);
}
