/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:10:14 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/05 01:09:08 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include "structs.h"

void		solve(t_map map);
void		dynamic_sq_expansion(t_solver_state *sol_state);
t_map_dim	new_sq_size(t_solver_state *sol_state, t_map_dim idx);

#endif