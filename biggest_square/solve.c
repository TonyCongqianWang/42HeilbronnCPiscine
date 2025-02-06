/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:37:23 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/05 15:08:48 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "grid_coordinates.h"
#include "map_conversion.h"

void	solve(t_map map)
{
	t_solver_state	solver_state;

	if (!init_solver_state_from_map(&solver_state, map))
	{
		free_sol_state(&solver_state);
		return ;
	}
	dynamic_sq_expansion(&solver_state);
	write_sol_into_map(map, solver_state);
	free_sol_state(&solver_state);
}

void	dynamic_sq_expansion(t_solver_state *sol_state)
{
	t_map_dim	idx;
	t_map_dim	new_size;

	idx = sol_state->dims.width - 1;
	while (idx < sol_state->total - 1)
	{
		idx++;
		if (idx % sol_state->dims.width == 0
			|| sol_state->best_squares[idx] == 0)
			continue ;
		new_size = new_sq_size(sol_state, idx);
		sol_state->best_squares[idx] = new_size;
		if (new_size > sol_state->best_square)
		{
			sol_state->best_square = new_size;
			sol_state->best_idx = idx;
		}
	}
}

t_map_dim	new_sq_size(t_solver_state *sol_state, t_map_dim idx)
{
	t_idx_tripplet	neighbour_idxs;
	t_map_dim		new_size;
	t_map_dim		size_ub;
	int				rel_idx;

	neighbour_idxs = get_neighbour_idxs(sol_state->dims, idx);
	new_size = 1 + sol_state->best_squares[neighbour_idxs.idxs[0]];
	rel_idx = 1;
	while (rel_idx < 3)
	{
		size_ub = 1 + sol_state->best_squares[neighbour_idxs.idxs[rel_idx]];
		if (size_ub < new_size)
			new_size = size_ub;
		rel_idx++;
	}
	return (new_size);
}
