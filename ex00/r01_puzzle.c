/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 22:32:16 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stdlib for malloc if we want to modify for bonus tasks
// #include <stdlib.h>
#include "r01_puzzle.h"
#include "r01_constraint.h"

void	r01_initialize_puzzle(t_r01_puzzle *puzzle, int size)
{
	int		idx;

	idx = 0;
	puzzle->size = size;
	puzzle->is_complete = 0;
	puzzle->is_invalid = 0;
	puzzle->min_unset_count = size;
	if (size == 0)
		puzzle->is_invalid = 0;
	while (idx < size * size)
	{
		puzzle->grid_vals[idx] = 0;
		idx++;
	}
	idx = 0;
	while (idx < 4 * size)
	{
		puzzle->constr_vals[idx] = 0;
		idx++;
	}
}

void	r01_update_min_unset(t_r01_puzzle *puzzle, int unset_count)
{
	if (puzzle->min_unset_count > unset_count)
	{
		puzzle->min_unset_count = unset_count;
	}
}

void	r01_set_grid_val(t_r01_puzzle *puzzle, int idx, int val)
{
	puzzle->grid_vals[idx] = val;
	r01_check_constraints(puzzle);
	idx = 0;
	puzzle->is_complete = 1;
	while (idx < puzzle->size * puzzle->size)
	{
		if (puzzle->grid_vals[idx] == 0)
		{
			puzzle->is_complete = 0;
			return ;
		}
		idx++;
	}
}
