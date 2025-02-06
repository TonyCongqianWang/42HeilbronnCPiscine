/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_coordinates.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:52:03 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 01:04:47 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_COORDINATES_H
# define GRID_COORDINATES_H

# include "structs.h"

t_map_dim		get_x_coord_from_idx(t_map_dims dims, t_map_dim idx);
t_map_dim		get_y_coord_from_idx(t_map_dims dims, t_map_dim idx);
t_map_dim		convert_coord_to_idx(t_map_dims dims, t_map_dim y, t_map_dim x);
t_idx_tripplet	get_neighbour_idxs(t_map_dims dims, t_map_dim idx);

#endif