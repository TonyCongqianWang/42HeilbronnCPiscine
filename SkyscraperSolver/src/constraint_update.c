/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraint_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:31:51 by towang            #+#    #+#             */
/*   Updated: 2025/01/30 20:47:14 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constraint_update.h"
#include "cell_bitmaps.h"
#include "cell_bounds.h"

int	update_constr_state(t_puzzle *puzzle, int abs_idx)
{
	t_constraint_state	*constr;
	int					new_val;
	short				val_lb;
	short				val_ub;

	constr = &puzzle->constr_state;
	new_val = puzzle->grid_vals[abs_idx];
	if (new_val == 0)
	{
		if (constr->max_height_lb == puzzle->size)
			return (1);
		get_cell_bounds(&puzzle->node_state, abs_idx, &val_lb, &val_ub);
		return (update_constr_state_unset(constr, val_lb, val_ub));
	}
	else
		return (update_constr_state_new_val(constr, new_val));
}

int	update_constr_state_unset(t_constraint_state *constr, int lb, int ub)
{
	if (ub > constr->max_height_lb)
	{
		constr->lhs_ub++;
		if (lb > constr->max_height_ub)
		{
			constr->max_height_lb = lb;
			constr->max_height_ub = ub;
			if (ub != constr->size)
				constr->fwd_lb++;
		}
		else
		{
			if (ub > constr->max_height_ub)
				constr->max_height_ub = ub;
			if (lb > constr->max_height_lb)
				constr->max_height_lb = lb;
		}
	}
	return (1);
}

int	update_constr_state_new_val(t_constraint_state *constr, int new_val)
{
	if (new_val == constr->size)
	{
		constr->max_height_lb = constr->size;
		constr->lhs_ub++;
		return (0);
	}
	if (new_val > constr->max_height_lb)
	{
		constr->lhs_ub++;
		constr->max_height_lb = new_val;
		if (new_val > constr->max_height_ub)
		{
			constr->fwd_lb++;
			constr->max_height_ub = new_val;
		}
	}
	if (new_val > constr->max_height_seen)
	{
		constr->bwd_ub--;
		constr->max_height_seen = new_val;
	}
	return (1);
}
