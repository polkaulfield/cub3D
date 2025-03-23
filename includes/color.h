/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:06:26 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/20 21:39:15 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "cub3d.h"

int		get_rgba(int r, int g, int b, int a);
void	*colorset(void *s, int c, size_t n);
#endif
