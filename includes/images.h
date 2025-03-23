/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:58:14 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/23 19:45:24 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H
# include "cub3d.h"
# include "params.h"
# include "coords.h"

mlx_image_t	*init_simple_image(int width, int height, int color, t_params *params);
void	add_image_mlx(int x, int y, mlx_image_t *img, t_params *params);
mlx_image_t	*new_image(t_params *params, t_coords size);

#endif
