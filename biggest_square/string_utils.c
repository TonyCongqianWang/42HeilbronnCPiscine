/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: towang <towang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:09:44 by towang            #+#    #+#             */
/*   Updated: 2025/02/05 15:22:12 by towang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libc.h>
#include "string_utils.h"

char	*realloc_str(char *str, ssize_t old_size, ssize_t new_size)
{
	char		*new_str;
	ssize_t		idx;

	if (old_size >= new_size || new_size <= 0)
		return (str);
	new_str = (char *)malloc(sizeof(char) * (new_size));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	idx = 0;
	while (idx < old_size)
	{
		new_str[idx] = str[idx];
		idx++;
	}
	if (old_size)
		free(str);
	return (new_str);
}
