/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:36 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 18:17:55 by towang           ###   ########.fr       */
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

int	r01_parse_input(t_r01_constraints *cons, char *str)
{
	int		size;
	int		group_idx;
	int		constr_idx;
	int		val;

	size = r01_parse_input_size(str);
	if (!size)
		return (0);
	cons->size = size;
	group_idx = 0;
	constr_idx = 0;
	while (group_idx < 4)
	{
		while (constr_idx < (group_idx + 1) * size)
		{
			val = str[2 * constr_idx] - '0';
			if (val > size)
				return (0);
			cons->vals[constr_idx % size][group_idx] = val;
			constr_idx++;
		}
		group_idx++;
	}
	return (1);
}

void	r01_print_grid(t_r01_grid *grid)
{
	int		x;
	int		y;
	char	val;

	x = 0;
	while (x < grid->size)
	{
		y = 0;
		while (y < grid->size)
		{
			val = grid->grid_vals[x][y] + '0';
			write(1, &val, 1);
			if (y < grid->size - 1)
				write(1, " ", 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

void	r01_print_error(void)
{
	write(1, "Error\n", 6);
}
