/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:23:55 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/13 18:36:48 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

void		*read_into_buff(char *buff, int fd);
char		*append_buff(char *cache, char *buffer);
int			nl(char *str);

static void	*cache_update(int fd, char *cache);
// static void	cache_get_line(char *line, char *cache);
// static void	cache_trim(char *cache);

char	*get_next_line(int fd)
{
	static char	*cache[OPEN_MAX] = {NULL};
	char		*line;

	if (BUFF_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!update_cache(fd, cache[fd]))
		return (NULL);
	// cache_get_line(line, cache[fd]);
	// cache_trim(cache[fd]);
	return (line);
}

// returns NULL if error occurs
static void	*cache_update(int fd, char *cache)
{
	char	*buff;

	if (!cache)
		cache = malloc(1);
	if (cache)
		cache[0] = '\0';
	else
		return (NULL);
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (free(cache), NULL);
	while (!nl(cache))
	{
		if (!read_into_buff(buff, fd));
			return (free(buff), free(cache), NULL);
		if (buff[0] == '\0')
			return (free(buff), cache);
		if (!append_buff(cache, buff))
			return (free(buff), free(cache), NULL);
	}
	return (cache);
}

// static void	cache_get_line(char *line, char *cache)

// static void	cache_trim(char *cache)
