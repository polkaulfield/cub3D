/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:07:18 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:18:33 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*colorset(int *s, int c, size_t n)
{
	int	*ptr;

	ptr = (int *) s;
	while (n--)
		*ptr++ = c;
	return (s);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 24 | green << 16 | blue << 8 | 255);
}
