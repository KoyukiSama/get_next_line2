/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:23:59 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/13 17:50:44 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <sys/types.h>

char	*append_buff(char *cache, char *buffer)
{

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
