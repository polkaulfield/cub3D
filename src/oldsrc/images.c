/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:04:21 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/26 19:43:37 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/images.h"
#include "../includes/errors.h"
#include "../includes/color.h"
#include "../includes/coords.h"

mlx_image_t	*init_simple_image(int width, int height, int color, t_params *params)
{
	mlx_image_t*	img;

	img = mlx_new_image(params->mlx, width, height);
	if (!img)
		error();
	colorset(img->pixels, color , img->width * img->height);
	return (img);
}

mlx_image_t	*new_image(t_params *params, int width, int height)
{
	mlx_image_t	*img;

	img = mlx_new_image(params->mlx, width, height);
	if (!img)
		error();
	return (img);
}

void	add_image_mlx(int x, int y, mlx_image_t *img, t_params *params)
{
	if (mlx_image_to_window(params->mlx, img, x, y))
		error();
}
