/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:36 by towang            #+#    #+#             */
/*   Updated: 2025/01/30 23:14:29 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print_grid.h"
#include "grid_update.h"
#include "cell_bounds.h"
#include "puzzle_solver.h"

void	print_solution_grid(t_puzzle *puzzle)
{
	int		counter;
	char	val;

	counter = 0;
	while (counter < puzzle->size * puzzle->size)
	{
		val = '0' + puzzle->node_state.grid.vals[counter];
		write(1, &val, 1);
		if (counter % puzzle->size != puzzle->size - 1)
		{
			write(1, " ", 1);
		}
		else
		{
			write(1, "\n", 1);
		}
		counter++;
	}
}

void	print_bmp_grid(t_puzzle *puzzle, int cell_val)
{
	int				cell_idx;
	char			print_val;
	t_node_state	*node_state;

	cell_idx = 0;
	node_state = &puzzle->node_state;
	while (cell_idx < puzzle->size * puzzle->size)
	{
		print_val = '0';
		print_val += is_valid_value(node_state, cell_idx, cell_val) != 0;
		write(1, &print_val, 1);
		if (cell_idx % puzzle->size != puzzle->size - 1)
		{
			write(1, " ", 1);
		}
		else
		{
			write(1, "\n", 1);
		}
		cell_idx++;
	}
}

void	print_bound_grid(t_node_state *node_state, int is_ub)
{
	int				cell_idx;
	short			cell_lb;
	short			cell_ub;
	char			print_val;

	cell_idx = 0;
	while (cell_idx < node_state->size * node_state->size)
	{
		print_val = '0';
		get_cell_bounds(node_state, cell_idx, &cell_lb, &cell_ub);
		if (!is_ub)
			print_val += cell_lb;
		else
			print_val += cell_ub;
		write(1, &print_val, 1);
		if (cell_idx % node_state->size != node_state->size - 1)
		{
			write(1, " ", 1);
		}
		else
		{
			write(1, "\n", 1);
		}
		cell_idx++;
	}
}
