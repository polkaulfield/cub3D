/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohernan <pohernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:07:58 by pohernan          #+#    #+#             */
/*   Updated: 2025/03/20 22:30:09 by pohernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static char	*get_line_from_stash(char **stash, int b_read, bool first_call)
{
	char	*nl_ptr;
	char	*line;
	char	*new_stash;

	if (!*stash)
		return (NULL);
	nl_ptr = ft_strchr(*stash, '\n');
	if (!nl_ptr)
	{
		if (!first_call && b_read <= 0)
		{
			line = ft_strdup(*stash);
			free(*stash);
			*stash = NULL;
			return (line);
		}
		return (NULL);
	}
	line = ft_strndup(*stash, nl_ptr - *stash + 1);
	new_stash = ft_strdup(nl_ptr + 1);
	free(*stash);
	*stash = new_stash;
	return (line);
}

static int	buffer_to_stash(int fd, char **stash)
{
	char	*buffer;
	char	*new_stash;
	int		b_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read <= 0)
	{
		free(buffer);
		return (b_read);
	}
	buffer[b_read] = '\0';
	if (!*stash)
		*stash = ft_strdup(buffer);
	else
	{
		new_stash = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = new_stash;
	}
	free(buffer);
	return (b_read);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[65536] = {0};
	int			b_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = get_line_from_stash(&(stash[fd]), 0, true);
	while (!line)
	{
		b_read = buffer_to_stash(fd, &(stash[fd]));
		line = get_line_from_stash(&(stash[fd]), b_read, false);
		if (!line && b_read <= 0)
			break ;
	}
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("LINE: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (0);
}
*/
