/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:18:57 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:28:40 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"
#include "../includes/galloc.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	terminate(EXIT_FAILURE);
}
