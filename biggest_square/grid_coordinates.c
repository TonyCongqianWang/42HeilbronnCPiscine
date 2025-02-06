/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:52:01 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 14:16:13 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid_coordinates.h"

t_map_dim	get_x_coord_from_idx(t_map_dims dims, t_map_dim idx)
{
	return (idx % dims.width);
}

t_map_dim	get_y_coord_from_idx(t_map_dims dims, t_map_dim idx)
{
	return (idx / dims.width);
}

t_map_dim	convert_coord_to_idx(t_map_dims dims, t_map_dim y, t_map_dim x)
{
	t_map_dim	index;

	index = y * dims.width + x;
	return (index);
}

t_idx_tripplet	get_neighbour_idxs(t_map_dims dims, t_map_dim idx)
{
	t_idx_tripplet	neighbour_idxs;

	neighbour_idxs.idxs[0] = idx - 1;
	neighbour_idxs.idxs[1] = idx - dims.width;
	neighbour_idxs.idxs[2] = idx - dims.width - 1;
	return (neighbour_idxs);
}
