/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 21:43:27 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_puzzle_init.h"
#include "r01_constraints.h"

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
		else if (idx < 4 * size)
			grid_index = ((idx % size) + 1) * size - 1 - sub_index;
		constrs->constr_grid_map[idx][sub_index] = grid_index;
		g_to_cons_idx = 0;
		while (constrs->grid_constr_map[grid_index][g_to_cons_idx] >= 0)
			g_to_cons_idx++;
		constrs->grid_constr_map[grid_index][g_to_cons_idx] = idx;
		sub_index++;
	}
}
