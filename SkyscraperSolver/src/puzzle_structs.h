/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/30 19:47:55 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLE_STRUCTS_H
# define PUZZLE_STRUCTS_H
# define MAX_N_CONSTR_PAIRS 18
# define MAX_CELL_COUNT 81
# define MAX_SIZE 9
# define C_PAIRS_PER_CELL 2

typedef struct s_puzzle	t_puzzle;

typedef struct s_node_transition
{
	int					cell_idx;
	char				cell_val;
	int					num_valids_col;
	int					num_valids_row;
	int					num_valids_cell;
	double				score;
}				t_node_transition;

typedef struct s_node_state
{
	t_puzzle			*puzzle;
	int					size;
	int					is_complete;
	int					is_invalid;
	int					total_unset_count;
	short				valid_val_bmps[MAX_CELL_COUNT];
	char				cell_bounds[MAX_CELL_COUNT];
	char				num_valid_vals_for_cell[MAX_CELL_COUNT];
	char				num_valid_cells_for_val[MAX_N_CONSTR_PAIRS][MAX_SIZE];
}				t_node_state;

typedef struct s_constraint_pair
{
	int				fwd_val;
	int				bwd_val;
	int				grid_indeces[MAX_SIZE];
}				t_constraint_pair;

typedef struct s_constraint_bounds
{
	int					size;
	t_constraint_pair	cur_c_pair;
	int					is_reverse;
	int					fwd_lb;
	int					lhs_ub;
	int					bwd_ub;
	int					max_height_lb;
	int					max_height_ub;
	int					max_height_seen;
}				t_constraint_bounds;

typedef struct s_puzzle
{
	int						size;
	int						nodes_visited;
	t_constraint_pair		constraint_pairs[MAX_N_CONSTR_PAIRS];
	int						grid_constr_map[MAX_CELL_COUNT][C_PAIRS_PER_CELL];
	char					grid_vals[MAX_CELL_COUNT];
	t_node_state			node_state;
	t_constraint_bounds		constr_bounds;
}				t_puzzle;

#endif
