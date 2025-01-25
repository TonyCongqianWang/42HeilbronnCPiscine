/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_io.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:39 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 12:57:54 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_IO_H
# define R01_IO_H

# include "r01_grid.h"

int			is_input_str_format_valid(char *str);
t_r01_grid	parse_input_str(char *str);
void		print_grid_or_error(t_r01_grid grid);
void		print_error(void);

#endif