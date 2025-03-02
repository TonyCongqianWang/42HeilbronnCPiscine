/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_pruning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/30 23:02:06 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_pruning.h"
#include "grid_manipulation.h"
#include "cell_bounds.h"
#include "puzzle_solver.h"
#include "node_selection.h"

static int	init_pruning_state(t_puzzle *puzzle);
static int	keep_pruning(t_node_pruning_state *state);
static int	check_validity(t_puzzle *puzzle, t_node_transition next);

void	prune_node(t_puzzle *puzzle)
{
	t_node_transition	tr;

	if (!init_pruning_state(puzzle))
		return ;
	while (keep_pruning(&puzzle->pruning))
	{
		tr.cell_idx = 0;
		tr.cell_val = 1;
		while (try_get_next_transition(puzzle, &tr))
		{
			if (!check_validity(puzzle, tr))
			{
				set_value_invalid(puzzle->cur_node, tr.cell_idx, tr.cell_val);
				puzzle->pruning.last_iteration_succeeded = 1;
			}
			tr.cell_val++;
		}
	}
}

static int	init_pruning_state(t_puzzle *puzzle)
{
	const double	min_unset_quotient = 0.67;
	double			unset_quotient;
	t_node_state	*state;

	state = puzzle->cur_node;
	unset_quotient = state->num_unset;
	unset_quotient /= puzzle->size * puzzle->size;
	if (state->sub_node_depth > 0)
		puzzle->pruning.max_pruning_depth = 1;
	else if (state->cur_depth == 0)
		puzzle->pruning.max_pruning_depth = 4 * unset_quotient;
	else if (state->cur_depth < puzzle->size / 4)
		puzzle->pruning.max_pruning_depth = 3 * unset_quotient;
	else
		puzzle->pruning.max_pruning_depth = 1;
	if (puzzle->pruning.max_pruning_depth < 1)
		puzzle->pruning.max_pruning_depth = 1;
	puzzle->pruning.can_reiterate = unset_quotient > min_unset_quotient;
	puzzle->pruning.cur_pruning_depth = 0;
	puzzle->pruning.last_iteration_succeeded = 0;
	return (1);
}

static int	keep_pruning(t_node_pruning_state *state)
{
	if (state->last_iteration_succeeded
		&& state->can_reiterate
		&& state->cur_pruning_depth < 2)
	{
		state->last_iteration_succeeded = 0;
		return (1);
	}
	else if (state->cur_pruning_depth < state->max_pruning_depth)
	{
		state->last_iteration_succeeded = 0;
		state->cur_pruning_depth++;
		return (1);
	}
	return (0);
}

static int	check_validity(t_puzzle *puzzle, t_node_transition next)
{
	t_node_state	old_state;
	int				is_valid;

	old_state = *(puzzle->cur_node);
	puzzle->cur_node->max_depth = puzzle->pruning.cur_pruning_depth;
	puzzle->cur_node->cur_depth++;
	puzzle->cur_node->sub_node_depth++;
	set_grid_val(puzzle->cur_node, next.cell_idx, next.cell_val, 1);
	is_valid = tree_search(puzzle);
	if (!is_valid || !puzzle->cur_node->is_complete)
		*(puzzle->cur_node) = old_state;
	return (is_valid);
}
