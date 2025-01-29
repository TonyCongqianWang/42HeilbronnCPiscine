/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_update.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/29 19:13:22 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_UPDATE_H
# define GRID_UPDATE_H
# include "puzzle_structs.h"

int		try_grid_val(t_puzzle *grid, int cell_idx, int val);
void	set_grid_val(t_puzzle *grid, int cell_idx, int val);
void	unset_grid_val(t_puzzle *grid, int cell_idx);
int		check_constraints(t_puzzle *puzzle, int insert_idx);

#endif
