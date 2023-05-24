/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:51:18 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/24 21:30:53 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_node_value(t_node *my_node, int new_val)
{
	my_node->value = new_val;
}
/// @brief Allocates and initializes new node
/// @param value Value of node as INT32
/// @return pointer to new node

t_node	*new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->value = value;
	new_node->index = 0;
	return (new_node);
}

/// @brief Adds end note to circular double linked list
/// @param val Value of node as INT32
/// @param top Top of the stack
/// @param prev previous node
/// @return pointer to new node
t_node	*add_end_node(int val, t_node *top, t_node *prev)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = val;
	new_node->index = 0;
	new_node->prev = prev;
	new_node->next = top;
	new_node->prev->next = new_node;
	top->prev = new_node;
	return (new_node);
}
// void	print_list(t_node *head)
// {
// 	t_node	*current = head;
// 	if (head == NULL)
// 	{
// 		fprintf(stderr, "Empty\n");
// 		return ;
// 	}
// 	fprintf(stderr, "  Val: ");
// 	do {
// 		fprintf(stderr, "%d ", current->value);
// 		current = current->next;
// 	} while (current != head);
// }

void	lonely_number(t_stack *stack, int *end)
{
	free(end);
	free(stack->a_top);
	free(stack->b_top);
	exit(1000);
}
