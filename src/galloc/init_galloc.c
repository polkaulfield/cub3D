/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_galloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:26:40 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:31:45 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/galloc.h"

static t_galloc	*init_galloc_extend(t_galloc *l_galloc)
{
	l_galloc = galloc(0);
	if (!l_galloc)
		exit(1);
	add_galloc(l_galloc);
	gfree(l_galloc);
	free_galloc(l_galloc);
	return (l_galloc);
}

t_galloc	*init_galloc(void)
{
	static int	iter = 0;
	t_galloc	*l_galloc;

	if (iter != 1)
	{
		if (iter == 0)
		{
			iter++;
			l_galloc = NULL;
			init_galloc_extend(l_galloc);
		}
		else
			iter++;
		return (NULL);
	}
	l_galloc = malloc(sizeof(t_galloc));
	if (!l_galloc)
	{
		ft_putendl_fd("", 2);
		exit(EXIT_FAILURE);
	}
	l_galloc->next = NULL;
	l_galloc->mem = NULL;
	l_galloc->start = l_galloc;
	iter++;
	return (l_galloc);
}
