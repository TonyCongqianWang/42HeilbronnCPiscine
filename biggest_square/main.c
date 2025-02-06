/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:02:02 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/05 15:28:27 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "map_creation.h"
#include "read_io.h"
#include "print_utils.h"
#include "solve.h"

int	parse_and_solve_map(char *map_str)
{
	t_map	map;
	int		load_success;

	if (!map_str)
	{
		print_map_error();
		return (-1);
	}
	load_success = try_read_map_from_str(&map, map_str);
	free(map_str);
	if (!load_success)
	{
		print_map_error();
		return (-2);
	}
	solve(map);
	print_map(map);
	free_map(&map);
	return (0);
}

int	solve_map_from_filepath(char *filepath)
{
	return (parse_and_solve_map(read_from_filepath(filepath)));
}

int	solve_map_from_stdins(void)
{
	return (parse_and_solve_map(read_from_stdin()));
}

int	main(int argc, char *argv[])
{
	int		arg_idx;

	if (argc == 1)
		solve_map_from_stdins();
	arg_idx = 1;
	while (arg_idx < argc)
	{
		solve_map_from_filepath(argv[arg_idx]);
		if (arg_idx != argc - 1)
			ft_putstr("\n");
		arg_idx++;
	}
	return (0);
}
