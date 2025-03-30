/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:02:18 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/30 18:02:19 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests.h"

void	draw_stuff(t_args *args)
{
	t_point	pos;

	pos.x = 100;
	pos.y = 100;
	draw_circle(args->img, pos, 30, get_rgba(255,255,255,255));
	//mlx_image_to_window(args->mlx, args->img, 0, 0);
}
