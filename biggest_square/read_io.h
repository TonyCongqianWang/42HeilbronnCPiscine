/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:03:19 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 14:16:32 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_IO_H
# define READ_IO_H

char	*read_from_stdin(void);
char	*read_from_filepath(char *path);
char	*read_from_fd(int fd);
int		read_next_chunk(int fd, char *str, int old_size, int new_size);

#endif