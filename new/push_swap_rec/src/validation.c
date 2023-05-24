/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:20:05 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/24 16:52:26 by fhinrich         ###   ########.fr       */
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
		if (temp[j] == '-' || temp[j] == '+')
				j++;
		while (temp[j] != '\0')
		{
			if (!ft_isdigit(temp[j]))
			{
				if (created_at_runtime)
					free_split_error(arguments_s);
				free_split_error(0);
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
				ft_printf("Error\n");
				exit(1);
			}
			curent_pos++;
		}
		offset++;
		curent_pos = &start[offset];
	}
}

void	any_empty_s(char **string_arr)
{
	int		i;
	int		len;
	char	*test;

	len = 0;
	i = 0;
	while (string_arr[i] != NULL)
	{
		len = ft_strlen(string_arr[i]);
		if (len == 0)
			ft_error(0, 1);
		test = string_arr[i];
		while (*test != '\0')
		{
			if (*test == ' ' || *test == '+'
				|| *test == '-')
				len--;
			test++;
		}
		if (len < 1)
			ft_error(0, 1);
		i++;
	}
}

/// @brief Takes array of strings, turns it to int, frees input
/// @param string_arr Array of Strings
/// @param created Created at runtime
/// @return On succes array of ints, on failure: exit, error to terminal;
int	*in_range(char **string_arr, int count, int created)
{
	int	*arguments_i;
	int	i;
	int	error;

	error = 0;
	arguments_i = malloc(sizeof(int) * count);
	if (!arguments_i)
		free_split_error(string_arr);
	i = 0;
	while (i < count)
	{
		arguments_i[i] = ft_atoll(string_arr[i], &error);
		if (error == TRUE)
		{
			free(arguments_i);
			if (created)
				free_split_error(string_arr);
			free_split_error(NULL);
		}
		i++;
	}
	if (created)
		free_split_win(string_arr);
	return (arguments_i);
}

/// @brief Takes string array
/// @param string_arr 
/// @return Returns number of elements
int	count_args(char **string_arr)
{
	int	i;

	i = 0;
	while (string_arr[i] != NULL)
	{
		i++;
	}
	return (i);
}
