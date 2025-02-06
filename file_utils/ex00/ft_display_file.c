/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:58:04 by towang            #+#    #+#             */
/*   Updated: 2025/02/06 13:11:12 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display_file_content(int fd)
{
	char		buff[256];
	ssize_t		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buff, 256);
		if (bytes_read < 0)
			break ;
		write(1, buff, bytes_read);
	}
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc <= 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc >= 3)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	display_file_content(fd);
	close(fd);
	return (0);
}
