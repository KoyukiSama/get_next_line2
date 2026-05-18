/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:23:55 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/18 16:01:51 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

char		*read_into_buff(char *buff, int fd);
char		*append_buff(char **cache, char *buffer);
int			nl(char *str);

static char	*cache_update(int fd, char **cache);
static char	*cache_get_line(char **line, char *cache);
static char	*cache_trim(char **cache);

char	*get_next_line(int fd)
{
	static char	*cache[OPEN_MAX] = {NULL};
	char		*line;

	line = NULL;
	if (BUFF_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!cache_update(fd, &cache[fd]) || cache[fd][0] == '\0')
		return (free(cache[fd]), cache[fd] = NULL, NULL);
	if (!cache_get_line(&line, cache[fd]))
		return (free(cache[fd]), cache[fd] = NULL, NULL);
	if (!cache_trim(&cache[fd]))
	{
		free(cache[fd]);
		cache[fd] = NULL;
	}
	return (line);
}

// returns NULL if error occurs
static char	*cache_update(int fd, char **cache)
{
	char	*buff;

	if (!*cache)
	{
		*cache = malloc(1);
		if (!*cache)
			return (NULL);
		(*cache)[0] = '\0';
	}
	buff = malloc((BUFF_SIZE + 1));
	if (!buff)
		return (free(*cache), NULL);
	while (!nl(*cache))
	{
		if (!read_into_buff(buff, fd))
			return (free(buff), NULL);
		if (buff[0] == '\0')
			return (free(buff), *cache);
		if (!append_buff(cache, buff))
			return (free(buff), NULL);
	}
	return (free(buff), *cache);
}

static char	*cache_get_line(char **line, char *cache)
{
	size_t	line_size;
	size_t	i;

	line_size = 0;
	while (cache[line_size] != '\n' && cache[line_size])
		line_size++;
	*line = malloc(line_size + 2);
	if (!*line)
		return (NULL);
	i = 0;
	while (cache[i] != '\n' && cache[i])
	{
		(*line)[i] = cache[i];
		i++;
	}
	if (cache[i] == '\n')
		(*line)[i++] = '\n';
	(*line)[i] = '\0';
	return (*line);
}

static char	*cache_trim(char **cache)
{
	char	*old_cache;
	char	*new_cache;
	size_t	i;

	old_cache = *cache;
	while (*old_cache != '\n' && *old_cache)
		old_cache++;
	if (*old_cache == '\0' || *(old_cache + 1) == '\0')
		return (NULL);
	old_cache++;
	i = 0;
	while (old_cache[i])
		i++;
	new_cache = malloc(i + 1);
	if (!new_cache)
		return (NULL);
	i = 0;
	while (*old_cache)
		new_cache[i++] = *old_cache++;
	new_cache[i] = '\0';
	return (free(*cache), *cache = new_cache, *cache);
}
