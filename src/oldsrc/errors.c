/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:08:08 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/18 18:24:19 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"
#include "../includes/galloc.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	terminate(EXIT_FAILURE);
}
