/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:11:11 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 15:07:56 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_conversion.h"
#include "grid_coordinates.h"
#include <stdlib.h>

int	init_solver_state_from_map(t_solver_state *sol_state, t_map map)
{
	t_map_dim	buff_size;
	t_map_dim	idx;

	sol_state->dims = map.dims;
	sol_state->total = sol_state->dims.width * sol_state->dims.height;
	buff_size = sol_state->total * sizeof(t_map_dim);
	sol_state->best_square = 0;
	sol_state->best_idx = 0;
	sol_state->best_squares = (t_map_dim *)malloc(buff_size);
	if (!sol_state->best_squares)
		return (0);
	idx = 0;
	while (idx < sol_state->total)
	{
		sol_state->best_squares[idx] = (map.values[idx] == map.empty_ch);
		if (map.values[idx] == map.empty_ch && !sol_state->best_square)
		{
			sol_state->best_square = 1;
			sol_state->best_idx = idx;
		}
		idx++;
	}
	return (1);
}

void	write_sol_into_map(t_map map, t_solver_state sol_state)
{
	t_map_dim	map_best_y;
	t_map_dim	map_best_x;
	t_map_dim	x;
	t_map_dim	y;
	t_map_dim	idx;

	map_best_x = get_x_coord_from_idx(sol_state.dims, sol_state.best_idx);
	map_best_y = get_y_coord_from_idx(sol_state.dims, sol_state.best_idx);
	y = map_best_y + 1;
	while (y > map_best_y + 1 - sol_state.best_square)
	{
		x = map_best_x + 1;
		y--;
		while (x > map_best_x + 1 - sol_state.best_square)
		{
			x--;
			idx = convert_coord_to_idx(map.dims, y, x);
			map.values[idx] = map.full_ch;
		}
	}
}
