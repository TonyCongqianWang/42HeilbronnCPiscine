/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_constraint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:31:51 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 02:42:00 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_constraint.h"

void	r01_check_constraints(t_r01_puzzle *puzzle)
{
	int					idx;
	t_r01_constraint	*constr;

	idx = 0;
	while (idx < 4 * puzzle->size)
	{
		constr = &(puzzle->constraints[idx]);
		constr->max_height = 0;
		constr->n_seen = 0;
		constr->n_unset = 0;
		puzzle->is_invalid = !r01_check_constr(puzzle, constr);
		if (puzzle->is_invalid)
			return ;
		r01_update_min_unset(puzzle, puzzle->constraints[idx].n_unset);
		idx++;
	}
}

int	r01_check_constr(t_r01_puzzle *puzzle, t_r01_constraint *constraint)
{
	int		constr_sub_idx;
	int		grid_idx;
	int		size;

	size = puzzle->size;
	constr_sub_idx = 0;
	while (constr_sub_idx < size)
	{
		grid_idx = constraint->grid_indeces[constr_sub_idx];
		r01_try_update_constr(puzzle->grid_vals[grid_idx], constraint);
		if (r01_check_violation(constraint, constr_sub_idx, size))
		{
			return (0);
		}
		constr_sub_idx++;
	}
	return (constraint->n_seen + constraint->n_unset >= constraint->target_val);
}

int	r01_check_violation(t_r01_constraint *constr, int sub_idx, int size)
{
	int		lhs_ub;
	int		rhs_ub;

	if (constr->n_unset == 0 && constr->n_seen > constr->target_val)
		return (1);
	lhs_ub = constr->n_seen + constr->n_unset;
	rhs_ub = size - constr->max_height;
	if ( size - sub_idx - 1 < rhs_ub)
		rhs_ub = size - sub_idx - 1;
	if (lhs_ub + rhs_ub < constr->target_val)
		return (1);
	return (0);
}

void	r01_try_update_constr(int val, t_r01_constraint *constr)
{
	if (val == 0)
	{
		constr->n_unset++;
	}
	else if (val > constr->max_height)
	{
		constr->max_height = val;
		constr->n_seen++;
	}
}
