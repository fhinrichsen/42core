/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:33:26 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/02 19:50:23 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *stack, int err_no)
{
	if (stack == 0)
	{
		ft_printf("Error\n");
		exit (err_no);
	}
	free_stack(stack, err_no);
}


void	validation_error(char **arguments_s)
{
	int	i;

	i = 0;
	if (arguments_s == 0)
	{
		ft_printf("Error\n");
		exit (20);
	}
	while (arguments_s[i] != 0)
	{
		free(arguments_s[i]);
		i++;
	}
	ft_printf("Error\n");
	exit (21);
}
