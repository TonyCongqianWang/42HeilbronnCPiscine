/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01_io.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:55:39 by towang            #+#    #+#             */
/*   Updated: 2025/01/25 15:52:13 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R01_IO_H
# define R01_IO_H

# include "r01_puzzle.h"

t_r01_puzzle	parse_input_str(char *str);
void			print_puzzle_grid(t_r01_puzzle grid);
void			print_error(void);

#endif