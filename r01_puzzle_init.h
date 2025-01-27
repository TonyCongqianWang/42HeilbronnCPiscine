/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle_init.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 21:42:53 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_PUZZLE_INIT_H
# define R01_PUZZLE_INIT_H
# include "r01_structs.h"

void	r01_init_puzzle(t_r01_grid *grid, t_r01_constraints *constrs, int size);
void	r01_init_arrays(t_r01_grid *grid, int size);
void	r01_init_maps(t_r01_constraints *constrs, int idx, int size);
int		r01_try_update_valid_values(t_r01_grid *grid, int idx, int val);
void	r01_set_grid_val(t_r01_grid *grid, int idx, int val);

#endif