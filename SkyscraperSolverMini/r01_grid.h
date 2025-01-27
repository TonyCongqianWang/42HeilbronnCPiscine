/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_grid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:03:56 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 16:06:38 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_GRID_H
# define R01_GRID_H
# include "r01_structs.h"

void	r01_init_grid(t_r01_grid *grid, int size);
int		r01_try_set_value(t_r01_grid *grid, int x, int y, int val);
int		r01_get_num_valid_values(t_r01_grid *grid, int x, int y);
int		r01_is_valid_value(t_r01_grid *grid, int x, int y, int val);
void	r01_set_value_invalid(t_r01_grid *grid, int x, int y, int val);
void	r01_set_value_valid(t_r01_grid *grid, int x, int y, int val);
void	r01_unset_value(t_r01_grid *grid, int x, int y);

#endif
