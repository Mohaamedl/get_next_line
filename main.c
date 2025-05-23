/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:36:30 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/05/19 11:56:48 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	//int fd = open("tests/1char.txt", O_RDONLY);
	int fd = open("test.txt", O_RDONLY);
	char *line;
	
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}	
	close(fd);
	return (0);
}

