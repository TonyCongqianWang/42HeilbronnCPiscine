/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:36 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 17:36:33 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "r01_io.h"

int	get_puzzle_size_from_input(char *str)
{
	int		space_expected;
	int		counter;

	counter = 0;
	space_expected = 0;
	while (*str)
	{
		if (space_expected && *str != ' ')
			return (0);
		else if (!space_expected && (*str < '1' || *str > '9'))
			return (0);
		space_expected = !space_expected;
		counter++;
	}
	if (counter % 4 != 0)
		return (0);
	if (counter / 4 != 4)
		return (0);
	return (counter / 4);
}

void	parse_input_str(t_r01_puzzle *puzzle, char *str)
{
	int		size;
	int		counter;
	int		val;

	size = get_puzzle_size_from_input(str);
	r01_initialize_puzzle(puzzle, size);
	counter = 0;
	while (counter < 4 * size)
	{
		val = str[2 * counter] - '0';
		if (val > size)
			puzzle->is_invalid = 1;
		puzzle->grid_vals[counter] = val;
		counter++;
	}
}

void	print_puzzle_grid(t_r01_puzzle *puzzle)
{
	int		x;
	int		y;
	int		counter;
	char	val;

	x = 0;
	y = 0;
	counter = 0;
	while (y < puzzle->size)
	{
		while (y < puzzle->size - 1)
		{
			val = '0' + puzzle->grid_vals[counter];
			write(1, &val, 1);
			write(1, " ", 1);
		}
		val = '0' + puzzle->grid_vals[counter];
		write(1, &val, 1);
		write(1, "\n", 1);
	}
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
