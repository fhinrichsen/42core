#include "push_swap.h"

void	is_sorted(t_stack *stack)
{
	t_node	*current;
	int		tmp;

	current = stack->a_top;
	tmp = current->index;
	while (current->next != stack->a_top)
	{
		if (tmp != (current->next->index) - 1)
			return ;
		current = current->next;
		tmp = current->index;
	}
	fprintf(stderr, "Is sorted\n");
	free_stack(stack, 0);
}

int	is_in_order(t_stack *stack)
{
	t_node	*current;

	current = head;
	while (current->next != head)
	{
		if(current->index != (current->next->index) + 1)

		current = current->next;
	}
	
}

void	sort_small_stack(t_stack *stack)
{
	
}