/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 18:20:03 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stdlib for malloc if we want to modify for bonus tasks
// #include <stdlib.h>
#include "r01_puzzle.h"

void	r01_initialize_puzzle(t_r01_puzzle *puzzle, int size)
{
	int		idx;

	idx = 0;
	puzzle->size = size;
	puzzle->is_complete = 0;
	puzzle->is_invalid = 0;
	if (size == 0)
		puzzle->is_invalid = 0;
	while (idx < size * size)
	{
		puzzle->grid_vals[idx] = 0;
	}
	idx = 0;
	while (idx < 4 * size)
	{
		puzzle->constr_vals[idx] = 0;
	}
}

int	r01_get_grid_idx_for_constr(int size, int constr_idx, int sub_idx)
{
	int		idx;

	if (constr_idx < size)
		idx = constr_idx + sub_idx * size;
	else if (constr_idx < 2 * size)
		idx = constr_idx + (size - sub_idx - 1) * size;
	else if (constr_idx < 2 * size)
		idx = constr_idx * size + sub_idx;
	else if (constr_idx < 2 * size)
		idx = (constr_idx + 1) * size - 1 - sub_idx;
	return (idx);
}

void	r01_check_constr(t_r01_puzzle *puzzle, int constr_idx, int size)
{
	int		grid_idx;
	int		counter;
	int		constr_val;
	int		actual_val;
	int		max_val;

	counter = 0;
	max_val = 0;
	constr_val = puzzle->constr_vals[constr_idx];
	actual_val = 0;
	while (counter < size)
	{
		grid_idx = r01_get_grid_idx_for_constr(size, constr_idx, counter);
		if (puzzle->grid_vals[grid_idx] == 0)
		{
			return ;
		}
		if (puzzle->grid_vals[grid_idx] > 0)
		{
			max_val = puzzle->grid_vals[grid_idx];
			actual_val++;
		}
	}
	puzzle->is_invalid = actual_val != constr_val;
}

void	r01_set_grid_val(t_r01_puzzle *puzzle, int idx, int val)
{
	puzzle->grid_vals[idx] = val;
	idx = 0;
	while (idx < 4 * puzzle->size)
	{
		r01_check_constr(puzzle, idx, puzzle->size);
	}
	idx = 0;
	puzzle->is_complete = 1;
	while (idx < 4 * puzzle->size)
	{
		if (puzzle->grid_vals[idx] == 0)
		{
			puzzle->is_complete = 0;
			return ;
		}
	}
}

int	r01_get_grid_val(t_r01_puzzle *puzzle, int x, int y)
{
	int		idx;

	idx = x + puzzle->size * y;
	return (puzzle->grid_vals[idx]);
}
