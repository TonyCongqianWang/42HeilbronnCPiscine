/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:03:16 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 14:56:34 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_io.h"
#include <libc.h>
#include <stdlib.h>
#include "string_utils.h"

char	*read_from_stdin(void)
{
	const int	fd = 0;

	return (read_from_fd(fd));
}

char	*read_from_filepath(char *path)
{
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = read_from_fd(fd);
	fd = close(fd);
	return (str);
}

char	*read_from_fd(int fd)
{
	ssize_t		chunk_size;
	ssize_t		old_chunk_size;
	int			success;
	char		*str;

	old_chunk_size = 0;
	chunk_size = 1 << 12;
	str = realloc_str(NULL, old_chunk_size, chunk_size);
	if (!str)
		return (NULL);
	while (1)
	{
		success = read_next_chunk(fd, str, old_chunk_size, chunk_size);
		if (success == -1)
			return (NULL);
		else if (success)
			return (str);
		old_chunk_size = chunk_size;
		chunk_size *= 2;
		str = realloc_str(str, old_chunk_size, chunk_size);
		if (!str)
			return (NULL);
	}
	return (str);
}

int	read_next_chunk(int fd, char *str, int old_size, int new_size)
{
	ssize_t		bytes_read_total;
	ssize_t		bytes_read_new;
	ssize_t		max_new_bytes;

	bytes_read_total = old_size;
	bytes_read_new = 1;
	while (bytes_read_new && bytes_read_total < new_size)
	{
		max_new_bytes = new_size - bytes_read_total;
		bytes_read_new = read(fd, str + bytes_read_total, max_new_bytes);
		if (bytes_read_new == -1)
		{
			free(str);
			return (-1);
		}
		bytes_read_total += bytes_read_new;
	}
	if (bytes_read_total < new_size)
		str[bytes_read_total] = '\0';
	return (bytes_read_total < new_size);
}
