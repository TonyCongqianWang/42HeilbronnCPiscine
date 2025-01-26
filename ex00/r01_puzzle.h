/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/26 12:21:51 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_PUZZLE_H
# define R01_PUZZLE_H
# define R01_MAX_CONSTR_SIZE 36
# define R01_MAX_GRID_SIZE 81
# define R01_MAX_SIZE 9
# define R01_CONSTRS_PER_VAL 4

typedef struct s_r01_constraints
{
	int				size;
	int				active_idx;
	int				cur_ub;
	int				cur_lb;	
	int				max_height;
	int				n_seen;
	int				n_unset;
	int				vals[R01_MAX_CONSTR_SIZE];
	int				complement_indece[R01_MAX_CONSTR_SIZE];
	int				grid_constr_map[R01_MAX_GRID_SIZE][R01_CONSTRS_PER_VAL];
	int				constr_grid_map[R01_MAX_CONSTR_SIZE][R01_MAX_SIZE];
}				t_r01_constraints;

typedef struct s_r01_grid
{
	int					size;
	int					is_complete;
	int					is_invalid;
	int					min_unset_count;
	t_r01_constraints	*constraints;
	char				grid_vals[R01_MAX_GRID_SIZE];
	short				valid_values[R01_MAX_GRID_SIZE];
}				t_r01_grid;

void	r01_initialize_puzzle(t_r01_grid *puzzle, int size);
void	init_constr_indeces(t_r01_constraints *constraints, int idx, int size);
void	r01_update_min_unset(t_r01_grid *puzzle, int unset_count);
int		r01_try_update_valid_values(t_r01_grid *puzzle, int idx, int val);
void	r01_set_grid_val(t_r01_grid *puzzle, int idx, int val);

#endif