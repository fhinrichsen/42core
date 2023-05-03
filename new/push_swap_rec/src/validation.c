/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:20:05 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/03 10:14:39 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/// @brief Checks if an array of strings contains a non int. frees and exits.
/// @param arguments_s array of strings
/// @param created_at_runtime 1 if malloced at runtime.
void	valid_int(char **arguments_s, int created_at_runtime)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (arguments_s[i] != NULL)
	{
		temp = arguments_s[i];
		if (temp[j] == '-')
				j++;
		while (temp[j] != '\0')
		{
			if (!ft_isdigit(temp[j]))
			{
				if (created_at_runtime)
					validation_error(arguments_s);
				validation_error(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

void	unique_ints(int *start, int *end)
{
	int	*curent_pos;
	int	temp;
	int	offset;

	offset = 1;
	curent_pos = &start[offset];
	temp = *start;
	while (curent_pos <= end)
	{
		temp = start[(offset - 1)];
		while (curent_pos <= end)
		{
			if (*curent_pos == temp)
			{
				free(start);
				ft_error(0, 25);
			}
			curent_pos++;
		}
		offset++;
		curent_pos = &start[offset];
	}
}
