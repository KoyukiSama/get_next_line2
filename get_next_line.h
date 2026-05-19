/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaclaes <kaclaes@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:24:02 by kaclaes           #+#    #+#             */
/*   Updated: 2026/05/19 14:23:50 by kaclaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  define BUFF_SIZE BUFFER_SIZE
# else
#  define BUFF_SIZE	6
# endif
# define OPEN_MAX 1024

// stash_strt_ptr is the malloc pointer
// stash is a modified ptr
typedef struct s_stash
{
	char	*stash;
	char	*stash_strt_ptr;
}	t_stash;

char	*get_next_line(int fd);

#endif