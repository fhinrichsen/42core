/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:35:42 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/11 19:55:07 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		exit(1);
	argv++;
	if (argc == 2)
	{
		any_empty_s(argv);
		stack = read_two_arguments(*argv);
	}
	else
	{
		any_empty_s(argv);
		argc--;
		stack = read_n_arguments(argv, argc);
	}
	print_list(stack->a_top);
	// ft_push(&stack->b_top, ft_pop(&stack->a_top));
	ft_rotate(1, &stack->a_top);
	fprintf(stderr, "\n");
	print_list(stack->a_top);
	fprintf(stderr, "\n");
	// print_list(stack->b_top);
	free_stack(stack, 10);
	return (0);
}
