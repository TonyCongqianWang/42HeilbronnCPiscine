/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:06 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 18:18:24 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_grid.h"

void	r01_init_grid(t_r01_grid *grid, int size)
{
	int		x;
	int		y;

	grid->size = size;
	grid->unset_number = size * size;
	grid->is_valid = 1;
	x = 0;
	y = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			grid->grid_vals[x][y] = 0;
			grid->valid_values[x][y] = 0xffff;
			y++;
		}
		x++;
	}
}

int	r01_try_set_value(t_r01_grid *grid, int x, int y, int val)
{
	int		swap;

	if (!r01_is_valid_value(grid, x, y, val))
		return (0);
	if (grid->grid_vals[x][y] != 0)
		return (0);
	grid->grid_vals[x][y] = val;
	grid->unset_number--;
	swap = x;
	x = 0;
	while (x < grid->size)
	{
		r01_set_value_invalid(grid, x, y, val);
		x++;
	}
	x = swap;
	y = 0;
	while (y < grid->size)
	{
		r01_set_value_invalid(grid, x, y, val);
		y++;
	}
	return (1);
}

int	r01_get_num_valid_values(t_r01_grid *grid, int x, int y)
{
	int		res;
	int		counter;
	int		bitmap;

	if (grid->grid_vals[x][y] != 0)
		return (grid->size + 1);
	res = 0;
	counter = 0;
	bitmap = grid->valid_values[x][y];
	while (counter < grid->size)
	{
		res += bitmap & 1;
		bitmap >>= 1;
		counter++;
	}
	return (res);
}

int	r01_is_valid_value(t_r01_grid *grid, int x, int y, int val)
{
	int		bitmask;
	short	bitmap;

	bitmask = 1 << (val - 1);
	bitmap = grid->valid_values[x][y];
	return (bitmask & bitmap);
}

void	r01_set_value_invalid(t_r01_grid *grid, int x, int y, int val)
{
	grid->valid_values[x][y] &= ~(1 << (val - 1));
}

void	r01_set_value_valid(t_r01_grid *grid, int x, int y, int val)
{
	grid->valid_values[x][y] |= 1 << (val - 1);
}
