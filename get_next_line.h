/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:21 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/05/19 12:55:07 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# def GET_NEXT_LINE

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);


#endif
