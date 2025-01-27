/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:25:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 18:10:43 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_io.h"
#include "r01_grid.h"
#include "r01_tree_search.h"

int	main(int argc, char **argv)
{
	t_r01_grid			puzzle_grid;
	t_r01_constraints	puzzle_constraints;

	if (argc != 2)
	{
		r01_print_error();
		return (0);
	}
	if(!r01_parse_input(&puzzle_constraints, argv[1]))
    {
        r01_print_error();
		return (0);
    }
    r01_init_grid(&puzzle_grid, puzzle_constraints.size);
    puzzle_grid = r01_tree_search(&puzzle_grid, &puzzle_constraints);
	if (!puzzle_grid.is_valid)
	{
		r01_print_error();
		return (0);
	}
	r01_print_grid(&puzzle_grid);
	return (0);
}
