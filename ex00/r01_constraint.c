/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_constraint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:31:51 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 13:07:12 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_constraint.h"

void	r01_check_constraints(t_r01_grid *puzzle, int insert_idx)
{
	int					constr_idx;
	t_r01_constraints	*constr;

	constr_idx = 0;
	constr = puzzle->constraints;
	while (constr_idx < 4)
	{
		constr->max_height = 0;
		constr->n_seen = 0;
		constr->n_unset = 0;
		constr->active_idx = constr->grid_constr_map[insert_idx][constr_idx];
		puzzle->is_invalid = !r01_check_active_constr(puzzle);
		if (puzzle->is_invalid)
			return ;
		if (puzzle->min_unset_count > constr->n_unset)
			puzzle->min_unset_count = constr->n_unset;
		constr_idx++;
	}
}

int	r01_check_active_constr(t_r01_grid *puzzle)
{
	int					constr_sub_idx;
	int					grid_idx;
	int					size;
	t_r01_constraints	*constr;
	int					constr_idx;

	size = puzzle->size;
	constr_sub_idx = 0;
	constr = puzzle->constraints;
	constr_idx = constr->active_idx;
	while (constr_sub_idx < size)
	{
		grid_idx = constr->constr_grid_map[constr_idx][constr_sub_idx];
		r01_update_constr(constr, puzzle->grid_vals[grid_idx]);
		if (r01_check_violation(constr, constr_sub_idx, size))
		{
			return (0);
		}
		constr_sub_idx++;
	}
	return (constr->n_seen + constr->n_unset >= constr->vals[constr_idx]);
}

int	r01_check_violation(t_r01_constraints *constr, int sub_idx, int size)
{
	int		lhs_ub;
	int		rhs_ub;
	int		constr_idx;

	constr_idx = constr->active_idx;
	if (constr->n_unset == 0 && constr->n_seen > constr->vals[constr_idx])
		return (1);
	lhs_ub = constr->n_seen + constr->n_unset;
	rhs_ub = size - constr->max_height;
	if (size - sub_idx - 1 < rhs_ub)
		rhs_ub = size - sub_idx - 1;
	if (lhs_ub + rhs_ub < constr->vals[constr_idx])
		return (1);
	return (0);
}

void	r01_update_constr(t_r01_constraints *constr, int val)
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
