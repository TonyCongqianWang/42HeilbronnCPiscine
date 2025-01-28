/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/28 17:34:36 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle_init.h"

void	init_puzzle(t_puzzle *puzzle, int size)
{
	int		idx;

	puzzle->size = size;
	puzzle->nodes_visited = 0;
	puzzle->node_state.size = size;
	if (size == 0)
		puzzle->node_state.is_invalid = 0;
	r01_init_arrays(puzzle, size);
	idx = 0;
	while (idx < 2 * size)
	{
		init_constraints(puzzle, idx, size);
		idx++;
	}
}

void	init_grid_and_bmps(t_puzzle *puzzle, int size)
{
	int		idx;
	int		sub_idx;

	idx = 0;
	while (idx < size * size)
	{
		puzzle->grid_vals[idx] = 0;
		puzzle->node_state.valid_val_bmps[idx] = 0xffff;
		sub_idx = 0;
		idx++;
	}
}

void	init_constraints(t_puzzle *puzzle, int idx, int size)
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
			grid_index = (idx % size) * size + sub_index;
		puzzle->constraint_pairs[idx].size = size;
		puzzle->constraint_pairs[idx].grid_indeces[sub_index] = grid_index;
		puzzle->grid_constr_map[grid_index][idx / size] = idx;
		sub_index++;
	}
}

void    init_states(t_node_state *node_state, int size)
{
	node_state->size = size;
	node_state->is_complete = 0;
	node_state->is_invalid = 0;
	node_state->total_unset_count = size * size;
}
