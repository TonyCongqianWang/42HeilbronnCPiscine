/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:58:04 by towang            #+#    #+#             */
/*   Updated: 2025/02/06 23:05:28 by towang           ###   ########.fr       */
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

int	handle_single_file(int argc, char **argv, int arg_idx, int offset)
{
	int		fd;

	fd = open(argv[arg_idx], O_RDONLY);
	if (fd != -1)
	{
		if (argc > 4)
			write_file_name(argv[arg_idx]);
		display_file_content(fd, offset);
		close(fd);
		return (1);
	}
	write_file_error(argv[0], argv[arg_idx]);
	return (0);
}

int	main(int argc, char **argv)
{
	int					arg_idx;
	unsigned long long	offset;
	int					need_nl;

	need_nl = 0;
	if (!get_offset_from_argv(argc, argv, &offset))
		return (0);
	if (argc <= 3)
		display_file_content(0, offset);
	arg_idx = 3;
	while (arg_idx < argc)
	{
		if(need_nl)
			write(1, "\n", 1);
		need_nl = handle_single_file(argc, argv, arg_idx, offset);
		arg_idx++;
	}
	return (0);
}
