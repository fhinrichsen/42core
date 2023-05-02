/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:34:32 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/02 16:40:27 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_two_arguments(char *argv)
{
	int		count;
	char	**arguments_s;

	count = 0;
	arguments_s = ft_split(argv, ' ');
	if (arguments_s[0] == NULL)
		
	valid_int(arguments_s, TRUE);
	while (arguments_s[count] != NULL)
		count++;
	handle_input(arguments_s, count);
}

void	read_n_arguments(char **arguments_s, int argc)
{
	// int	*arguments_i;

	valid_int(arguments_s, FALSE);
	handle_input(arguments_s, argc);
	return ;
}

t_stack	*build_stack(int *start, int *end)
{
	t_stack	*stack;
	int	n_elem;

	n_elem = end - start;
	stack = init_stack();
	if (!stack /*|| TRUE*/) //test only
		free_stack(stack, 30);
	update_node_value(stack->a_top, *start);
	
	return (stack);
}
