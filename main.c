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
#include <unistd.h>
int main(void)
{
	int			fd;
	int			size;
	char		buffer[1024];	

	fd = open("test.txt", O_RDONLY);
	size = read(fd, buffer, sizeof(buffer));
	printf("Reading %d bytes and got content: %s", size, buffer);
	
}
