/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:33:26 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/11 18:53:55 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *stack, int err_no)
{
	if (stack == 0)
	{
		write(2, "Error\n", 7);
		exit (err_no);
	}
	write(2, "Error\n", 7);
	free_stack(stack, err_no);
}

/// @brief Frees string array and prints error to terminal and exit.
/// @param arguments_s 
void	free_split_error(char **arguments_s)
{
	int	i;

	i = 0;
	if (arguments_s == NULL)
	{
		write(2, "Error\n", 7);
		exit (20);
	}
	while (arguments_s[i] != NULL)
	{
		free(arguments_s[i]);
		i++;
	}
	free(arguments_s);
	write(2, "Error\n", 7);
	exit (21);
}

/// @brief Frees string array
/// @param arguments_s 
void	free_split_win(char **arguments_s)
{
	int	i;

	i = 0;
	if (arguments_s == 0)
		return ;
	while (arguments_s[i] != 0)
	{
		free(arguments_s[i]);
		i++;
	}
	free(arguments_s);
}
