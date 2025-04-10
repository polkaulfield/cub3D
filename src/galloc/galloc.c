/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:26:51 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 15:59:23 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/galloc.h"

void	terminate(int exit_value)
{
	free_galloc(NULL);
	exit(exit_value);
}

void	free_galloc(t_galloc *galloc)
{
	static t_galloc	*l_galloc = NULL;
	t_galloc		*temp_galloc;
	t_galloc		*list_galloc;

	if (!l_galloc)
	{
		l_galloc = galloc;
		return ;
	}
	list_galloc = l_galloc->start;
	while (list_galloc)
	{
		temp_galloc = list_galloc;
		list_galloc = list_galloc->next;
		if (temp_galloc && temp_galloc->mem)
			free(temp_galloc->mem);
		if (temp_galloc)
			free(temp_galloc);
	}
}

void	*add_galloc(void *mem)
{
	static t_galloc	*l_galloc = NULL;
	t_galloc		*n_galloc;

	if (!l_galloc)
	{
		l_galloc = mem;
		return (mem);
	}
	while (l_galloc->next)
		l_galloc = l_galloc->next;
	if (!mem)
		return (NULL);
	n_galloc = malloc(sizeof(t_galloc));
	if (!n_galloc)
		terminate(EXIT_FAILURE);
	n_galloc->mem = mem;
	n_galloc->next = NULL;
	n_galloc->start = l_galloc->start;
	l_galloc->next = n_galloc;
	l_galloc = n_galloc;
	return (mem);
}

void	gfree(void *ptr)
{
	static t_galloc	*l_galloc;
	t_galloc		*mem_node;
	t_galloc		*prev_node;

	if (!l_galloc)
	{
		l_galloc = ptr;
		return ;
	}
	mem_node = l_galloc->start;
	prev_node = NULL;
	while (mem_node)
	{
		if (mem_node->mem == ptr)
		{
			free(ptr);
			mem_node->mem = NULL;
			if (prev_node)
				prev_node->next = mem_node->next;
			free(mem_node);
			return ;
		}
		prev_node = mem_node;
		mem_node = mem_node->next;
	}
}
//ptr = NULL

void	*galloc(size_t size)
{
	static t_galloc	*l_galloc = NULL;
	t_galloc		*n_galloc;
	void			*mem;

	if (!l_galloc)
	{
		l_galloc = init_galloc();
		return (l_galloc);
	}
	while (l_galloc->next)
		l_galloc = l_galloc->next;
	n_galloc = malloc(sizeof(t_galloc));
	if (!n_galloc)
		terminate(EXIT_FAILURE);
	mem = ft_calloc(1, size);
	if (!mem)
		terminate(EXIT_FAILURE);
	n_galloc->mem = mem;
	n_galloc->next = NULL;
	n_galloc->start = l_galloc->start;
	l_galloc->next = n_galloc;
	l_galloc = n_galloc;
	return (mem);
}
