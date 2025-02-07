/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:58:04 by towang            #+#    #+#             */
/*   Updated: 2025/02/07 01:33:42 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <libgen.h>

void	display_file_content(int fd, int num_bytes);
void	write_file_error(char *progname, char *filename);
void	write_option_error(char *progname);
void	write_offset_error(char *progname, char *arg);
void	write_file_name(char *str);

int	try_parse_offset(char *arg, unsigned long long *res)
{
	*res = 0;
	while (*arg <= '9' && *arg >= '0')
	{
		*res = (10 * *res) + (*arg - '0');
		arg++;
	}
	return (!*arg);
}

int	get_offset_from_argv(int argc, char **argv, unsigned long long *res)
{
	const char		ref_option[3] = "-c";
	const char		*option;
	const char		*cmp;

	if (argc < 3)
	{
		write_option_error(argv[0]);
		return (0);
	}
	option = argv[1];
	cmp = ref_option;
	while (*cmp || *option)
	{
		if (*cmp++ != *option++)
		{
			write_option_error(argv[0]);
			return (0);
		}
	}
	if (!try_parse_offset(argv[2], res))
	{
		write_offset_error(argv[0], argv[2]);
		return (0);
	}
	return (1);
}

void	handle_single_file(char **argv, int arg_idx, int offset, int *flags)
{
	int		fd;

	fd = open(argv[arg_idx], O_RDONLY);
	if (fd != -1)
	{
		if (*flags & 2)
			write(1, "\n", 1);
		if (*flags & 1)
			write_file_name(argv[arg_idx]);
		display_file_content(fd, offset);
		close(fd);
		*flags |= 2;
	}
	else
	{
		write_file_error(argv[0], argv[arg_idx]);
	}
}

int	main(int argc, char **argv)
{
	int					arg_idx;
	int					need_nl_or_fn;
	unsigned long long	offset;

	if (!get_offset_from_argv(argc, argv, &offset))
		return (0);
	if (argc <= 3)
		display_file_content(0, offset);
	need_nl_or_fn = argc > 4;
	arg_idx = 3;
	while (arg_idx < argc)
	{
		handle_single_file(argv, arg_idx, offset, &need_nl_or_fn);
		arg_idx++;
	}
	return (0);
}
