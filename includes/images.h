/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:58:14 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/18 18:25:26 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H
# include "cub3d.h"
# include "params.h"

mlx_image_t	*init_simple_image(int width, int height, int color, t_params *params);

void	add_image_mlx(int x, int y, mlx_image_t *img, t_params *params);

#endif
