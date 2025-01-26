/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_constraint.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:31:47 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 12:23:06 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_CONSTRAINT_H
# define R01_CONSTRAINT_H
# include "r01_puzzle.h"

void	r01_check_constraints(t_r01_grid *puzzle);
int		r01_check_active_constr(t_r01_grid *puzzle);
int		r01_check_violation(t_r01_constraints *constr, int sub_idx, int size);
void	r01_update_constr(t_r01_constraints *constr, int val);

#endif