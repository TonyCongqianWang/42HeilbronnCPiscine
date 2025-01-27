/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:27:09 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 18:07:20 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_validation.h"
#include "r01_io.h"
#include "stdio.h"
int	r01_check_grid(t_r01_grid *grid, t_r01_constraints *constr, int x, int y)
{
	if (!r01_check_grid_col(grid, x, 0, constr->vals[x][0]))
	{
		return (0);
	}
	if (!r01_check_grid_col(grid, x, 1, constr->vals[x][1]))
	{
		return (0);
	}	
	if (!r01_check_grid_row(grid, y, 0, constr->vals[y][2]))
	{
		return (0);
	}
	if (!r01_check_grid_row(grid, y, 1, constr->vals[y][3]))
	{
		return (0);
	}
	return (1);
}

int	r01_check_grid_row(t_r01_grid *grid, int y, int reverse, int c_val)
{
	int		loop_idx;
	int		x;
	int		max_val;
	int		vis_count;
	
	loop_idx = 0;
	max_val = 0;
	vis_count = 0;
	while (loop_idx < grid->size)
	{
		if(!reverse)
			x = loop_idx;
		else
			x = grid->size - loop_idx - 1;
		if (grid->grid_vals[x][y] == 0)
			return (1);
		if (grid->grid_vals[x][y] > max_val)
		{
			max_val = grid->grid_vals[x][y];
			vis_count++;
		}
		loop_idx++;
	}
	if (vis_count != c_val)
		return (0);
	return (1);
}


int	r01_check_grid_col(t_r01_grid *grid, int x, int reverse, int c_val)
{
	int		loop_idx;
	int		y;
	int		max_val;
	int		vis_count;
	
	loop_idx = 0;
	max_val = 0;
	vis_count = 0;
	while (loop_idx < grid->size)
	{
		if(!reverse)
			y = loop_idx;
		else
			y = grid->size - loop_idx - 1;
		if (grid->grid_vals[x][y] == 0)
			return (1);
		if (grid->grid_vals[x][y] > max_val)
		{
			max_val = grid->grid_vals[x][y];
			vis_count++;
		}
		loop_idx++;
	}
	if (vis_count != c_val)
		return (0);
	return (1);
}


