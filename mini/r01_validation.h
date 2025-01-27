/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:27:09 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 15:12:34 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_VALIDATION_H
# define R01_VALIDATION_H
# include "r01_structs.h"

int	r01_check_grid(t_r01_grid *grid, t_r01_constraints *constr, int x, int y);
int	r01_check_grid_row(t_r01_grid *grid, int y, int reverse, int c_val);
int	r01_check_grid_col(t_r01_grid *grid, int x, int reverse, int c_val);

#endif