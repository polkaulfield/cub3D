/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:06:26 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 00:43:31 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "cub3d.h"

# include "structs.h"

int		get_rgba(int r, int g, int b, int a);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	*colorset(void *s, int c, size_t n);
#endif
