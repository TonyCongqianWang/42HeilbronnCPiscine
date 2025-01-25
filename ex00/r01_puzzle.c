/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 17:41:00 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stdlib for malloc if we want to modify for bonus tasks
// #include <stdlib.h>
#include "r01_puzzle.h"

void	r01_initialize_puzzle(t_r01_puzzle *puzzle, int size)
{
	int		idx;

	idx = 0;
	puzzle->size = size;
	puzzle->is_complete = 0;
	puzzle->is_invalid = 0;
	if (size == 0)
		puzzle->is_invalid = 0;
	while (idx < size * size)
	{
		puzzle->grid_vals[idx] = 0;
	}
	idx = 0;
	while (idx < 4 * size)
	{
		puzzle->constr_vals[idx] = 0;
	}
}

void	r01_set_grid_number(t_r01_puzzle *puzzle, int x, int y, int val)
{
	int		idx;

	idx = x + puzzle->size * y;
	puzzle->grid_vals[idx] = val;
}
