/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:58:23 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 01:04:32 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef unsigned long	t_map_dim;

typedef struct s_map_dims
{
	t_map_dim		width;
	t_map_dim		height;
}				t_map_dims;

typedef struct s_map
{
	t_map_dims		dims;
	char			empty_ch;
	char			obstacle_ch;
	char			full_ch;
	char			*values;
}				t_map;

typedef struct s_solver_state
{
	t_map_dims		dims;
	t_map_dim		total;
	t_map_dim		best_idx;
	t_map_dim		best_square;
	t_map_dim		*best_squares;
}				t_solver_state;

typedef struct s_idx_tripplet
{
	t_map_dim		idxs[3];
}				t_idx_tripplet;

void	free_map(t_map	*map);
void	free_sol_state(t_solver_state	*sol_state);

#endif