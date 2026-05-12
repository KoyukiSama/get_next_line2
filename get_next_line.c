/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:23:55 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/12 22:18:02 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

char	*get_next_line(int fd)
{
	static char	*cache[OPEN_MAX] = {0};
	char		*line;

	if (BUFF_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	update_cache(fd, cache[fd]);
	if (!cache[fd])
		return (NULL);
	cache_get_line(line, cache[fd]);
	cache_trim(cache[fd]);
	return (line);
}

static char	*cache_update(int fd, char *cache)
{
	
}

static char	*cache_get_line(char *line, char *cache);

static char	*cache_trim(char *cache);
