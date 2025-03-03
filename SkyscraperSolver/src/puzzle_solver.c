/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:42 by towang            #+#    #+#             */
/*   Updated: 2025/01/31 00:29:27 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle_solver.h"
#include "grid_manipulation.h"
#include "node_pruning.h"
#include "node_selection.h"

int	solve_puzzle(t_puzzle *puzzle, int max_depth)
{
	t_node_state	input_state;
	int				idx;
	int				input_val;

	if (max_depth >= 0)
		puzzle->cur_node->max_depth = max_depth;
	input_state = *(puzzle->cur_node);
	idx = 0;
	while (idx < puzzle->size * puzzle->size)
		puzzle->cur_node->grid.vals[idx++] = 0;
	idx = 0;
	while (idx < puzzle->size * puzzle->size)
	{
		idx++;
		input_val = input_state.grid.vals[idx - 1];
		if (input_val == 0)
			continue ;
		if (puzzle->cur_node->grid.vals[idx - 1] == 0)
			set_grid_val(puzzle->cur_node, idx - 1, input_val, 1);
		else if (puzzle->cur_node->grid.vals[idx - 1] != input_val)
			return (0);
	}
	return (tree_search(puzzle));
}

static int	has_reached_terminal_state(t_node_state *cur_node)
{
	int	is_leaf_node;

	is_leaf_node = (cur_node->cur_depth >= cur_node->max_depth);
	is_leaf_node |= cur_node->is_complete;
	is_leaf_node |= cur_node->is_invalid;
	return (is_leaf_node);
}

static int	node_is_valid(t_node_state *cur_node)
{
	return (!cur_node->is_invalid);
}

int	tree_search(t_puzzle *puzzle)
{
	t_node_state		old_state;
	t_node_transition	next;

	puzzle->nodes_visited++;
	if (has_reached_terminal_state(puzzle->cur_node))
		return (node_is_valid(puzzle->cur_node));
	prune_node(puzzle);
	while (!has_reached_terminal_state(puzzle->cur_node)
		&& try_get_best_transition(puzzle, &next))
	{
		old_state = *(puzzle->cur_node);
		set_grid_val(puzzle->cur_node, next.cell_idx, next.cell_val, 0);
		puzzle->cur_node->cur_depth++;
		if (tree_search(puzzle))
			return (1);
		*(puzzle->cur_node) = old_state;
		set_value_invalid(puzzle->cur_node, next.cell_idx, next.cell_val);
	}
	return (node_is_valid(puzzle->cur_node));
}
