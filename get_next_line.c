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
/*
stati void	ft_read_save(char * newline_pos, ssize_t bytes_read, char *buf, char *stash)
{
	while (!newline_pos && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
		free(buf);
		free(stash);
		stash = NULLL;
		return (NULL);
		}
	}
}
*/

char	*ft_free_all(char *buf, char* stash)
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
	*bytes_read = 1; // ft_strchr(stash, '\n');
	return " ";	
}
void	*ft_free_stash(char *stash)
{
	free(stash);
	stash = NULL;
	return (NULL);
}

char	*ft_newline(char *stash, char *line, char *newline_pos)
{
	char	*new_stash;

	if (newline_pos)
	{
		size_t	line_len = newline_pos - stash + 1;
		line = ft_substr(stash, 0, line_len);
		new_stash = ft_strdup(stash + line_len);
		free(stash);
		stash = new_stash;
	}
	else
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;    
	char				*temp;
	char		*buf;
	char		*newline_pos;
	char		*line;
	ssize_t		bytes_read;
	
//	printf("Buffer size: %d", BUFFER_SIZE);
	/*
	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	newline_pos = NULL;// ft_strchr(stash, '\n');
	bytes_read = 1;
	*/
	if (!ft_init(&fd, &buf, &newline_pos, &bytes_read))
		return (NULL);
	while (!newline_pos && bytes_read > 0)
	{
//		printf("inside while.");
		bytes_read = read(fd, buf, BUFFER_SIZE);
//		printf("Bytes read: %zd", bytes_read);
		if (bytes_read < 0)
			return (ft_free_all(buf,stash));
		buf[bytes_read] = '\0';
		//printf("buf: %s", buf);
		temp = stash;
		stash = ft_strjoin(stash, buf);
		free(temp);
//		printf("stash: %s", stash);
		if (!stash)
			return (ft_free_all(buf, stash));
		newline_pos = ft_strchr(stash, '\n');
//		printf("newline_pos: %s", newline_pos);	
	}
	free(buf);
	// If nothing was read and stash is empty, clean up and return NULL (EOF)
	if ((!stash || *stash == '\0') && bytes_read == 0)
		return (ft_free_stash(stash));
	/*
	if (newline_pos)
	{
		size_t	line_len = newline_pos - stash + 1;
		line = ft_substr(stash, 0, line_len);
		char *new_stash = ft_strdup(stash + line_len);
		free(stash);
		stash = new_stash;
	}
	else
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
	}
	*/
	line = ft_newline(stash, line, newline_pos);
	return (line);
}




