/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:34:32 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/04 20:12:11 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_two_arguments(char *arguments)
{
	int		count;
	char	**arguments_s;
	int		*arguments_i;
	int		*end;

	count = 0;
	arguments_s = ft_split(arguments, ' ');
	count = count_args(arguments_s);
	if (!arguments_s)
		free_split_error(arguments_s);
	valid_int(arguments_s, TRUE);
	arguments_i = in_range(arguments_s, count, TRUE);
	end = &arguments_i[(count - 1)];
	unique_ints(arguments_i, end);
	fprintf(stderr, "All unique\n");
	free(arguments_i);
}

void	read_n_arguments(char **arguments, int argc)
{
	int	*arguments_i;
	int	*end;

	valid_int(arguments, FALSE);
	arguments_i = in_range(arguments, (argc), FALSE);
	end = &arguments_i[(argc - 1)];
	unique_ints(arguments_i, end);
	fprintf(stderr, "All unique\n");
	free(arguments_i);
}

t_stack	*build_stack(int *start, int *end)
{
	t_stack	*stack;
	int		n_elem;

	n_elem = end - start;
	stack = init_stack();
	if (!stack)
	{
		free(start);
		free_stack(stack, 30);
	}
	update_node_value(stack->a_top, *start);
	fill_stack_a(stack, start, end);
	return (stack);
}
