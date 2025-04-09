/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:26:23 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:28:25 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/galloc.h"

void	*add_galloc_arr(void **mem)
{
	int		i;

	i = -1;
	while (mem[++i])
		add_galloc(mem[i]);
	add_galloc(mem);
	return (mem);
}

void	gfree_arr(void **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (arr[i])
			gfree(arr[i]);
	}
	if (arr)
		gfree(arr);
}

void	terminate_error(char *text_error)
{
	ft_putendl_fd(text_error, 2);
	terminate(1);
}
