/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:36 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 15:27:31 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "r01_io.h"

int	is_input_str_format_valid(char *str)
{
	return (0);
}

t_r01_puzzle	parse_input_str(char *str)
{
	t_r01_puzzle	res;

	return (res);
}

void	print_puzzle_grid(t_r01_puzzle puzzle)
{
	int		x;
	int		y;
	int		counter;
	char	val;

	x = 0;
	y = 0;
	counter = 0;
	while (y < puzzle.size)
	{
		while (y < puzzle.size - 1)
		{
			val = '0' + puzzle.grid_vals[counter];
			write(1, &val, 1);
			write(1, " ", 1);
		}
		val = '0' + puzzle.grid_vals[counter];
		write(1, &val, 1);
		write(1, "\n", 1);
	}
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
