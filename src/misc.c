/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:19:09 by pohernan          #+#    #+#             */
/*   Updated: 2025/04/10 15:48:28 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/misc.h"

float	deg2rad(float angle)
{
	return (angle * MPI / 180);
}

static char	char_in_set(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*trim_str(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	trim_len;
	size_t	i;
	char	*str;

	if (!s1)
		return (0);
	start = 0;
	while (char_in_set(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	if (start == end - 1)
		return ((char *)ft_strdup(s1));
	while (char_in_set(s1[end - 1], set) && start < end)
		end--;
	trim_len = end - start + 1;
	str = (char *)malloc(sizeof (char) * trim_len);
	if (!str)
		return (0);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
