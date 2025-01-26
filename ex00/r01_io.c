/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:36 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 12:57:05 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "r01_io.h"

int	r01_parse_input_size(char *str)
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
		else if (!space_expected)
			counter++;
		space_expected = !space_expected;
		str++;
	}
	if (!space_expected)
		return (0);
	if (counter % 4 != 0)
		return (0);
	if ((counter / 4) > 9 || (counter / 4) < 1)
		return (0);
	return (counter / 4);
}

void	r01_parse_input(t_r01_grid *grid, t_r01_constraints *constrs, char *str)
{
	int		size;
	int		counter;
	int		val;

	size = r01_parse_input_size(str);
	
	r01_init_puzzle(grid, constrs, size);
	counter = 0;
	while (counter < 4 * size)
	{
		val = str[2 * counter] - '0';
		if (val > size)
			grid->is_invalid = 1;
		constrs->vals[counter] = val;
		counter++;
	}
}

void	r01_print_grid(t_r01_grid *grid)
{
	int		counter;
	char	val;

	counter = 0;
	while (counter < grid->size * grid->size)
	{
		val = '0' + grid->grid_vals[counter];
		write(1, &val, 1);
		if (counter % grid->size != grid->size - 1)
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

void	r01_print_error(void)
{
	write(1, "Error\n", 6);
}
