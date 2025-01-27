/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_tree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:28:12 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 18:18:48 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_tree_search.h"
#include "r01_grid.h"
#include "r01_validation.h"

t_r01_grid	r01_tree_search(t_r01_grid *grid, t_r01_constraints *constraints)
{
	int				next_x;
	int				next_y;
	int				next_val;
	t_r01_grid		next_grid;

	if (grid->unset_number == 0)
		return (*grid);
	if (!r01_get_min_available_coord(grid, &next_x, &next_y))
	{
		grid->is_valid = 0;
		return (*grid);
	}
	next_val = 1;
	while (next_val <= grid->size)
	{
		next_grid = *grid;
		if (r01_try_set_value(&next_grid, next_x, next_y, next_val))
		{
			if (r01_check_grid(&next_grid, constraints, next_x, next_y))
			{
				next_grid = r01_tree_search(&next_grid, constraints);
				if (next_grid.is_valid)
					return (next_grid);
			}
		}
		next_val++;
	}
	grid->is_valid = 0;
	return (*grid);
}

int	r01_get_min_available_coord(t_r01_grid *grid, int *x, int *y)
{
	int		best_x;
	int		best_y;
	int		min_availability;
	int		cur_availability;

	*x = 0;
	min_availability = grid->size + 1;
	while (*x < grid->size)
	{
		*y = 0;
		while (*y < grid->size)
		{
			cur_availability = r01_get_num_valid_values(grid, *x, *y);
			if (cur_availability < 0)
				return (0);
			if (cur_availability < min_availability)
			{
				min_availability = cur_availability;
				best_x = *x;
				best_y = *y;
			}
			(*y)++;
		}
		(*x)++;
	}
	if (min_availability >= grid->size + 1)
		return (0);
	*x = best_x;
	*y = best_y;
	return (1);
}
