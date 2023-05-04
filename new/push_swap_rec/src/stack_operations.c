/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:34:32 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/04 20:03:59 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a_top = new_node(0);
	stack->b_top = new_node(0);
	stack->a_size = 0;
	stack->b_size = 0;
	return (stack);
}

t_stack	*fill_stack_a(t_stack *stack, int *start, int *end)
{
	int		*curent_pos;
	t_node	*temp_end;

	curent_pos = NULL;
	if (start != end)
		curent_pos = &start[1];
	else
	{
		free(start);
	}
	temp_end = stack->a_top;
	while (curent_pos <= end)
	{
	temp_end = add_end_node(*curent_pos, stack->a_top, temp_end);
		if (temp_end == NULL)
		{
			free(start);
			free_stack(stack, 20);
		}
		curent_pos++;
	}
	free(start);
	return (stack);
}
