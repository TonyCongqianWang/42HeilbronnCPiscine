/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:51:38 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 12:57:41 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_io.h"
#include "r01_solver.h"
#include "r01_grid.h"

int	main(int argc, char **argv)
{
	t_r01_grid		grid;

	if (argc != 1)
	{
		print_error();
		return (0);
	}
	else if (is_input_str_format_valid(argv[1]))
	{
		print_error();
		return (0);
	}
	else
	{
		grid = parse_input_str(argv[1]);
		grid = solve_r01_grid(grid);
		print_grid_or_error(grid);
	}
}
