/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_bounds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:48:43 by towang            #+#    #+#             */
/*   Updated: 2025/01/31 00:17:45 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell_bounds.h"
#include "cell_bitmaps.h"
#include "grid_update.h"
#include "constraint_checking.h"

int	tighten_single_cell_bounds(t_puzzle *puzzle, int idx)
{
	short			cell_val;
	short			cell_ub;
	int				success;
	t_node_state	*node_state;

	node_state = &puzzle->node_state;
	get_cell_bounds(node_state, idx, &cell_val, &cell_ub);
	success = 0;
	while (cell_val <= cell_ub)
	{
		if (is_valid_value(node_state, idx, cell_val))
		{
			if (check_grid_val_violations(puzzle, idx, cell_val))
			{
				set_value_invalid(node_state, idx, cell_val);
				success = 1;
			}
		}
		cell_val++;
	}
	return (success);
}

void	update_cell_bounds(t_node_state *state, int idx)
{
	char	lb;
	char	ub;

	lb = 1;
	while (lb < state->size
		&& !is_valid_value(state, idx, lb))
	{
		lb++;
	}
	ub = state->size;
	while (ub > 1
		&& !is_valid_value(state, idx, ub))
	{
		ub--;
	}
	lb &= 0x0F;
	ub = (ub & 0x0F) << 4;
	state->grid.cell_bounds[idx] = lb;
	state->grid.cell_bounds[idx] |= ub;
}

void	get_cell_bounds(t_node_state *state, int idx, short *lb, short *ub)
{
	*lb = state->grid.cell_bounds[idx] & 0x0F;
	*ub = state->grid.cell_bounds[idx] & 0xF0;
	*ub >>= 4;
}
