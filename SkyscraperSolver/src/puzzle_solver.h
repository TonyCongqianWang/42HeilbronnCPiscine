/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_solver.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:46 by towang            #+#    #+#             */
/*   Updated: 2025/01/31 00:29:51 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLE_SOLVER_H
# define PUZZLE_SOLVER_H
# include "puzzle_structs.h"

int	solve_puzzle(t_puzzle *puzzle);
int	tree_search(t_puzzle *puzzle, int depth);
int	set_best_transition_val(t_puzzle *puzzle, int idx, t_node_transition *next);
int	try_get_next_transition(t_puzzle *puzzle, t_node_transition *next);

#endif
