/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 21:46:24 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_grid.h"
#include "r01_constraints.h"

int	r01_try_update_valid_values(t_r01_grid *grid, int idx, int val)
{
	int		counter;
	int		update_idx;

	if (!((grid->valid_values[idx]) & (1 << val)))
		return (0);
	counter = 0;
	while (counter < grid->size)
	{
		update_idx = (idx + counter * grid->size);
		update_idx %= grid->size * grid->size;
		grid->valid_values[update_idx] &= ~(1 << val);
		counter++;
	}
	counter = 0;
	while (counter < grid->size)
	{
		update_idx = (idx / grid->size) * grid->size;
		update_idx += ((idx + counter) % grid->size);
		grid->valid_values[update_idx] &= ~(1 << val);
		counter++;
	}
	return (1);
}

void	r01_set_grid_val(t_r01_grid *grid, int idx, int val)
{
	grid->grid_vals[idx] = val;
	if (!r01_try_update_valid_values(grid, idx, val))
	{
		grid->is_invalid = 1;
		return ;
	}
	r01_check_constraints(grid, idx);
	grid->total_unset_count--;
	if (grid->total_unset_count == 0)
		grid->is_complete = 1;
}
