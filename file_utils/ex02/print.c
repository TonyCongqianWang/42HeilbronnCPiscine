/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:53:04 by towang            #+#    #+#             */
/*   Updated: 2025/02/06 21:41:09 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <unistd.h>
#include <libc.h>
#include <libgen.h>

void	write_file_error(char *progname, char *filename)
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

void	write_option_error(char *progname)
{
	progname = basename(progname);
	while (*progname)
		write(2, progname++, 1);
	write(2, ": illegal option. Only -c supported\n", 36);
}

void	write_offset_error(char *progname, char *arg)
{
	progname = basename(progname);
	while (*progname)
		write(2, progname++, 1);
	write(2, ": illegal offset -- ", 20);
	while (*arg)
		write(2, arg++, 1);
	write(2, "\n", 1);
}

void	write_file_name(char *str)
{
	write(1, "==> ", 4);
	while (*str)
		write(1, str++, 1);
	write(1, " <==\n", 5);
}
