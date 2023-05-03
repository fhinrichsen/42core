/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prison_break.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:34:32 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/03 10:43:54 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack, int err_no)
{
	free_list(stack->a_top);
	free_list(stack->b_top);
	exit (err_no);
}

void free_list(t_node *head)
{
	t_node *current;
	t_node *next;
	
	current = head;
	next = NULL;
	if (head == NULL)
		return;
	 while (current != NULL) 
	 {
		next = current->next;
		free(current);
		current = next;
		if (current == head)
			break;
	 }
	
}