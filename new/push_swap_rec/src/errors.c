#include "push_swap.h"

void ft_error(t_stack *stack)
{
	if (stack == 0)
		ft_printf("Error\n");
		exit(1);
	free_stack(stack);
}

void free_stack(t_stack *stack)
{
	ft_printf("I should frre struct stack but I'm not implemented");
	stack = stack + 0;
	exit(1);
}

void validation_error(char **arguments_s)
{
	int i;

	i = 0;
	if (arguments_s == 0)
	{
		ft_printf("Error\n");
		exit(20);
	}
	while (arguments_s[i] != 0)
	{
		free(arguments_s[i]);
		i++;
	}
	ft_printf("Error\n");
	exit(21);
}