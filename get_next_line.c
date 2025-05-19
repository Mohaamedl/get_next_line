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
#define BUFFER_SIZE

char	*get_line(char *line_bak);

char	*get_next_line(int fd)
{
	char buffer[BUFFER_SIZE];
	char *line;
	static char *line_bak;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPN_FILE)
		return (NULL);
	line = get_line();

}



