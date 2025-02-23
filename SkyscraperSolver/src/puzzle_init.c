/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/30 21:21:54 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle_init.h"
#include "cell_bounds.h"

void	init_puzzle(t_puzzle *puzzle, int size)
{
	int		idx;

	init_state_fields(puzzle, size);
	init_grid_and_bmps(puzzle, size);
	idx = 0;
	while (idx < 2 * size)
	{
		init_constraint(puzzle, idx, size);
		idx++;
	}
}

void	init_grid_and_bmps(t_puzzle *puzzle, int size)
{
	int		idx;

	idx = 0;
	while (idx < size * size)
	{
		puzzle->cur_node->grid.vals[idx] = 0;
		puzzle->cur_node->grid.valid_val_bmps[idx] = 0xffff;
		update_cell_bounds(puzzle->cur_node, idx);
		puzzle->cur_node->grid.num_cell_vals[idx] = size;
		idx++;
	}
}

void	init_constraint(t_puzzle *puzzle, int idx, int size)
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
		puzzle->cur_node->constrs.num_val_positions[idx][sub_index] = size;
		puzzle->constraint_pairs[idx].grid_indeces[sub_index] = grid_index;
		puzzle->grid_constr_map[grid_index][idx / size] = idx;
		sub_index++;
	}
}

void	init_state_fields(t_puzzle *puzzle, int size)
{
	puzzle->size = size;
	puzzle->nodes_visited = 0;
	puzzle->constr_bounds.size = size;
	puzzle->cur_node = &puzzle->stored_node;
	puzzle->cur_node->puzzle = puzzle;
	puzzle->cur_node->size = size;
	puzzle->cur_node->is_complete = 0;
	puzzle->cur_node->is_invalid = 0;
	puzzle->cur_node->is_sub_state = 0;
	puzzle->cur_node->last_set_idx = -1;
	puzzle->cur_node->num_unset = size * size;
}
