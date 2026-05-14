/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:23:59 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/14 17:52:01 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

static size_t	ft_strlen(char *str);

char	*append_buff(char **cache, char *buffer)
{
	char	*new_cache;
	char	*old_cache;
	size_t	i;

	old_cache = *cache;
	if (!old_cache || !buffer)
		return (NULL);
	new_cache = malloc(ft_strlen(old_cache) + ft_strlen(buffer) + 1);
	if (!new_cache)
		return (NULL);
	i = 0;
	while (old_cache[i])
	{
		new_cache[i] = old_cache[i];
		i++;
	}
	while (*buffer)
		new_cache[i++] = *buffer++;
	new_cache[i] = '\0';
	*cache = new_cache;
	return (free(old_cache), new_cache);
}

static size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
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

char	*read_into_buff(char *buff, int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buff, BUFF_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buff[bytes_read] = '\0';
	return (buff);
}
