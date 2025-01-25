/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:42 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 00:13:54 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_solver.h"

t_r01_puzzle	r01_solve_puzzle(t_r01_puzzle *puzzle)
{
	t_r01_puzzle	res;
	int				grid_idx;
	int				grid_val;

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

int	r01_score_grid_idx(t_r01_puzzle *puzzle, int idx)
{
	t_r01_puzzle	res;
	int				grid_val;
	int				num_valid;

	res = *puzzle;
	grid_val = 1;
	num_valid = 1;
	while (grid_val <= puzzle->size)
	{
		r01_set_grid_val(&res, idx, grid_val);
		if (!res.is_invalid)
			num_valid++;
		res = *puzzle;
		grid_val++;
	}
	return (10 * puzzle->size - 3 * num_valid - puzzle->min_unset_count);
}

int	r01_get_next_grid_idx(t_r01_puzzle *puzzle)
{
	int		idx;
	int		score;
	int		best_idx;
	int		best_score;

	idx = 0;
	best_idx = -1;
	best_score = -2 * R01_MAX_GRID_SIZE;
	while (idx < puzzle->size * puzzle->size)
	{
		if (puzzle->grid_vals[idx] == 0)
		{
			score = r01_score_grid_idx(puzzle, idx);
			if (score > best_score)
			{
				best_idx = idx;
				best_score = score;
			}
		}
		idx++;
	}
	return (best_idx);
}
