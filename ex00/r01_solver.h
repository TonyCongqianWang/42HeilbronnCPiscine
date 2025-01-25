/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_solver.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:46 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 20:27:55 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_SOLVER_H
# define R01_SOLVER_H

# include "r01_puzzle.h"

t_r01_puzzle	r01_solve_puzzle(t_r01_puzzle *puzzle);
int				r01_get_next_grid_idx(t_r01_puzzle *puzzle);

#endif