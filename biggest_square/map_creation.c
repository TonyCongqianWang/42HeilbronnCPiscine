/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:36:31 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 15:08:14 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creation.h"
#include <stdlib.h>

int	try_read_map_from_str(t_map *map, char *str)
{
	unsigned long	total_vals;

	if (!try_parse_map_info(map, &str))
		return (0);
	map->values = (char *)(0);
	total_vals = 0;
	while (str[total_vals] && str[total_vals] != '\n')
		total_vals++;
	if (!str[total_vals] || !total_vals)
		return (0);
	map->dims.width = total_vals;
	total_vals *= map->dims.height;
	map->values = (char *)malloc(total_vals * sizeof(char *) + 1);
	if (!map->values)
		return (0);
	map->values[total_vals + 1] = '\0';
	if (!try_parse_map_values(map, str))
	{
		free_map(map);
		return (0);
	}
	return (1);
}

int	try_parse_map_info(t_map *map, char **str)
{
	char	*read_pos;

	read_pos = *str;
	map->dims.height = 0;
	map->dims.width = 0;
	while (*read_pos >= '0' && *read_pos <= '9')
		map->dims.height = (10 * map->dims.height) + (*(read_pos++) - '0');
	if (!map->dims.height)
		return (0);
	*str = read_pos;
	return (try_parse_map_characters(map, str));
}

int	try_parse_map_characters(t_map *map, char **str)
{
	char	*read_pos;

	read_pos = *str;
	if (*(read_pos) >= 32 && *(read_pos) <= 126)
		map->empty_ch = *(read_pos++);
	else
		return (0);
	if (*(read_pos) >= 32 && *(read_pos) <= 126)
		map->obstacle_ch = *(read_pos++);
	else
		return (0);
	if (*(read_pos) >= 32 && *(read_pos) <= 126)
		map->full_ch = *(read_pos++);
	else
		return (0);
	if (*(read_pos++) != '\n')
		return (0);
	*str = read_pos;
	return (map->empty_ch != map->obstacle_ch
		&& map->obstacle_ch != map->full_ch
		&& map->full_ch != map->empty_ch);
}

int	try_parse_map_values(t_map *map, char *str)
{
	unsigned long	n_lines_read;

	n_lines_read = 0;
	while (*str && n_lines_read < map->dims.height)
	{
		if (!try_parse_map_line(map, str, &n_lines_read))
			return (0);
		str += map->dims.width + 1;
	}
	return (*str == '\0' && n_lines_read == map->dims.height);
}

int	try_parse_map_line(t_map *map, char *src, unsigned long *n_lines_read)
{
	char			*write_pos;
	unsigned long	n_chars_written;

	write_pos = map->values + (*n_lines_read) * map->dims.width;
	n_chars_written = 0;
	while (src[n_chars_written]
		&& src[n_chars_written] != '\n'
		&& n_chars_written < map->dims.width)
	{
		if (src[n_chars_written] != map->empty_ch
			&& src[n_chars_written] != map->obstacle_ch)
			return (0);
		write_pos[n_chars_written] = src[n_chars_written];
		n_chars_written++;
	}
	(*n_lines_read)++;
	return (src[n_chars_written] == '\n' && n_chars_written == map->dims.width);
}
