/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:18:17 by towang            #+#    #+#             */
/*   Updated: 2025/02/06 21:40:49 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libc.h>

ssize_t	read_into_buff(int fd, char *buff, int size, int *wraparound)
{
	ssize_t		bytes_read;
	ssize_t		write_position;

	write_position = 0;
	bytes_read = 1;
	*wraparound = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff + write_position, size - write_position);
		write_position += bytes_read;
		if (write_position >= size)
			*wraparound = 1;
		write_position %= size;
	}
	if (bytes_read == -1)
		return (-1);
	return (write_position);
}

void	display_file_content(int fd, int num_bytes)
{
	char		*buff;
	ssize_t		write_pos;
	int			wraparound;

	buff = (char *)malloc(num_bytes * sizeof(char));
	if (!buff)
		return ;
	write_pos = read_into_buff(fd, buff, num_bytes, &wraparound);
	if (write_pos >= 0)
	{
		if (wraparound)
			write(1, buff + write_pos, num_bytes - write_pos);
		write(1, buff, write_pos);
	}
	free(buff);
}
