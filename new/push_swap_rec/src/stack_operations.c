/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:34:32 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/02 15:45:25 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *init_stack()
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

t_node *new_node(int value)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return(NULL);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->value = value;
	return (new_node);
}