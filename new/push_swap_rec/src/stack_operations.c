/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:34:32 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/11 18:53:40 by fhinrich         ###   ########.fr       */
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
	stack->b_top = NULL;
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
			write(2, "Error\n", 7);
			free_stack(stack, 20);
		}
		curent_pos++;
	}
	return (stack);
}

// 8lines too long
void	normalize_ints(t_stack *stack)
{
	int		i;
	int		min;
	t_node	*current;

	i = 1;
	current = stack->a_top;
	while (i <= (stack->a_size) + 1)
	{
		min = INT32_MAX;
		find_min(i, min, stack, current);
		i++;
	}
}

void	find_min(int new_value, int min, t_stack *stack, t_node	*current)
{
	int		j;

	j = stack->a_size;
	while (j >= 0)
	{
		if (current->value < min)
		{
			if (current->index > 0)
			{
				current = current->next;
				j--;
				continue ;
			}
			min = current->value;
		}
		current = current->next;
		j--;
	}
	while (j <= stack->a_size)
	{
		if (current->value == min)
			current->index = new_value;
		current = current->next;
		j++;
	}
}
