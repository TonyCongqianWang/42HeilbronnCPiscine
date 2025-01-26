/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:42 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 15:30:38 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_solver.h"

t_r01_grid	r01_solve_puzzle(t_r01_grid *puzzle)
{
	return (r01_tree_search(puzzle, -1, 0));
}

t_r01_grid	r01_tree_search(t_r01_grid *puzzle, int depths, int score_depths)
{
	t_r01_grid		res;
	int				grid_idx;
	int				grid_val;

	if (puzzle->is_invalid || puzzle->is_complete || depths == 0)
		return (*puzzle);
	res = *puzzle;
	grid_idx = r01_get_next_grid_idx(&res, score_depths);
	grid_val = 1;
	while (grid_val <= puzzle->size)
	{
		r01_set_grid_val(&res, grid_idx, grid_val);
		res = r01_tree_search(&res, depths - 1, score_depths);
		if (!res.is_invalid)
			return (res);
		res = *puzzle;
		grid_val++;
	}
	res.is_invalid = 1;
	return (res);
}

int	r01_score_grid_idx(t_r01_grid *puzzle, int idx, int score_depths)
{
	t_r01_grid		res;
	int				grid_val;
	int				num_valid;

	res = *puzzle;
	grid_val = 1;
	num_valid = 0;
	while (grid_val <= puzzle->size)
	{
		if (puzzle->valid_values[idx] & (1 << grid_val))
		{
			r01_set_grid_val(&res, idx, grid_val);
			if (score_depths != 0)
				r01_tree_search(&res, score_depths, 0);
			if (res.is_invalid)
				puzzle->valid_values[idx] &= ~(1 << grid_val);
			else
				num_valid++;
			res = *puzzle;
		}
		grid_val++;
	}
	return (10 * puzzle->size - 3 * num_valid - puzzle->min_unset_count);
}

int	r01_get_next_grid_idx(t_r01_grid *puzzle, int score_depths)
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
			score = r01_score_grid_idx(puzzle, idx, score_depths);
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
