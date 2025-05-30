/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraint_update.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:31:47 by towang            #+#    #+#             */
/*   Updated: 2025/01/30 20:46:00 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRAINT_UPDATE_H
# define CONSTRAINT_UPDATE_H
# include "puzzle_structs.h"

int	update_constr_bounds(t_puzzle *puzzle, int cell_idx);
int	update_constr_bounds_unset(t_constraint_bounds *constr, int lb, int ub);
int	update_constr_bounds_new_val(t_constraint_bounds *constr, int new_val);

#endif