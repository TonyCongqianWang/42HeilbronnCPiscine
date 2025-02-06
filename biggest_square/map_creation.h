/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:36:31 by towang            #+#    #+#             */
/*   Updated: 2025/02/04 21:35:10 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CREATION_H
# define MAP_CREATION_H

# include "structs.h"

int	try_read_map_from_str(t_map *map, char *str);
int	try_parse_map_info(t_map *map, char **str);
int	try_parse_map_characters(t_map *map, char **str);
int	try_parse_map_values(t_map *map, char *str);
int	try_parse_map_line(t_map *map, char *src, unsigned long *n_lines_read);

#endif
