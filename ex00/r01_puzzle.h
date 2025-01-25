/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 22:33:01 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_PUZZLE_H
# define R01_PUZZLE_H
# define R01_CONSTR_SIZE 36
# define R01_GRID_SIZE 81

typedef struct s_r01_puzzle
{
	int		size;
	int		is_complete;
	int		is_invalid;
	int		min_unset_count;
	int		constr_vals[R01_CONSTR_SIZE];
	int		grid_vals[R01_GRID_SIZE];
}				t_r01_puzzle;

void	r01_initialize_puzzle(t_r01_puzzle *puzzle, int size);
void	r01_set_grid_val(t_r01_puzzle *puzzle, int idx, int val);
void	r01_update_min_unset(t_r01_puzzle *puzzle, int unset_count);

#endif