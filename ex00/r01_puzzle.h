/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 02:41:41 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_PUZZLE_H
# define R01_PUZZLE_H
# define R01_MAX_CONSTR_SIZE 36
# define R01_MAX_GRID_SIZE 81
# define R01_MAX_SIZE 9

typedef struct s_r01_constraint
{
	int		max_height;
	int		n_seen;
	int		n_unset;
	int		target_val;
	int		grid_indeces[R01_MAX_SIZE];
}				t_r01_constraint;

typedef struct s_r01_puzzle
{
	int					size;
	int					is_complete;
	int					is_invalid;
	int					min_unset_count;
	t_r01_constraint	constraints[R01_MAX_CONSTR_SIZE];
	char				grid_vals[R01_MAX_GRID_SIZE];
	int					valid_values[R01_MAX_GRID_SIZE];
}				t_r01_puzzle;

void	r01_initialize_puzzle(t_r01_puzzle *puzzle, int size);
void	r01_set_grid_val(t_r01_puzzle *puzzle, int idx, int val);
void	r01_update_min_unset(t_r01_puzzle *puzzle, int unset_count);
int		r01_try_update_valid_values(t_r01_puzzle *puzzle, int idx, int val);
void	init_constr_indeces(t_r01_constraint *constraint, int idx, int size);

#endif