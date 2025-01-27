/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 21:34:29 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_STRUCTS_H
# define R01_STRUCTS_H
# define R01_MAX_CONSTR_SIZE 36
# define R01_MAX_GRID_SIZE 81
# define R01_MAX_SIZE 9
# define R01_CONSTRS_PER_VAL 4

typedef struct s_r01_constraints
{
	int				size;
	int				active_idx;
	int				cur_lb;	
	int				cur_ub;
	int				rev_lb;
	int				rev_ub;
	int				max_height;
	int				n_seen;
	int				n_unset;
	int				vals[R01_MAX_CONSTR_SIZE];
	int				grid_constr_map[R01_MAX_GRID_SIZE][R01_CONSTRS_PER_VAL];
	int				constr_grid_map[R01_MAX_CONSTR_SIZE][R01_MAX_SIZE];
}				t_r01_constraints;

typedef struct s_r01_grid
{
	int					size;
	int					is_complete;
	int					is_invalid;
	int					min_unset_count;
	int					total_unset_count;
	t_r01_constraints	*constraints;
	char				grid_vals[R01_MAX_GRID_SIZE];
	short				valid_values[R01_MAX_GRID_SIZE];
}				t_r01_grid;

#endif