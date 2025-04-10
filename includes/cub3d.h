/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:17:40 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 14:48:56 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "structs.h"
# include <string.h>
# ifndef MPI
#  define WIDTH 1920
#  define HEIGHT 1080
#  define MPI 3.141592
#  define TWOPI 6.283184
#  define FOV 1.047197551
#  define HALF_FOV 0.523598776
#  define CASTED_RAYS WIDTH
#  define MAX_DEPTH 100
#  define DIR_CHECK_STEP 0.005
#  define UP 0
#  define DOWN 1
#  define LEFT 2
#  define RIGHT 3
#  define W 4
#  define S 5
#  define A 6
#  define D 7
# endif
#endif
