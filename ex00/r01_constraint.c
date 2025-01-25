/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_constraint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:31:51 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 00:00:53 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01_constraint.h"

void	r01_check_constraints(t_r01_puzzle *puzzle)
{
	int					idx;
	int					sub_idx;
	t_r01_constraint	constraint;

	idx = 0;
	while (idx < 4 * puzzle->size)
	{
		constraint.idx = idx;
		constraint.size = puzzle->size;
		constraint.target_val = puzzle->constr_vals[idx];
		constraint.max_height = 0;
		constraint.n_seen = 0;
		constraint.n_unset = 0;
		sub_idx = 0;
		while (sub_idx < puzzle->size)
		{
			constraint.present_vals[sub_idx] = 0;
			sub_idx++;
		}
		puzzle->is_invalid = !r01_check_constr(puzzle, &constraint);
		r01_update_min_unset(puzzle, constraint.n_unset);
		if (puzzle->is_invalid)
			return ;
		idx++;
	}
}

#include "r01_io.h"
#include "stdio.h"
int	r01_check_constr(t_r01_puzzle *puzzle, t_r01_constraint *constraint)
{
	int		constr_sub_idx;
	int		grid_idx;

	constr_sub_idx = 0;
	while (constr_sub_idx < constraint->size)
	{
		grid_idx = r01_get_grid_idx_for_constr(constraint, constr_sub_idx);
		if (!r01_try_update_constr(puzzle->grid_vals[grid_idx], constraint))
		{
			// printf("violated constraint %d %d %d\n", constraint->idx, constraint->n_seen, constr_sub_idx);
			// print_puzzle_grid(puzzle);
			return (0);
		}
		if (r01_check_constr_violation(constraint, constr_sub_idx))
		{
			// printf("violated constraint %d %d %d\n", constraint->idx, constraint->n_seen, constr_sub_idx);
			// print_puzzle_grid(puzzle);
			return (0);
		}
		constr_sub_idx++;
	}
	return (constraint->n_seen + constraint->n_unset >= constraint->target_val);
}

int	r01_get_grid_idx_for_constr(t_r01_constraint *constraint, int sub_idx)
{
	int		constr_idx;
	int		size;
	int		grid_idx;

	constr_idx = constraint->idx;
	size = constraint->size;
	grid_idx = -1;
	if (constr_idx < size)
		grid_idx = constr_idx + sub_idx * size;
	else if (constr_idx < 2 * size)
		grid_idx = (constr_idx % size) + (size - sub_idx - 1) * size;
	else if (constr_idx < 3 * size)
		grid_idx = (constr_idx % size) * size + sub_idx;
	else if (constr_idx < size * size)
		grid_idx = ((constr_idx % size) + 1) * size - 1 - sub_idx;
	return (grid_idx);
}

int	r01_check_constr_violation(t_r01_constraint *constr, int sub_idx)
{
	int		lhs_ub;
	int		rhs_ub;

	if (constr->n_unset == 0 && constr->n_seen > constr->target_val)
		return (1);
	lhs_ub = constr->n_seen + constr->n_unset;
	rhs_ub = constr->size - constr->max_height;
	if (constr->size - sub_idx - 1 < rhs_ub)
		rhs_ub = constr->size - sub_idx - 1;
	if (lhs_ub + rhs_ub < constr->target_val)
		return (1);
	return (0);
}

int	r01_try_update_constr(int val, t_r01_constraint *constr)
{
	if (val > 0)
	{
		constr->present_vals[val - 1]++;
		if (constr->present_vals[val - 1] > 1)
			return (0);
	}
	if (val == 0)
	{
		constr->n_unset++;
	}
	else if (val > constr->max_height)
	{
		constr->max_height = val;
		constr->n_seen++;
	}
	return (1);
}
