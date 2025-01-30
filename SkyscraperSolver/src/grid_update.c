/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/30 11:50:00 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid_update.h"
#include "cell_bitmaps.h"
#include "constraint_checking.h"
#include "constraint_selection.h"

int	try_grid_val(t_puzzle *grid, int cell_idx, int val)
{
	t_node_state	old_state;
	int				success;

	if (!is_valid_value(&grid->node_state, cell_idx, val))
	{
		return (0);
	}
	old_state = grid->node_state;
	set_grid_val(grid, cell_idx, val);
	success = check_constraints(grid, cell_idx);
	if (!success)
		set_value_invalid(&old_state, cell_idx, val);
	grid->node_state = old_state;
	unset_grid_val(grid, cell_idx);
	return (success);
}

void	set_grid_val(t_puzzle *grid, int cell_idx, int val)
{
	grid->grid_vals[cell_idx] = val;
	grid->node_state.total_unset_count--;
	update_bitmaps(&grid->node_state, cell_idx, val);
	if (grid->node_state.total_unset_count == 0)
		grid->node_state.is_complete = 1;
}

void	unset_grid_val(t_puzzle *grid, int cell_idx)
{
	grid->grid_vals[cell_idx] = 0;
}
#include <stdio.h>
int	check_constraints(t_puzzle *puzzle, int insert_idx)
{
	int					rel_idx;
	int					abs_idx;

	rel_idx = 0;
	while (rel_idx < 2)
	{
		abs_idx = puzzle->grid_constr_map[insert_idx][rel_idx];
		set_active_constraint(puzzle, abs_idx);
		if (insert_idx == 55 && puzzle->grid_vals[insert_idx] == 8)
			printf("GRID0 %d: %d %d %d %d\n", rel_idx, puzzle->constr_state.fwd_ub, 
			puzzle->constr_state.cur_c_pair.fwd_val, puzzle->constr_state.cur_c_pair.bwd_val, 
			puzzle->constr_state.max_height_lb);
		if (!check_active_constr(puzzle))
			return (0);
		if (insert_idx == 55 && puzzle->grid_vals[insert_idx] == 8)
			printf("GRID1 %d: %d %d %d %d\n", rel_idx, puzzle->constr_state.fwd_ub, 
			puzzle->constr_state.cur_c_pair.fwd_val, puzzle->constr_state.cur_c_pair.bwd_val, 
			puzzle->constr_state.max_height_lb);
		reverse_constr_direction(puzzle);
		if (insert_idx == 55 && puzzle->grid_vals[insert_idx] == 8)
			printf("GRID2 %d: %d %d %d %d\n", rel_idx, puzzle->constr_state.fwd_ub, 
			puzzle->constr_state.cur_c_pair.fwd_val, puzzle->constr_state.cur_c_pair.bwd_val, 
			puzzle->constr_state.max_height_lb);
			if (insert_idx == 55 && puzzle->grid_vals[insert_idx] == 8)
			printf("GRID2b %d\n", puzzle->constr_state.is_reverse);
		if (!check_active_constr(puzzle))
			return (0);
		if (insert_idx == 55 && puzzle->grid_vals[insert_idx] == 8)
			printf("GRID3 %d: %d %d %d %d\n", rel_idx, puzzle->constr_state.fwd_ub, 
			puzzle->constr_state.cur_c_pair.fwd_val, puzzle->constr_state.cur_c_pair.bwd_val, 
			puzzle->constr_state.max_height_lb);
		rel_idx++;
	}
	return (1);
}
