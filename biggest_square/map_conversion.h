/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:11:13 by towang            #+#    #+#             */
/*   Updated: 2025/02/04 23:24:55 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CONVERSION_H
# define MAP_CONVERSION_H

# include "structs.h"

int		init_solver_state_from_map(t_solver_state *sol_state, t_map map);
void	write_sol_into_map(t_map map, t_solver_state sol_state);

#endif