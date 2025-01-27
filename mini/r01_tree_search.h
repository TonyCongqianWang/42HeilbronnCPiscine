/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_tree_search.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:25:38 by towang            #+#    #+#             */
/*   Updated: 2025/01/27 18:08:10 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_TREE_SEARCH_H
# define R01_TREE_SEARCH_H
# include "r01_structs.h"

t_r01_grid	r01_tree_search(t_r01_grid *grid, t_r01_constraints *constraints);
int			r01_get_min_available_coord(t_r01_grid *grid, int *x, int *y);

#endif
