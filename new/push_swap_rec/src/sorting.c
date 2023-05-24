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
	free_stack(stack, 0);
}

void	sort_small_stack(t_stack *stack)
{
	if (stack->a_size == 2)
	{
		ft_rotate(1, &stack->a_top);
		free_stack(stack, 0);
	}
	if (stack->a_size > 3)
	{
		sort_five(stack);
	}
	else
		sort_three(stack);
	free_stack(stack, 0);
}

void	sort_five(t_stack *stack)
{
	int	x;

	x = stack->a_size - 2;
	while (stack->a_size > 3)
		{
			if (stack->a_top->index < x)
				push_pop(stack, 'b');
			if(stack->a_size > 3)
				ft_rotate(1, &stack->a_top);
		}
		sort_three(stack);
		if (stack->b_top->index < stack->b_top->next->index)
			ft_rotate(11, &stack->b_top);
		push_pop(stack, 'a');
		push_pop(stack, 'a');
		free_stack(stack, 0);
}

static void	small_top(int t, int m, int b, t_stack *s)
{
	if (m < b)
	{
		if (t < b)
			ft_swap(&s->a_top, 'a');
		else
			ft_rotate(1, &s->a_top);
	}
	else
	{
		ft_swap(&s->a_top, 'a');
		ft_rotate(0, &s->a_top);
	}
}

void	sort_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;

	top = stack->a_top->index;
	mid = stack->a_top->next->index;
	bottom = stack->a_top->prev->index;
	if (top > mid)
	{
		small_top(top, mid, bottom, stack);
	}
	else if (top < mid)
	{
		if(top < bottom)
		{
			ft_swap(&stack->a_top, 'a');
			ft_rotate(1, &stack->a_top);
		}
		else
			ft_rotate(0, &stack->a_top);
	}

}