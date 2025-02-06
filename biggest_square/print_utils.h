/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:03:49 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/04 21:31:43 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UTILS_H
# define PRINT_UTILS_H

# include "structs.h"

void	ft_putstr(const char *str);
void	ft_putline(const char *str, unsigned long l);
void	print_map_error(void);
void	print_map(t_map map);

#endif