/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:51:38 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 15:23:13 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_io.h"
#include "r01_solver.h"
#include "r01_puzzle.h"

int	main(int argc, char **argv)
{
	t_r01_puzzle		puzzle;

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
	puzzle = parse_input_str(argv[1]);
	puzzle = solve_r01_puzzle(puzzle);
	if (puzzle.is_invalid || !puzzle.is_complete)
	{
		print_error();
		return (0);
	}
	print_puzzle_grid(puzzle);
	return (0);
}
