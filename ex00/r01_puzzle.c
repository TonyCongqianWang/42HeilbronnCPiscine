/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 13:05:56 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_puzzle.h"
#include "r01_constraint.h"

void	r01_init_puzzle(t_r01_grid *grid, t_r01_constraints *constrs, int size)
{
	int		idx;

	grid->size = size;
	grid->is_complete = 0;
	grid->is_invalid = 0;
	grid->min_unset_count = size;
	grid->constraints = constrs;
	grid->total_unset_count = size * size;
	constrs->size = size;
	if (size == 0)
		grid->is_invalid = 0;
	r01_init_arrays(grid, size);
	idx = 0;
	while (idx < 4 * size)
	{
		r01_init_maps(grid->constraints, idx, size);
		idx++;
	}
}

void	r01_init_arrays(t_r01_grid *grid, int size)
{
	int		idx;
	int		sub_idx;

	idx = 0;
	while (idx < size * size)
	{
		sub_idx = 0;
		grid->grid_vals[idx] = 0;
		grid->valid_values[idx] = 0xffff;
		while (sub_idx < 4)
		{
			grid->constraints->grid_constr_map[idx][sub_idx] = -1;
			sub_idx++;
		}
		idx++;
	}
}

void	r01_init_maps(t_r01_constraints *constrs, int idx, int size)
{
	int		sub_index;
	int		grid_index;
	int		g_to_cons_idx;

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
		constrs->constr_grid_map[idx][sub_index] = grid_index;
		g_to_cons_idx = 0;
		while (constrs->grid_constr_map[grid_index][g_to_cons_idx] >= 0)
			g_to_cons_idx++;
		constrs->grid_constr_map[grid_index][g_to_cons_idx] = idx;
		sub_index++;
	}
}

int	r01_try_update_valid_values(t_r01_grid *grid, int idx, int val)
{
	int		counter;
	int		update_idx;

	if (!((grid->valid_values[idx]) & (1 << val)))
		return (0);
	counter = 0;
	while (counter < grid->size)
	{
		update_idx = (idx + counter * grid->size);
		update_idx %= grid->size * grid->size;
		grid->valid_values[update_idx] &= ~(1 << val);
		counter++;
	}
	counter = 0;
	while (counter < grid->size)
	{
		update_idx = (idx / grid->size) * grid->size;
		update_idx += ((idx + counter) % grid->size);
		grid->valid_values[update_idx] &= ~(1 << val);
		counter++;
	}
	return (1);
}

void	r01_set_grid_val(t_r01_grid *grid, int idx, int val)
{
	grid->grid_vals[idx] = val;
	if (!r01_try_update_valid_values(grid, idx, val))
	{
		grid->is_invalid = 1;
		return ;
	}
	r01_check_constraints(grid, idx);
	grid->total_unset_count--;
	if (grid->total_unset_count == 0)
		grid->is_complete = 1;
}
