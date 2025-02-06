/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:39:11 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/05 00:10:24 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_utils.h"
#include <unistd.h>

void	ft_putstr(const char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putline(const char *str, unsigned long l)
{
	unsigned long	i;

	i = 0;
	while (i < l)
	{
		write(1, &str[i], 1);
		i++;
	}
	ft_putstr("\n");
}

void	print_map_error(void)
{
	ft_putline("map error", 9);
}

void	print_map(t_map map)
{
	unsigned long	i;

	i = 0;
	while (i < map.dims.height)
	{
		ft_putline(&map.values[map.dims.width * i], map.dims.width);
		i++;
	}
}
