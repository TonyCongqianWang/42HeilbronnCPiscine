/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 12:27:42 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stdlib for malloc if we want to modify for bonus tasks
// #include <stdlib.h>
#include "r01_puzzle.h"
#include "r01_constraint.h"

void	r01_initialize_puzzle(t_r01_grid *puzzle, int size)
{
	int		idx;

	idx = 0;
	puzzle->size = size;
	puzzle->is_complete = 0;
	puzzle->is_invalid = 0;
	puzzle->min_unset_count = size;
	if (size == 0)
		puzzle->is_invalid = 0;
	while (idx < size * size)
	{
		puzzle->grid_vals[idx] = 0;
		puzzle->valid_values[idx] = 0xffff;
		idx++;
	}
	idx = 0;
	while (idx < 4 * size)
	{
		init_constr_indeces(puzzle->constraints, idx, size);
		idx++;
	}
}

void	init_constr_indeces(t_r01_constraints *constraints, int idx, int size)
{
	int		sub_index;
	int		grid_index;

	sub_index = 0;
	grid_index = 0;
	while (sub_index < size)
	{
		if (idx < size)
			grid_index = idx + sub_index * size;
		else if (idx < 2 * size)
			grid_index = (idx % size) + (size - sub_index - 1) * size;
		else if (idx < 3 * size)
			grid_index = (idx % size) * size + sub_index;
		else if (idx < size * size)
			grid_index = ((idx % size) + 1) * size - 1 - sub_index;
		constraints->constr_grid_map[idx][sub_index] = grid_index;
		constraints->grid_constr_map[grid_index][sub_index] = idx;
		sub_index++;
	}
}

void	r01_update_min_unset(t_r01_grid *puzzle, int unset_count)
{
	if (puzzle->min_unset_count > unset_count)
	{
		puzzle->min_unset_count = unset_count;
	}
}

int	r01_try_update_valid_values(t_r01_grid *puzzle, int idx, int val)
{
	int		counter;
	int		update_idx;

	if (!((puzzle->valid_values[idx]) & (1 << val)))
		return (0);
	counter = 0;
	while (counter < puzzle->size)
	{
		update_idx = (idx + counter * puzzle->size);
		update_idx %= puzzle->size * puzzle->size;
		puzzle->valid_values[update_idx] &= ~(1 << val);
		counter++;
	}
	counter = 0;
	while (counter < puzzle->size)
	{
		update_idx = (idx / puzzle->size) * puzzle->size;
		update_idx += ((idx + counter) % puzzle->size);
		puzzle->valid_values[update_idx] &= ~(1 << val);
		counter++;
	}
	return (1);
}

void	r01_set_grid_val(t_r01_grid *puzzle, int idx, int val)
{
	puzzle->grid_vals[idx] = val;
	if (!r01_try_update_valid_values(puzzle, idx, val))
	{
		puzzle->is_invalid = 1;
		return ;
	}
	r01_check_constraints(puzzle);
	idx = 0;
	puzzle->is_complete = 1;
	while (idx < puzzle->size * puzzle->size)
	{
		if (puzzle->grid_vals[idx] == 0)
		{
			puzzle->is_complete = 0;
			return ;
		}
		idx++;
	}
}
