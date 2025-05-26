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

char	*ft_free_all(char *buf, char *stash)
{
	free(buf);
	free(stash);
	stash = NULL;
	return (NULL);
}

void	*ft_init(int *fd, char **buf, char **newline_pos, ssize_t *bytes_read)
{
	if (*fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	*buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!*buf)
		return (NULL);
	*newline_pos = NULL;
	*bytes_read = 1;
	return ("");
}

void	*ft_free_stash(char *stash)
{
	free(stash);
	stash = NULL;
	return (NULL);
}

char	*ft_newline(char **buf, char **stash, char **line, char *newline_pos)
{
	char	*new_stash;
	size_t	line_len;

	free(*buf);
	if (newline_pos)
	{
		line_len = newline_pos - *stash + 1;
		*line = ft_substr(*stash, 0, line_len);
		new_stash = ft_strdup(*stash + line_len);
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		*line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*newline_pos;
	char		*line;
	ssize_t		bytes_read;

	if (!ft_init(&fd, &buf, &newline_pos, &bytes_read))
		return (NULL);
	while (!newline_pos && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free_all(buf, stash));
		buf[bytes_read] = '\0';
		newline_pos = stash;
		stash = ft_strjoin(stash, buf);
		free(newline_pos);
		if (!stash)
			return (ft_free_all(buf, stash));
		newline_pos = ft_strchr(stash, '\n');
	}
	if ((!stash || *stash == '\0') && bytes_read == 0)
		return (ft_free_all(buf, stash));
	return (ft_newline(&buf, &stash, &line, newline_pos));
}
