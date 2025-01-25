/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_puzzle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:53 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 15:03:32 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_PUZZLE_H
# define R01_PUZZLE_H
# define R01_CONSTR_SIZE 16
# define R01_GRID_SIZE 16

typedef struct s_r01_puzzle
{
	int		size;
	int		is_complete;
	int		is_invalid;
	int		constr_vals[R01_CONSTR_SIZE];
	int		grid_vals[R01_GRID_SIZE];
}				t_r01_puzzle;

#endif