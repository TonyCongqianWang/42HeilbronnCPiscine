/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_constraint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:31:51 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 23:18:46 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_constraint.h"

void	r01_check_constraints(t_r01_grid *puzzle, int insert_idx)
{
	int					rel_idx;
	int					abs_idx;
	int					last_idx;
	t_r01_constraints	*constr;

	rel_idx = 0;
	constr = puzzle->constraints;
	while (rel_idx < 4 && !puzzle->is_invalid)
	{
		last_idx = abs_idx;
		abs_idx = constr->grid_constr_map[insert_idx][rel_idx];
		r01_set_active_constraint(constr, abs_idx);
		if (rel_idx % 2 == 1)
		{
			constr->cur_ub = constr->size + 1 - constr->last_lb;
			puzzle->is_invalid = !r01_check_active_constr(puzzle);
			constr->last_ub = constr->size + 1 - constr->cur_lb;
			puzzle->is_invalid |= constr->last_ub < constr->vals[last_idx];
		}
		else
			puzzle->is_invalid = !r01_check_active_constr(puzzle);
		if (puzzle->min_unset_count > constr->n_unset)
			puzzle->min_unset_count = constr->n_unset;
		rel_idx++;
	}
}

void	r01_set_active_constraint(t_r01_constraints *constr, int constr_idx)
{
	constr->max_height = 0;
	constr->n_seen = 0;
	constr->n_unset = 0;
	constr->last_lb = constr->cur_lb;
	constr->cur_lb = 0;
	constr->cur_ub = constr->size;
	constr->active_idx = constr_idx;
}

int	r01_check_active_constr(t_r01_grid *puzzle)
{
	int					sub_idx;
	int					grid_idx;
	int					size;
	t_r01_constraints	*constr;
	int					constr_idx;

	size = puzzle->size;
	sub_idx = 0;
	constr = puzzle->constraints;
	constr_idx = constr->active_idx;
	while (sub_idx < size)
	{
		grid_idx = constr->constr_grid_map[constr_idx][sub_idx];
		r01_insert_val(constr, puzzle->grid_vals[grid_idx]);
		r01_update_constr(constr, sub_idx);
		sub_idx++;
		if (constr->cur_lb > constr->vals[constr_idx])
			return (0);
		if (constr->cur_ub < constr->vals[constr_idx])
			return (0);
	}
	return (1);
}

void	r01_insert_val(t_r01_constraints *constr, int val)
{
	if (val == 0)
		constr->n_unset++;
	else if (val > constr->max_height)
	{
		constr->max_height = val;
		constr->n_seen++;
	}
}

void	r01_update_constr(t_r01_constraints *constr, int idx)
{
	int		lhs_ub;
	int		rhs_ub;
	int		new_lb;
	int		constr_idx;
	int		size;

	size = constr->size;
	constr_idx = constr->active_idx;
	new_lb = constr->n_seen > constr->cur_lb;
	if (constr->max_height < size)
		new_lb += 1;
	if (constr->n_unset == 0 && new_lb > constr->cur_lb)
		constr->cur_lb = new_lb;
	lhs_ub = constr->n_seen + constr->n_unset;
	rhs_ub = size - constr->max_height;
	if (size - idx - 1 < rhs_ub)
		rhs_ub = size - idx - 1;
	if (lhs_ub + rhs_ub < constr->cur_ub)
		constr->cur_ub = lhs_ub + rhs_ub;
}
