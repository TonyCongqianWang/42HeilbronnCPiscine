/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:58:04 by towang            #+#    #+#             */
/*   Updated: 2025/02/06 22:04:51 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libc.h>
#include <sys/errno.h>
#include <libgen.h>

void	display_file_content(int fd)
{
	char		buff[16];
	ssize_t		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buff, 16);
		if (bytes_read < 0)
			break ;
		write(1, buff, bytes_read);
	}
}

void	write_error(char *progname, char *filename)
{
	char	*err_msg;

	progname = basename(progname);
	while (*progname)
		write(2, progname++, 1);
	write(2, ": ", 2);
	while (*filename)
		write(2, filename++, 1);
	write(2, ": ", 2);
	err_msg = strerror(errno);
	while (*err_msg)
		write(2, err_msg++, 1);
	write(2, "\n", 1);
}

int	open_if_file(char *name)
{
	int		fd;

	fd = open(name, O_RDONLY + O_DIRECTORY);
	if (fd == -1)
	{
		fd = open(name, O_RDONLY);
		return (fd);
	}
	close(fd);
	fd = open(name, O_RDWR);
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		arg_idx;

	if (argc <= 1)
	{
		display_file_content(0);
		return (0);
	}
	arg_idx = 1;
	while (arg_idx < argc)
	{
		fd = open_if_file(argv[arg_idx]);
		if (fd != -1)
		{
			display_file_content(fd);
			close(fd);
		}
		else
			write_error(argv[0], argv[arg_idx]);
		arg_idx++;
	}
	return (0);
}
