/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:19:14 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/05/27 09:33:18 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free_all(char **buf, char **stash)
{
	free(*buf);
	free(*stash);
	*stash = NULL;
	return (NULL);
}

void	*ft_init(int *fd, char **buf, char **newline_pos, ssize_t *bytes_read)
{
	if (*fd < 0 || BUFFER_SIZE <= 0 || *fd >= MAX_OPEN)
		return (NULL);
	*buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!*buf)
		return (NULL);
	*newline_pos = NULL;
	*bytes_read = 1;
	return ("");
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
	static char	*stash[MAX_OPEN];
	char		*buf;
	char		*newline_pos;
	char		*line;
	ssize_t		bytes_read[MAX_OPEN];

	if (!ft_init(&fd, &buf, &newline_pos, &bytes_read[fd]))
		return (NULL);
	while (!newline_pos && bytes_read[fd] > 0)
	{
		bytes_read[fd] = read(fd, buf, BUFFER_SIZE);
		if (bytes_read[fd] < 0)
			return (ft_free_all(&buf, &stash[fd]));
		buf[bytes_read[fd]] = '\0';
		newline_pos = stash[fd];
		stash[fd] = ft_strjoin(stash[fd], buf);
		free(newline_pos);
		if (!stash[fd])
			return (ft_free_all(&buf, &stash[fd]));
		newline_pos = ft_strchr(stash[fd], '\n');
	}
	if ((!stash[fd] || *stash[fd] == '\0') && bytes_read[fd] == 0)
		return (ft_free_all(&buf, &stash[fd]));
	return (ft_newline(&buf, &stash[fd], &line, newline_pos));
}
