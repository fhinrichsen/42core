/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:33:26 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/02 16:44:20 by fhinrich         ###   ########.fr       */
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

void	free_stack(t_stack *stack, int err_no)
{
	ft_printf("I should free struct stack but I'm not implemented\n");
	fprintf(stderr, "Adress top a: %p\n", stack->a_top);
	fprintf(stderr, "Adress top b: %p\n", stack->b_top);
	exit (err_no);
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
