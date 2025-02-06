/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:58:23 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 00:14:08 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdlib.h>

void	free_map(t_map	*map)
{
	map->dims.height = 0;
	map->dims.width = 0;
	if (map->values)
		free(map->values);
	map->values = 0;
}

void	free_sol_state(t_solver_state	*sol_state)
{
	sol_state->dims.height = 0;
	sol_state->dims.width = 0;
	if (sol_state->best_squares)
		free(sol_state->best_squares);
	sol_state->best_square = 0;
}
