/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:51:38 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 12:18:25 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_io.h"
#include "r01_solver.h"
#include "r01_puzzle.h"

int	main(int argc, char **argv)
{
	t_r01_grid			puzzle_grid;
	t_r01_constraints	puzzle_constraints;

	if (argc != 2)
	{
		r01_print_error();
		return (0);
	}
	r01_parse_input(&puzzle_grid, &puzzle_constraints, argv[1]);
	puzzle_grid = r01_solve_puzzle(&puzzle_grid);
	if (puzzle_grid.is_invalid || !puzzle_grid.is_complete)
	{
		r01_print_error();
		return (0);
	}
	r01_print_grid(&puzzle_grid);
	return (0);
}
