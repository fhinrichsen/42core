/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:34:32 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/03 11:02:48 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_two_arguments(char *argv)
{
	int		count;
	char	**arguments_s;
	t_stack *stack;

	count = 0;
	arguments_s = ft_split(argv, ' ');
	if (arguments_s[0] == NULL)
	{
		free(arguments_s);
		exit(1);
	}
	valid_int(arguments_s, TRUE);
	while (arguments_s[count] != NULL)
		count++;
	if (count == 1)
		exit(0);
	stack = handle_input(arguments_s, count, TRUE);
	print_list(stack->a_top);
	free_stack(stack, 0);
}

void	read_n_arguments(char **arguments_s, int argc)
{
	t_stack *stack;

	valid_int(arguments_s, FALSE);
	stack = handle_input(arguments_s, argc, FALSE);
	print_list(stack->a_top);
	free_stack(stack, 0);
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
	fill_stack_a(stack, start, end);
	return (stack);
}
