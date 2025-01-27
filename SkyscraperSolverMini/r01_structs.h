/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:48:29 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 16:11:50 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_STRUCTS_H
# define R01_STRUCTS_H
# define R01_MAX_SIZE 9

typedef struct s_r01_constraints
{
	int				size;
	int				vals[R01_MAX_SIZE][4];
}				t_r01_constraints;

typedef struct s_r01_grid
{
	int				size;
	int				is_valid;
	int				unset_number;
	char			grid_vals[R01_MAX_SIZE][R01_MAX_SIZE];
	short			valid_values[R01_MAX_SIZE][R01_MAX_SIZE];
}				t_r01_grid;

#endif
