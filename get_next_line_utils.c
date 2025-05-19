/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:20 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/05/19 12:55:21 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
	{
		size++;
	}
	return (size);
}
void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *) s;
	while (n > 0)
	{
		*(temp++) = 0;
		n--;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*temp;

	if (size && SIZE_MAX/size < n)
		return NULL;
	temp = malloc(n * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, n * size);
	return (temp);
}
