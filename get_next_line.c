/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:18 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/05/19 12:55:13 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*stash;            // Static buffer holding leftover data
	char		*buf;
	char		*newline_pos;
	char		*line;
	ssize_t		bytes_read;
	
//	printf("Buffer size: %d", BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	newline_pos = NULL;
	bytes_read = 1;
	while (!newline_pos && bytes_read > 0)
	{
//		printf("inside while.");
		bytes_read = read(fd, buf, BUFFER_SIZE);
//		printf("Bytes read: %zd", bytes_read);
		if (bytes_read < 0)
		{
			free(buf);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buf[bytes_read] = '\0';
		//printf("buf: %s", buf);
		stash = ft_strjoin(stash, buf);
//		printf("stash: %s", stash);
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
		newline_pos = ft_strchr(stash, '\n');
//		printf("newline_pos: %s", newline_pos);	
	}
	free(buf);
	// If nothing was read and stash is empty, clean up and return NULL (EOF)
	if ((!stash || *stash == '\0') && bytes_read == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (newline_pos)
	{
		size_t	line_len = newline_pos - stash + 1;
		line = (char *)malloc(line_len + 1);
		if (!line)
			return (NULL);
		for (size_t i = 0; i < line_len; i++)
			line[i] = stash[i];
		line[line_len] = '\0';
		char *new_stash = ft_strdup(stash + line_len);
		free(stash);
		stash = new_stash;
	}
	else
	{
		line = stash;
		stash = NULL;
	}
	return (line);
}

