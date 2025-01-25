/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:42 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 19:13:05 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_solver.h"
#include "r01_io.h"

t_r01_puzzle	r01_solve_puzzle(t_r01_puzzle *puzzle)
{
	t_r01_puzzle	res;
	int				grid_idx;
	int				grid_val;

	print_puzzle_grid(puzzle); //TODO take this out
	res = *puzzle;
	if (res.is_invalid || res.is_complete)
		return (res);
	grid_idx = r01_get_next_grid_idx(&res);
	if (grid_idx < 0)
	{
		return (res);
	}
	grid_val = 1;
	while (grid_val <= puzzle->size)
	{
		r01_set_grid_val(&res, grid_idx, grid_val);
		res = r01_solve_puzzle(&res);
		if (!res.is_invalid && res.is_complete)
			return (res);
		res = *puzzle;
		grid_val++;
	}
	return (res);
}

int	r01_get_next_grid_idx(t_r01_puzzle *puzzle)
{
	int		idx;
	idx = 0;
	while (idx < puzzle->size * puzzle->size)
	{
		if (puzzle->grid_vals[idx] == 0)
			return (idx);
		idx++;
	}
	return (-1);
}
