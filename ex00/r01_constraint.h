/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_constraint.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:31:47 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 22:56:20 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_CONSTRAINT_H
# define R01_CONSTRAINT_H
# include "r01_puzzle.h"

typedef struct s_r01_constraint
{
	int		idx;
	int		size;
	int		max_height;
	int		n_seen;
	int		n_unset;
	int		target_val;
	int		present_vals[R01_MAX_SIZE];
}				t_r01_constraint;

void	r01_check_constraints(t_r01_puzzle *puzzle);
int		r01_check_constr(t_r01_puzzle *puzzle, t_r01_constraint *constraint);
int		r01_check_constr_violation(t_r01_constraint *constr, int sub_idx);
int		r01_get_grid_idx_for_constr(t_r01_constraint *constraint, int sub_idx);
int		r01_try_update_constr(int val, t_r01_constraint *constr);

#endif