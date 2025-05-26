#include "get_next_line_bonus.h"
#define MAX_OPEN 1024

#ifndef  s_dict
# define s_dict {

}



char	*get_next_line(int fd)
{
	static char	*stash[MAX_OPEN];    
	char				*temp;
	char				*buf;
	char				*newline_pos;
	char				*line;
	ssize_t			bytes_read;
	int					i;

	i = 0;
//	printf("Buffer size: %d", BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	buf[i] = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	newline_pos = NULL;// ft_strchr(stash, '\n');
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
		temp = stash;
		stash = ft_strjoin(stash, buf);
		free(temp);
//		printf("stash: %s", stash);
		if (!stash)
		{
			free(buf);
			free(stash);
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
	return (line);
}

