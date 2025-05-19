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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			str[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i])
			str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			c_c;

	c_c = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c_c)
		return ((char *) &s[i]);
	return (NULL);
}
