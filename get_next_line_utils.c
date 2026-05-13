/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:23:59 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/13 18:37:30 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

static size_t	ft_strlen(char *str);

char	*append_buff(char *cache, char *buffer)
{
	char	*new_cache;
	size_t	i;

	new_cache = malloc(ft_strlen(cache) + ft_strlen(buffer) + 1);
	if (!new_cache)
		return (NULL);
	i = 0;
	while (*cache)
		new_cache[i++] = *cache++;
	while (*buffer)
		new_cache[i++] = *buffer++;
	return (free(cache), new_cache);
}

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	nl(char *str)
{
	if (!str)
		return (0);
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		return (1);
	return (0);
}

void	*read_into_buff(char *buff, int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buff, BUFF_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buff[bytes_read] = '\0';
	return (buff);
}
