/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:36 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 16:41:46 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "r01_io.h"
#include <stdio.h>

int	r01_parse_input_size(char *str)
{
	int		last_space;
	int		counter;

	counter = 1;
	last_space = 0;
	while (*str)
	{
		if (last_space && *str == ' ')
			return (0);
		if (*str == ' ')
		{
			counter++;
			last_space = 1;
		}
		else if (*str < '0' || *str > '9')
			return (0);
		else
		{
			last_space = 0;
		}
		str++;
	}
	if (last_space)
		return (0);
	if (counter % 4 != 0)
		return (0);
	if ((counter / 4) > 16 || (counter / 4) < 1)
		return (0);
	return (counter / 4);
}

void	r01_parse_input(t_r01_grid *grid, t_r01_constraints *cons, char *str)
{
	int		size;
	int		counter;
	int		val;

	size = r01_parse_input_size(str);
	r01_init_puzzle(grid, cons, size);
	counter = 0;
	while (counter < 4 * size)
	{
		val = 0;
		while (*str >= '0' && *str <= '9')
		{
			val *= 10;
			val += *str - '0';
			str++;
		}
		str++;
		if (val > size)
			grid->is_invalid = 1;
		cons->vals[counter] = val;
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
		if (val > '9') val += + 'a' - 1 - '9';
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
