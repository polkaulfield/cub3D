/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:27:21 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/09 21:27:21 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	calc_height(char **grid)
{
	int	y;
	int	temp_y;

	y = 0;
	while (grid[y] && !check_line(grid[y], NULL) && grid[y][0] != '\0')
		y++;
	temp_y = y;
	while (grid[temp_y])
	{
		if (!check_line(grid[temp_y], NULL) && grid[temp_y][0] != '\0')
			terminate_error("Error: Wrong map format");
		temp_y++;
	}
	return (y);
}

int	calc_width(char **grid)
{
	int	y;
	int	x;
	int	max_width;

	y = -1;
	max_width = 0;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
			;
		if (max_width < x)
			max_width = x;
	}
	return (max_width);
}

int	char_in_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	**dynamic_arr(char **arr, char *line)
{
	int		i;
	int		j;
	char	**new_arr;

	i = 0;
	if (!arr)
	{
		arr = galloc(2 * sizeof(char *));
		arr[0] = NULL;
		arr[1] = NULL;
	}
	while (arr[i])
		i++;
	new_arr = galloc((i + 2) * sizeof(char *));
	i = 0;
	j = 0;
	while (arr[i])
		new_arr[j++] = add_galloc(ft_strdup(arr[i++]));
	new_arr[j] = add_galloc(ft_strdup(line));
	new_arr[++j] = NULL;
	i = 0;
	gfree_arr((void **)arr);
	return (new_arr);
}
